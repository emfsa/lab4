#pragma once
#include "Validator.h"
#include "Table.h"
#include <string>
#include "executer.h"
class Bracket_checker : public Validator
{
    Executerr _logger;

public:
    explicit Bracket_checker(Table* table) : _logger(table) {}

    bool isNormal(const std::string& line) {
        int openCount = 0;
        for (char c : line) {
            if (c == '(') ++openCount;
            else if (c == ')') --openCount;
        }

        if (openCount < 0) {
            _logger.thRow(logs("001"));  // лишняя закрывающая
            return false;
        }
        if (openCount > 0) {
            _logger.thRow(logs("002"));  // не хватает закрывающих
            return false;
        }
        return true;
    }
};
#pragma once
#include "Validator.h"

class doubleSign :Validator
{
	Executerr logger;
public:
	doubleSign(Table* table) : logger(table) {}


    bool isNormal(const std::string& line) 
    { auto isOperator = [](char c) -> bool {
            return c == '+' || c == '-' || c == '*' || c == '/' || c == '=';
            };

        for (size_t i = 0; i < line.size(); ++i) {
            char current = line[i];

            
            if (!isOperator(current)) {
                continue;
            }

           
            if (i > 0) {
                char prev = line[i - 1];
              
                if (isOperator(prev)) {
                    logger.thRow(logs("101"));
                    return false;
                }
            }

            
            if (i + 1 < line.size()) {
                char next = line[i + 1];
                if (isOperator(next)) {
                    logger.thRow(logs("101"));
                    return false;
                }
            }
        }

        return true;
    }

	~doubleSign() {}

};


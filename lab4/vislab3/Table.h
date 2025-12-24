
#pragma once
#include <iostream>
#include <vector>
#include <string>

class Table {
private:
    std::vector<std::pair<std::string, std::string>> data;

public:
    Table() {
        //0 - bracket
    //1 - double sign
        AddRow("001", ") > (");
        AddRow("002", "( > )");
        AddRow("101", "double sign");
        AddRow("000", "invalid line");

    }
    void AddRow(const std::string& errorCode, const std::string& description) {
        data.emplace_back(errorCode, description);
    }

    std::string GetDescription(const std::string& errorCode) const {
        for (const auto& entry : data) {
            if (entry.first == errorCode) {
                return entry.second;
            }
        }
        return "Unknown error code: " + errorCode;
    }
};
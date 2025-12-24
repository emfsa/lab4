#pragma once
#include "stdr.h"
#include "ctime"
#include <sstream>
#include <iomanip>

class logs
{
public:
    std::string time, code, msg;


    explicit logs(const std::string& errCode) : code(errCode), msg("") {
        std::time_t t = std::time(nullptr);
        std::tm timeInfo{};
        localtime_s(&timeInfo, &t);
        std::ostringstream os;
        os << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
        time = os.str();
    }


    logs(const std::string& message, const std::string& errCode)
        : msg(message), code(errCode) {
        std::time_t t = std::time(nullptr);
        std::tm timeInfo{};
        localtime_s(&timeInfo, &t);
        std::ostringstream os;
        os << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
        time = os.str();
    }


    logs() = default;

    std::string ToString() const {
        return "[" + time + "] Code: " + code + " | Message: " + msg;
    }
};
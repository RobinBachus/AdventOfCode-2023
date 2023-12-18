#include "common.h"

#include <iostream>
#include <ostream>

std::vector<std::string> common::split(const std::string& str, const std::string& delimiter) {
    size_t pos_start = 0, pos_end;
    const size_t delimiter_len = delimiter.length();
    std::vector<std::string> res;

    while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
        std::string token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delimiter_len;
        res.push_back(token);
    }

    res.push_back(str.substr(pos_start));
    return res;
}

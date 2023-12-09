#pragma once

#ifndef FILE_MANAGER
#define FILE_MANAGER

#include <string>
#include <iostream>
#include <vector>

// Borrowed and adjusted from another project I'm working on
class file_manager
{
private:

public:
    [[nodiscard]] static std::vector<std::string> open_file(const std::string& path);
};

#endif
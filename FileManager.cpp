#include "FileManager.h"

#include <fstream>
#include <vector>
#include <filesystem>


std::vector<std::string> file_manager::open_file(const std::string& path)
{

	if (!std::filesystem::exists(path))
	{
		// TODO: Handle the case where the file doesn't exist
		std::cerr << "File does not exist";
		return {};
	}

	std::string line;
	std::vector<std::string> content;
	std::ifstream read_file(path);

	if (!read_file.is_open())
	{
		// TODO: Handle the case where the file couldn't be opened
		std::cerr << "File is already opened by another program";
		return {};
	}

	while (std::getline(read_file, line))
	{
		content.push_back(line);
	}

	read_file.close();
	return content;
}



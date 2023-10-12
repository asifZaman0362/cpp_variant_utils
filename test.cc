#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "src/result.hpp"

using namespace zifmann;
using std::filesystem::path, std::string;

Result<int, string> fallible_function(const path& filepath) {
    try {
        std::ifstream file(filepath);
        string buffer;
        file >> buffer;
        return Ok<int, string>(std::stoi(buffer));
    } catch (std::exception exception) {
        return Err<int, string>(exception.what());
    }
}

int main() {
    if OK (value, fallible_function("file.txt")) {
        std::cout << "integer in file: " << value << "\n";
    } else {
        std::cout << "couldnt parse integer!\n";
    }
}


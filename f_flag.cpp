//
// Created by Mikołaj on 08.06.2021.
//

#include <iostream>
#include <fstream>
#include "f_flag.hpp"
#include "my_exception.hpp"

auto should_call_f_exception = false;

auto read_file_by_line(const std::vector<std::string> &arguments) -> std::vector<std::string> {
    std::ifstream file(arguments[1]);

    if (!file.is_open()) {
        should_call_f_exception = true;
//        exit(EXIT_FAILURE);
    }

    auto file_content_line_by_line = std::vector<std::string>();
    std::string line;
    while (std::getline(file, line)) {
        file_content_line_by_line.push_back(line);
    }

    return file_content_line_by_line;
}

auto read_file_by_word(const std::vector<std::string> &arguments) -> std::vector<std::string> {
    std::ifstream file(arguments[1]);

    if (!file.is_open()) {
        should_call_f_exception = true;
//        exit(EXIT_FAILURE);
    }

    auto file_content_word_by_word = std::vector<std::string>();
    for (auto word = std::string(); file >> word;) {
        file_content_word_by_word.push_back(word);
    }

    return file_content_word_by_word;
}

auto read_file_and_insert_output_into_two_vectors(const std::vector<std::string> &arguments,
                                                  std::vector<std::string> &file_content_line_by_line,
                                                  std::vector<std::string> &file_content_word_by_word) -> void {
    if (arguments[0] == "-f" || arguments[0] == "--file") {
        file_content_line_by_line = read_file_by_line(arguments);
        file_content_word_by_word = read_file_by_word(arguments);
    }

    if (should_call_f_exception) {
        std::cout << "Error. Wrong Path." << "\n";
        throw my_exception("-f flag problem");
    }
}
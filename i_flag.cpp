//
// Created by Mikołaj on 11.06.2021.
//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "i_flag.hpp"
#include "my_exception.hpp"

auto should_call_i_exception = false;
namespace i_flag_functions {
    auto get_input_file_path(const std::vector<std::string> &arguments) -> std::string {
        return arguments[1];
    }

    auto get_input_file_arguments(const std::vector<std::string> &arguments) -> std::vector<std::string> {
        std::ifstream input_file(get_input_file_path(arguments));
        if (input_file.fail()) {
            std::cout << "That's not a valid input file path after -i flag or file does not exist!\n";
            should_call_i_exception = true;
//        exit(EXIT_FAILURE);

            if (should_call_i_exception) {
                throw my_exception("-i flag problem");
            }

        }
        auto input_file_arguments_word_by_word = std::vector<std::string>();

        for (auto word = std::string(); input_file >> word;) {
            input_file_arguments_word_by_word.push_back(word);
        }

        return input_file_arguments_word_by_word;
    }
}

i::i(const std::vector<std::string> &arguments)
        : arguments(arguments), flag_name(std::string("-i")), flag_alias(std::string("--input")) {}

void i::do_stuff() const {
    //... does absolutely nothing
}

const std::string &i::get_flag_name() const {
    return flag_name;
}

const std::string &i::get_flag_alias() const {
    return flag_alias;
}


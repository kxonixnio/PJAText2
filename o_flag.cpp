//
// Created by Mikołaj on 10.06.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ostream>
#include <map>
#include <memory>
#include "o_flag.hpp"

bool should_output_be_send_to_file = false;
std::string output_file_path;

namespace o_flag_functions {

    auto get_if_send_output_to_file() -> bool {
        return should_output_be_send_to_file;
    }

    auto get_output_file_path() -> std::string {
        return output_file_path;
    }

    auto find_output_file_path(const std::vector<std::string> &arguments) -> std::string {
        auto output_file = std::find_if(arguments.begin(), arguments.end(), [](const auto &arg) {
            return arg == "-o" || arg == "--output";
        }) + 1; //bo chce to co po -o
        return *output_file;
    }

    auto send_output_to_file(const unsigned long long int value_to_send) -> void {
        auto output_file = std::ofstream(get_output_file_path(), std::ios::app);
        output_file << value_to_send << '\n';
    }

    auto send_output_to_file(const std::string &value_to_send) -> void {
        auto output_file = std::ofstream(get_output_file_path(), std::ios::app);
        output_file << value_to_send << '\n';
    }

    auto clear_output_file() -> void {
        auto file = std::ofstream(get_output_file_path());
    }

    auto decide_whether_output_should_be_send_to_file(const std::vector<std::string> &arguments,
                                                      std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void {
        if (std::find_if(arguments.begin(), arguments.end(), [](const auto &arg) {
            return arg == "-o" || arg == "--output";
        }) != arguments.end()) {
            map["-o"]->do_stuff();
        }
    }
}

o::o(const std::vector<std::string> &arguments)
        : arguments(arguments), flag_name(std::string("-o")), flag_alias(std::string("--output")) {}

void o::do_stuff() const {
    should_output_be_send_to_file = true;
    output_file_path = o_flag_functions::find_output_file_path(arguments);
    o_flag_functions::clear_output_file();
}

const std::string &o::get_flag_name() const {
    return flag_name;
}

const std::string &o::get_flag_alias() const {
    return flag_alias;
}
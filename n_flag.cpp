//
// Created by Mikołaj on 08.06.2021.
//
#include <string>
#include <iostream>
#include <vector>

#include "n_flag.hpp"
#include "o_flag.hpp"

auto print_amount_of_lines(const std::vector<std::string> &file_content_line_by_line) -> void {
    if (o_flag_functions::get_if_send_output_to_file()) {
        o_flag_functions::send_output_to_file(file_content_line_by_line.size());
    } else {
        std::cout << file_content_line_by_line.size() << "\n";
    }
}

n::n(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-n")), flag_alias(std::string("--newlines")) {}

void n::do_stuff() const {
    print_amount_of_lines(file_content);
}

const std::string &n::get_flag_name() const {
    return flag_name;
}

const std::string &n::get_flag_alias() const {
    return flag_alias;
}


//
// Created by Mikołaj on 08.06.2021.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "d_flag.hpp"
#include "o_flag.hpp"

auto get_vector_of_chars_transformed_from_vector_of_string(
        const std::vector<std::string> &file_content_line_by_line) -> std::vector<char> {
    //vector of strings -> one string
    auto file_content_as_one_string = std::accumulate(file_content_line_by_line.begin(),
                                                      file_content_line_by_line.end(), std::string{});

    //one string -> vector of chars
    auto file_content_as_chars = std::vector<char>(
            file_content_as_one_string.begin(),
            file_content_as_one_string.end()
    );

    return file_content_as_chars;
}

auto get_amount_of_digits(const std::vector<char> &file_content_as_chars) -> int {
    //count every digit in vector of chars
    auto digit_counter = std::count_if(
            file_content_as_chars.begin(),
            file_content_as_chars.end(),
            [](const char ch) {
                return isdigit(ch);
            });

    return digit_counter;
}

auto print_amount_of_digits(const std::vector<std::string> &file_content_line_by_line) -> void {

    auto file_content_as_chars = get_vector_of_chars_transformed_from_vector_of_string(file_content_line_by_line);
    auto amount_of_digits = get_amount_of_digits(file_content_as_chars);

    if (o_flag_functions::get_if_send_output_to_file()) {
        o_flag_functions::send_output_to_file(amount_of_digits);
    } else {
        std::cout << amount_of_digits << "\n";
    }
}

d::d(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-d")), flag_alias(std::string("--digits")) {}

void d::do_stuff() const {
    print_amount_of_digits(file_content);
}

const std::string &d::get_flag_name() const {
    return flag_name;
}

const std::string &d::get_flag_alias() const {
    return flag_alias;
}
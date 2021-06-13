//
// Created by Mikołaj on 08.06.2021.
//
#include <string>
#include <iostream>
#include <vector>

#include "c_flag.hpp"
#include "o_flag.hpp"

auto
get_sum_of_characters_with_spaces_from_each_word(const std::vector<std::string> &file_content_line_by_line) -> int {
    auto amount_of_characters_with_spaces = 0;

    for (const auto &line : file_content_line_by_line) {
        amount_of_characters_with_spaces += line.length();
    }

    return amount_of_characters_with_spaces;
}

auto print_amount_of_characters_with_spaces(const std::vector<std::string> &file_content_line_by_line) -> void {

    auto amount_of_characters_with_spaces = get_sum_of_characters_with_spaces_from_each_word(file_content_line_by_line);

    if (o_flag_functions::get_if_send_output_to_file()) {
        o_flag_functions::send_output_to_file(amount_of_characters_with_spaces);
    } else {
        std::cout << amount_of_characters_with_spaces << "\n";
    }
}

auto
get_sum_of_characters_without_spaces_from_each_word(const std::vector<std::string> &file_content_word_by_word) -> int {
    auto char_counter_no_spaces = 0;
    for (const auto &word : file_content_word_by_word) {
        char_counter_no_spaces += word.size();
    }

    return char_counter_no_spaces;
}

auto print_amount_of_characters_without_spaces(const std::vector<std::string> &file_content_word_by_word) -> void {

    auto amount_of_characters_without_spaces = get_sum_of_characters_without_spaces_from_each_word(
            file_content_word_by_word);

    if (o_flag_functions::get_if_send_output_to_file()) {
        o_flag_functions::send_output_to_file(amount_of_characters_without_spaces);
    } else {
        std::cout << amount_of_characters_without_spaces << "\n";
    }
}

c::c(const std::vector<std::string> &content_word_by_word, const std::vector<std::string> &content_line_by_line)
        : file_content_word_by_word(content_word_by_word), file_content_line_by_line(content_line_by_line),
          flag_name(std::string("-c")), flag_alias(std::string("--chars")) {}

void c::do_stuff() const {
//    print_amount_of_characters_without_spaces(file_content_word_by_word);
    print_amount_of_characters_with_spaces(file_content_line_by_line);
}

const std::string &c::get_flag_name() const {
    return flag_name;
}

const std::string &c::get_flag_alias() const {
    return flag_alias;
}
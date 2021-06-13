//
// Created by Mikołaj on 08.06.2021.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>

#include "dd_flag.hpp"
#include "o_flag.hpp"

auto get_amount_of_integers(const std::vector<std::string> &file_content_word_by_word) -> int {
    auto counter_of_ints = std::count_if(
            file_content_word_by_word.begin(), file_content_word_by_word.end(),
            [](const std::string &word) {
                return std::regex_match(word, std::regex("[0-9]+"));
            }
    );

    return counter_of_ints;
}

auto get_amount_of_floating_point_numbers(const std::vector<std::string> &file_content_word_by_word) -> int {
    auto counter_of_doubles = std::count_if(
            file_content_word_by_word.begin(), file_content_word_by_word.end(),
            [](const std::string &word) {
                return std::regex_match(word, std::regex("[0-9]+\\.[0-9]+"));
            }
    );

    return counter_of_doubles;
}

auto print_amount_of_numbers(const std::vector<std::string> &file_content_word_by_word) -> void {

    auto amount_of_ints = get_amount_of_integers(file_content_word_by_word);
    auto counter_of_doubles = get_amount_of_floating_point_numbers(file_content_word_by_word);

    auto amount_of_matches = amount_of_ints + counter_of_doubles;

    if (o_flag_functions::get_if_send_output_to_file()) {
        o_flag_functions::send_output_to_file(amount_of_matches);
    } else {
        std::cout << amount_of_matches << "\n";
    }
}


dd::dd(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-dd")), flag_alias(std::string("--numbers")) {}

void dd::do_stuff() const {
    print_amount_of_numbers(file_content);
}

const std::string &dd::get_flag_name() const {
    return flag_name;
}

const std::string &dd::get_flag_alias() const {
    return flag_alias;
}
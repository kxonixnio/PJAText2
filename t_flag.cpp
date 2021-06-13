//
// Created by Mikołaj on 11.06.2021.
//

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include "t_flag.hpp"
#include "o_flag.hpp"

auto get_unique_chars_from_file_content(const std::vector<std::string> &file_content_word_by_word) -> std::set<char> {
    auto unique_letters_in_file_content = std::set<char>();
    for (const auto &word : file_content_word_by_word) {
        for (const auto &letter : word) {
            unique_letters_in_file_content.insert(letter);
        }
    }
    return unique_letters_in_file_content;
}

auto decide_if_he_is_here(const std::set<char> &letters_in_file_content) -> bool {
    auto is_he_here = true;
    for (const auto &letter : std::string("Tomaszew")) {
        if (std::find(letters_in_file_content.begin(), letters_in_file_content.end(), letter) ==
            letters_in_file_content.end()) {
            is_he_here = false;
        }
    }
    return is_he_here;
}

auto print_is_tomaszew_hiding_among_us(const std::vector<std::string> &file_content_word_by_word) -> void {

    auto letters_in_file_content = get_unique_chars_from_file_content(file_content_word_by_word);
    auto is_he_here = decide_if_he_is_here(letters_in_file_content);

    if (is_he_here) {
        if (o_flag_functions::get_if_send_output_to_file()) {
            o_flag_functions::send_output_to_file("Tomaszew is among us");
        } else {
            std::cout << "Tomaszew is among us\n";
        }
    } else {
        if (o_flag_functions::get_if_send_output_to_file()) {
            o_flag_functions::send_output_to_file("Tomaszew is not among us");
        } else {
            std::cout << "Tomaszew is not among us\n";
        }
    }
}

t::t(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-t")), flag_alias(std::string("--tomaszew")) {}

void t::do_stuff() const {
    print_is_tomaszew_hiding_among_us(file_content);
}

const std::string &t::get_flag_name() const {
    return flag_name;
}

const std::string &t::get_flag_alias() const {
    return flag_alias;
}
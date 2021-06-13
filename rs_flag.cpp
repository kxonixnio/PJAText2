//
// Created by Mikołaj on 08.06.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "rs_flag.hpp"
#include "l_flag.hpp"
#include "o_flag.hpp"

auto print_words_inversely_sorted_alphabetically(
        std::vector<std::string> file_content_word_by_word) -> void {    //kopia jest potrzebna, bo nie chce zmieniać oryginału

    std::sort(file_content_word_by_word.begin(), file_content_word_by_word.end(),
              [](const auto &left_word, const auto &right_word) {
                  return left_word > right_word;
              });

    for (const auto &word : file_content_word_by_word) {
        if (o_flag_functions::get_if_send_output_to_file()) {
            o_flag_functions::send_output_to_file(word);
        } else {
            std::cout << word << "\n";
        }
    }
}

auto print_words_inversely_sorted_by_length(std::vector<std::string> file_content_word_by_word) -> void {

    std::sort(file_content_word_by_word.begin(), file_content_word_by_word.end(),
              [](const auto &left_word, const auto &right_word) {
                  return left_word.length() > right_word.length();
              });

    for (const auto &word : file_content_word_by_word) {
        if (o_flag_functions::get_if_send_output_to_file()) {
            o_flag_functions::send_output_to_file(word);
        } else {
            std::cout << word << "\n";
        }
    }
    turn_off_length_s_rs_functionality();
}

rs::rs(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-rs")), flag_alias(std::string("--reverse-sorted")) {}

void rs::do_stuff() const {
    if (!get_is_s_or_rs_modified()) {
        print_words_inversely_sorted_alphabetically(file_content);
    } else {
        print_words_inversely_sorted_by_length(file_content);
    }
}

const std::string &rs::get_flag_name() const {
    return flag_name;
}

const std::string &rs::get_flag_alias() const {
    return flag_alias;
}
//
// Created by Mikołaj on 08.06.2021.
//

#include <iostream>
#include <vector>
#include "w_flag.hpp"
#include "o_flag.hpp"

auto print_amount_of_words(const std::vector<std::string> &file_content_word_by_word) -> void {

    if (o_flag_functions::get_if_send_output_to_file()) {
        o_flag_functions::send_output_to_file(file_content_word_by_word.size());
    } else {
        std::cout << file_content_word_by_word.size() << "\n";
    }

}

w::w(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-w")), flag_alias(std::string("--words")) {}

void w::do_stuff() const {
    print_amount_of_words(file_content);
}

const std::string &w::get_flag_name() const {
    return flag_name;
}

const std::string &w::get_flag_alias() const {
    return flag_alias;
}
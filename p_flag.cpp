//
// Created by Mikołaj on 10.06.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "p_flag.hpp"
#include "o_flag.hpp"

auto extract_words_after_p_flag(std::vector<std::string> &arguments) -> void {
    auto flag_or_alias = std::find(arguments.begin(), arguments.end(), "-p");
    if (flag_or_alias == arguments.end()) {
        flag_or_alias = std::find(arguments.begin(), arguments.end(), "--palindromes");
    }

    arguments.erase(
            arguments.begin(), std::find(arguments.begin(), arguments.end(), *flag_or_alias) + 1
    );

}

auto is_palindrome(const std::string &word) -> bool {
    return word == std::string(word.rbegin(), word.rend());
}

auto does_palindrome_exist_in_file(const std::vector<std::string> &file_content_word_by_word,
                                   const std::string &palindrome) -> bool {
    return std::find(file_content_word_by_word.begin(), file_content_word_by_word.end(), palindrome) !=
           file_content_word_by_word.end();
}

auto find_palindromes_in_two_vectors(const std::vector<std::string> &file_content_word_by_word,
                                     const std::vector<std::string> &arguments) -> std::set<std::string> {
    auto unique_palindromes = std::set<std::string>();

    for (const auto &arg : arguments) {
        if (is_palindrome(arg)) {
            if (does_palindrome_exist_in_file(file_content_word_by_word, arg)) {
                unique_palindromes.insert(arg);
            }
        }
    }

    return unique_palindromes;
}

auto
find_palindromes(const std::vector<std::string> &file_content_word_by_word,
                 std::vector<std::string> arguments) -> void {

    extract_words_after_p_flag(arguments);
    auto unique_anagrams = find_palindromes_in_two_vectors(file_content_word_by_word, arguments);

    for (const auto &arg : unique_anagrams) {
        if (o_flag_functions::get_if_send_output_to_file()) {
            o_flag_functions::send_output_to_file(arg);
        } else {
            std::cout << arg << "\n";
        }
    }
}

p::p(const std::vector<std::string> &content, const std::vector<std::string> &arguments)
        : file_content(content), flag_name(std::string("-p")), flag_alias(std::string("--palindromes")),
          arguments(arguments) {}

void p::do_stuff() const {
    find_palindromes(file_content, arguments);
}

const std::string &p::get_flag_name() const {
    return flag_name;
}

const std::string &p::get_flag_alias() const {
    return flag_alias;
}
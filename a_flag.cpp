//
// Created by Mikołaj on 09.06.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory>
#include "a_flag.hpp"
#include "o_flag.hpp"

auto extract_words_after_a_flag(std::vector<std::string> &arguments) -> void {

    auto flag_or_alias = std::find(arguments.begin(), arguments.end(), "-a");//to mi się nie podoba, wpisane z palca
    if (flag_or_alias == arguments.end()) {
        flag_or_alias = std::find(arguments.begin(), arguments.end(), "--anagrams"); //tak samo jak to
    }

    arguments.erase(
            arguments.begin(), std::find(arguments.begin(), arguments.end(), *flag_or_alias) + 1
    );

}

auto find_anagrams_in_two_vectors(const std::vector<std::string> &file_content_word_by_word,
                                  const std::vector<std::string> &arguments) -> std::set<std::string> {
    auto unique_anagrams = std::set<std::string>();

    for (const auto &arg : arguments) {
        auto arg_copy = arg;

        for (const auto &word : file_content_word_by_word) {
            auto word_copy = word;

            if (arg.length() == word.length()) {
                std::sort(arg_copy.begin(), arg_copy.end());
                std::sort(word_copy.begin(), word_copy.end());

                if (arg_copy == word_copy) {
                    unique_anagrams.insert(word);
                }
            }
        }
    }
    return unique_anagrams;
}

auto
print_anagrams_of_words_from_file_typed_after_a_flag(const std::vector<std::string> &file_content_word_by_word,
                                                     std::vector<std::string> arguments) -> void {

    extract_words_after_a_flag(arguments);
    auto unique_anagrams = find_anagrams_in_two_vectors(file_content_word_by_word, arguments);

    for (const auto &arg : unique_anagrams) {
        if (o_flag_functions::get_if_send_output_to_file()) {
            o_flag_functions::send_output_to_file(arg);
        } else {
            std::cout << arg << "\n";
        }
    }
}

a::a(const std::vector<std::string> &content, const std::vector<std::string> &arguments)
        : file_content(content), flag_name(std::string("-a")), flag_alias(std::string("--anagrams")),
          arguments(arguments) {}

void a::do_stuff() const {
    print_anagrams_of_words_from_file_typed_after_a_flag(file_content, arguments);
}

const std::string &a::get_flag_name() const {
    return flag_name;
}

const std::string &a::get_flag_alias() const {
    return flag_alias;
}

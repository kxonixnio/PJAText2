//
// Created by Mikołaj on 31.05.2021.
//

#ifndef PJATEXT2_C_FLAG_HPP
#define PJATEXT2_C_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Sums up and returns amount of characters (space is considered as a character)
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @return amount of characters (spaces included)
 */
auto get_sum_of_characters_with_spaces_from_each_word(const std::vector<std::string> &file_content_line_by_line) -> int;

/**
 * Prints amount of chars (spaces included!) read previously from a file line by line
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_amount_of_characters_with_spaces(const std::vector<std::string> &file_content_line_by_line) -> void;

/**
 * Sums up and returns amount of characters (space is not considered as a character)
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @return amount of characters (spaces not included)
 */
auto
get_sum_of_characters_without_spaces_from_each_word(const std::vector<std::string> &file_content_word_by_word) -> int;

/**
 * Prints amount of chars (no spaces!) read previously from a file word by word
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_amount_of_characters_without_spaces(const std::vector<std::string> &file_content_word_by_word) -> void;

struct c : abstract_flag {
private:
    std::vector<std::string> file_content_word_by_word;
    std::vector<std::string> file_content_line_by_line;
    std::string flag_name;
    std::string flag_alias;

public:
    c(const std::vector<std::string> &content_word_by_word, const std::vector<std::string> &content_line_by_line);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_C_FLAG_HPP

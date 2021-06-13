//
// Created by Mikołaj on 13.05.2021.
//

#ifndef PJATEXT2_DD_FLAG_HPP
#define PJATEXT2_DD_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Sums up and returns amount of integers in file.
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @return amount of integers
 */
auto get_amount_of_integers(const std::vector<std::string> &file_content_word_by_word) -> int;

/**
 * Sums up and returns amount of floating point numbers in file.
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @return amount of floating point numbers
 */
auto get_amount_of_floating_point_numbers(const std::vector<std::string> &file_content_word_by_word) -> int;

/**
 * Prints amount of numbers read previously from a file word by word
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_amount_of_numbers(const std::vector<std::string> &file_content_word_by_word) -> void;

struct dd : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    dd(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_DD_FLAG_HPP

//
// Created by Mikołaj on 13.05.2021.
//

#ifndef PJATEXT2_D_FLAG_HPP
#define PJATEXT2_D_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Returns vector of chars made from vector of strings
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * @return vector filled with content from file letter by letter
 */
auto get_vector_of_chars_transformed_from_vector_of_string(
        const std::vector<std::string> &file_content_line_by_line) -> std::vector<char>;

/**
 * Counts and returns amount of digits in provided vector of chars
 * @param file_content_as_chars - std::vector<char>
 * @return amount of digits
 */
auto get_amount_of_digits(const std::vector<char> &file_content_as_chars) -> int;

/**
 * Prints amount of digits read previously from a file line by line
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_amount_of_digits(const std::vector<std::string> &file_content_line_by_line) -> void;

struct d : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    d(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_D_FLAG_HPP

//
// Created by Mikołaj on 11.06.2021.
//

#ifndef PJATEXT2_T_FLAG_HPP
#define PJATEXT2_T_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Returns container including unique letters from file content
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @return std::set<char> with unique letters from each word in file content
 */
auto get_unique_chars_from_file_content(const std::vector<std::string> &file_content_word_by_word) -> std::set<char>;

/**
 * Depending if there's each of "tomaszew" letters is std::set, function returns appropriate value.
 * ("Tomaszew" letters -> 'T', 'o', 'm', 'a', 's', 'z', 'e', 'w').
 * @param letters_in_file_content - container including unique letters from file content.
 * @return true/false - depending if there's each of "tomaszew" letters.
 */
auto decide_if_he_is_here(const std::set<char> &letters_in_file_content) -> bool;

/**
 * Prints whether Java Master ("Tomaszew") can be made from all the letters from file content
 * @param file_content_word_by_word
 */
auto print_is_tomaszew_hiding_among_us(const std::vector<std::string> &file_content_word_by_word) -> void;

struct t : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    t(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_T_FLAG_HPP

//
// Created by Mikołaj on 08.06.2021.
//

#ifndef PJATEXT2_S_FLAG_HPP
#define PJATEXT2_S_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Prints all words sorted alphabetically read previously from a file word by word
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_words_sorted_alphabetically(std::vector<std::string> file_content_word_by_word) -> void;

/**
 * Prints all words sorted by length read previously from a file word by word
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_words_sorted_by_length(std::vector<std::string> file_content_word_by_word) -> void;

struct s : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    s(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_S_FLAG_HPP

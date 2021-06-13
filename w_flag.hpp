//
// Created by Mikołaj on 31.05.2021.
//

#ifndef PJATEXT2_W_FLAG_HPP
#define PJATEXT2_W_FLAG_HPP

#include "abstract_flag.hpp"

/**
 *Prints amount of words read previously from a file word by word
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_amount_of_words(const std::vector<std::string> &file_content_word_by_word) -> void;

struct w : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    w(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_W_FLAG_HPP

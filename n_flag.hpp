//
// Created by Mikołaj on 13.05.2021.
//

#ifndef PJATEXT2_N_FLAG_HPP
#define PJATEXT2_N_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Prints the amount of lines read previously from a file line by line
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
auto print_amount_of_lines(const std::vector<std::string> &file_content_line_by_line) -> void;

struct n : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    n(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_N_FLAG_HPP

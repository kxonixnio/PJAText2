//
// Created by Mikołaj on 09.06.2021.
//

#ifndef PJATEXT2_L_FLAG_HPP
#define PJATEXT2_L_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Makes next -s or -rs flag change their behaviour.
 * -s/-rs will sort words not alphabetically, but by length.
 */
auto turn_on_length_s_rs_functionality() -> void;

/**
 * Makes next -s or -rs flag change back to their standard behaviour.
 * -s/-rs will sort alphabetically again
 */
auto turn_off_length_s_rs_functionality() -> void;

/**
 * @return current status whether next -s or -rs flag should be modified
 */
auto get_is_s_or_rs_modified() -> bool;

struct l : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;

public:
    l(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_L_FLAG_HPP

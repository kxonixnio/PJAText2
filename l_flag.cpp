//
// Created by Mikołaj on 09.06.2021.
//

#include <iostream>
#include <vector>
#include "l_flag.hpp"


bool is_s_or_rs_modified = false;

auto turn_on_length_s_rs_functionality() -> void {
    is_s_or_rs_modified = true;
}

auto turn_off_length_s_rs_functionality() -> void {
    is_s_or_rs_modified = false;
}

auto get_is_s_or_rs_modified() -> bool {
    return is_s_or_rs_modified;
}


l::l(const std::vector<std::string> &content)
        : file_content(content), flag_name(std::string("-l")), flag_alias(std::string("--by-length")) {}

void l::do_stuff() const {
    turn_on_length_s_rs_functionality();
}

const std::string &l::get_flag_name() const {
    return flag_name;
}

const std::string &l::get_flag_alias() const {
    return flag_alias;
}
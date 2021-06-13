//
// Created by Mikołaj on 11.06.2021.
//

#ifndef PJATEXT2_I_FLAG_HPP
#define PJATEXT2_I_FLAG_HPP

#include "abstract_flag.hpp"

namespace i_flag_functions {
/**
 * Gets input file path
 * @param arguments - user input
 * @return - input file path
 */
    auto get_input_file_path(const std::vector<std::string> &arguments) -> std::string;

/**
 * Reads arguments from input file
 * @param arguments - user input
 * @return - vector which contains arguments from input file
 */
    auto get_input_file_arguments(const std::vector<std::string> &arguments) -> std::vector<std::string>;
}
struct i : abstract_flag {
private:
    std::vector<std::string> arguments;
    std::string flag_name;
    std::string flag_alias;

public:
    i(const std::vector<std::string> &content);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_I_FLAG_HPP

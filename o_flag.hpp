//
// Created by Mikołaj on 10.06.2021.
//

#ifndef PJATEXT2_O_FLAG_HPP
#define PJATEXT2_O_FLAG_HPP

#include "abstract_flag.hpp"
#include <map>
#include <memory>

namespace o_flag_functions {

/**
 * @return - true or false depending on whether the output should be sent to the file or not
 */
    auto get_if_send_output_to_file() -> bool;

/**
 * @return name of the file, where output should be send
 */
    auto get_output_file_path() -> std::string;

/**
 * Finds name of the file, where output should be send
 * @param arguments - std::vector<std::string> of provided arguments by user.
 * @return name of the file, where output should be send
 */
    auto find_output_file_path(const std::vector<std::string> &arguments) -> std::string;

/**
 * Sends numbers to the file
 * @param value_to_send - number to be send
 */
    auto send_output_to_file(unsigned long long int value_to_send) -> void;

/**
 * Sends string to the file
 * @param value_to_send  - string to be send
 */
    auto send_output_to_file(const std::string &value_to_send) -> void;

/**
 * Clears file before sending output there
 */
    auto clear_output_file() -> void;

/**
 * Sends signal whether output should be send to file
 * @param arguments - std::vector<std::string> of provided arguments by user.
 * @param map - map of valid flags
 */
    auto decide_whether_output_should_be_send_to_file(const std::vector<std::string> &arguments,
                                                      std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void;
}
struct o : abstract_flag {
private:
    std::vector<std::string> arguments;
    std::string flag_name;
    std::string flag_alias;

public:
    o(const std::vector<std::string> &arguments);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_O_FLAG_HPP

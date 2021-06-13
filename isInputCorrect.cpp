//
// Created by Mikołaj on 08.06.2021.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <set>

#include "isInputCorrect.hpp"
#include "my_exception.hpp"
#include "o_flag.hpp"

auto should_exception_be_called = false;

namespace input_correctness {

    auto replace_given_flag_alias_with_given_flag_name(std::vector<std::string> &arguments, const std::string &alias,
                                                       const std::string &flag) -> void {
        std::replace_if(arguments.begin(), arguments.end(),
                        [alias, flag](const auto &flag_or_alias) {
                            return flag_or_alias == alias;
                        }, flag);
    }

    auto
    is_there_any_given_as_an_argument_flag(const std::vector<std::string> &arguments, const std::string &flag) -> bool {
        if (std::find(arguments.begin(), arguments.end(), flag) != arguments.end()) {
            return true;
        } else {
            return false;
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto is_f_flag_meeting_all_the_requirements(std::vector<std::string> arguments) -> void {
        if (!arguments.empty()) {

            replace_given_flag_alias_with_given_flag_name(arguments, "--file", "-f");
            replace_given_flag_alias_with_given_flag_name(arguments, "--input", "-i");

            auto occurence = std::count_if(
                    arguments.begin(), arguments.end(),
                    [](const auto &argument) {
                        return argument == "-f";
                    }
            );

            if (!is_there_any_given_as_an_argument_flag(arguments, "-i")) {
                if (occurence == 0) {
                    std::cout << "There's no -f flag!";
                    should_exception_be_called = true;
//                    exit(EXIT_FAILURE);
                }
            }
            if (occurence == 1) {
                if (arguments[0] != "-f") {
                    std::cout << "-f must be the first flag!";
                    should_exception_be_called = true;
//                    exit(EXIT_FAILURE);
                }
            }
            if (occurence > 1) {
                std::cout << "There's more than one -f flag!";
                should_exception_be_called = true;
//                exit(EXIT_FAILURE);
            }
        }

        if (should_exception_be_called) {
            throw my_exception("-f flag problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto check_if_there_is_file_path_after_o_flag(const std::vector<std::string> &arguments) -> void {
        auto file_path_iterator = std::find_if(
                arguments.begin(), arguments.end(),
                [](const auto &arg) {
                    return arg == "-o" || arg == "--output";
                }
        ) + 1;  //bierzemy pod uwagę element zaraz za -o

        if (*file_path_iterator->begin() == '-') {
            std::cout << "Flag/alias directly after -o flag is forbidden! There must be a file path!\n";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }
    }

    auto check_if_o_is_not_a_last_input(std::vector<std::string> arguments) -> void {
        replace_given_flag_alias_with_given_flag_name(arguments, "--output", "-o");
        if (arguments.back() == "-o") {
            std::cout << "-o is the last flag without file path directly after!";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }
    }

    auto is_o_flag_meeting_all_the_requirements(const std::vector<std::string> &arguments) -> void {
        auto occurence = std::count_if(
                arguments.begin(), arguments.end(),
                [](const auto &argument) {
                    return argument == "-o" || argument == "--output";
                }
        );

        if (occurence > 1) {
            std::cout << "There's more than one -o flag!";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }
        if (occurence == 1) {
            check_if_o_is_not_a_last_input(arguments);
            check_if_there_is_file_path_after_o_flag(arguments);
        }

        if (should_exception_be_called) {
            throw my_exception("-o flag problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto remove_everything_except_flags(std::vector<std::string> &arguments) -> void {
        //usuwam wszystko co nie jest flagą
        auto beginning_of_removal = std::remove_if(arguments.begin(), arguments.end(),
                                                   [](auto potential_argument) {
                                                       auto cut_string = potential_argument.substr(0, 1);
                                                       return cut_string != "-";
                                                   });
        arguments.erase(beginning_of_removal, arguments.end());

        //usuwam wszystko co jest aliasem - nie biorę ich tu pod uwagę
        auto beginning_of_removal2 = std::remove_if(arguments.begin(), arguments.end(),
                                                    [](auto potential_argument) {
                                                        auto cut_string = potential_argument.substr(0, 2);
                                                        return cut_string == "--";
                                                    });
        arguments.erase(beginning_of_removal2, arguments.end());
    }

    auto
    get_available_flags(const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> std::set<std::string> {
        auto available_flags = std::set<std::string>();
        for (const auto &element : map) {
            available_flags.insert(element.first);
        }
        return available_flags;
    }


    auto is_each_candidate_a_valid_flag(const std::vector<std::string> &arguments_only_flags,
                                        const std::set<std::string> &available_flags) -> void {
        for (const auto &argument : arguments_only_flags) {
            if (argument != "-f") {
                if (std::find(available_flags.begin(), available_flags.end(), argument) ==
                    available_flags.end()) {   //not found
                    std::cout << argument << " is not a valid flag!";
                    should_exception_be_called = true;
//                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    auto is_every_flag_in_arguments_a_valid_flag(std::vector<std::string> arguments,
                                                 const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void {

        remove_everything_except_flags(arguments);
        auto available_flags = get_available_flags(map);
        is_each_candidate_a_valid_flag(arguments, available_flags);

        if (should_exception_be_called) {
            throw my_exception("validation flag problem");
        }
    }

    auto is_this_a_valid_flag_or_alias(const std::string &argument,
                                       const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> bool {
        auto available_flags = get_available_flags(map);
        if (argument != "-f") {
            if (std::find(available_flags.begin(), available_flags.end(), argument) ==
                available_flags.end()) {   //not found
                if (argument.substr(0, 2) == "--") {
                    if (o_flag_functions::get_if_send_output_to_file()) {
                        o_flag_functions::send_output_to_file(argument + " is not a valid alias!");
                    } else {
                        std::cout << argument << " is not a valid alias!\n";
                    }

                } else {
                    if (o_flag_functions::get_if_send_output_to_file()) {
                        o_flag_functions::send_output_to_file(argument + " is not a valid flag!");
                    } else {
                        std::cout << argument << " is not a valid flag!\n";
                    }
                }
                return false;
            } else {
                return true;
            }
        }
        return true;
    }

//----------------------------------------------------------------------------------------------------------------------
    auto remove_everything_except_aliases(std::vector<std::string> &arguments) -> void {
        auto beginning_of_removal = std::remove_if(arguments.begin(), arguments.end(),
                                                   [](const auto &potential_argument) {
                                                       auto cut_string = potential_argument.substr(0, 2);
                                                       return cut_string != "--";
                                                   });
        arguments.erase(beginning_of_removal, arguments.end());
    }

    auto
    get_available_aliases(const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> std::set<std::string> {
        auto available_aliases = std::set<std::string>();
        for (const auto &element : map) {
            available_aliases.insert(element.second->get_flag_alias());
        }

        return available_aliases;
    }

    auto is_each_candidate_a_valid_alias(const std::vector<std::string> &arguments_only_aliases,
                                         const std::set<std::string> &available_aliases) -> void {
        for (const auto &argument : arguments_only_aliases) {
            if (argument != "--file") {
                if (std::find(available_aliases.begin(), available_aliases.end(), argument) ==
                    available_aliases.end()) {   //not found
                    std::cout << argument << " is not a valid alias!";
                    should_exception_be_called = true;
//                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    auto is_every_alias_in_arguments_a_valid_alias(std::vector<std::string> arguments,
                                                   const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void {

        remove_everything_except_aliases(arguments);
        auto available_aliases = get_available_aliases(map);
        is_each_candidate_a_valid_alias(arguments, available_aliases);

        if (should_exception_be_called) {
            throw my_exception("validation alias problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto get_only_flags_and_aliases(const std::vector<std::string> &arguments) -> std::vector<std::string> {
        auto only_flags_and_aliases = std::vector<std::string>();

        for (const auto &arg : arguments) {
            if (*arg.begin() == '-') {
                only_flags_and_aliases.push_back(arg);
            }
        }
        return only_flags_and_aliases;
    }

    auto is_a_definitely_a_last_flag(const std::vector<std::string> &arguments) -> void {
        auto only_flags_and_aliases = get_only_flags_and_aliases(arguments);
        replace_given_flag_alias_with_given_flag_name(only_flags_and_aliases, "--anagrams", "-a");

        if (only_flags_and_aliases.back() != "-a") {
            std::cout << "-a is not the last flag!";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }

    }

    auto is_a_flag_meeting_all_the_requirements(const std::vector<std::string> &arguments) -> void {

        auto amount_of_a_flags_or_aliases = std::count_if(      //zrób z tego count_a_flags_and_aliases
                arguments.begin(), arguments.end(),
                [](const auto &arg) {
                    return arg == "-a";
                }
        );
        amount_of_a_flags_or_aliases += std::count_if(
                arguments.begin(), arguments.end(),
                [](const auto &arg) {
                    return arg == "--anagrams";
                }
        );

        if (amount_of_a_flags_or_aliases > 1) {
            std::cout << "There's more than one -a flag!\n";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }
        if (amount_of_a_flags_or_aliases == 1) {
            is_a_definitely_a_last_flag(arguments);
        }

        if (should_exception_be_called) {
            throw my_exception("-a flag problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto is_l_flag_meeting_all_the_requirements(const std::vector<std::string> &arguments) -> void {

        auto only_flags_and_aliases = get_only_flags_and_aliases(arguments);
        replace_given_flag_alias_with_given_flag_name(only_flags_and_aliases, "--by-length", "-l");
        replace_given_flag_alias_with_given_flag_name(only_flags_and_aliases, "--sorted", "-s");
        replace_given_flag_alias_with_given_flag_name(only_flags_and_aliases, "--reverse-sorted", "-rs");

        if (is_there_any_given_as_an_argument_flag(only_flags_and_aliases, "-l")) {

            auto l_vector = std::vector<std::string>{"-l"};
            auto last_l_iterator = std::find_end(
                    only_flags_and_aliases.begin(), only_flags_and_aliases.end(),
                    l_vector.begin(), l_vector.end());

            if (std::find_if(last_l_iterator, only_flags_and_aliases.end(),
                             [](const auto &flag_or_alias) {
                                 return flag_or_alias == "-s" ||
                                        flag_or_alias == "-rs";    //podziel to na mniejsze funkcje i dodaj dokumentację
                             }) == only_flags_and_aliases.end()) {
                std::cout << "There's no -s or -rs flag for -l flag!";
                should_exception_be_called = true;
//                exit(EXIT_FAILURE);
            }
        }

        if (should_exception_be_called) {
            throw my_exception("-l flag problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto is_p_definitely_a_last_flag(const std::vector<std::string> &arguments) -> void {
        auto only_flags_and_aliases = get_only_flags_and_aliases(arguments);

        if (only_flags_and_aliases.back() != "-p") {
            std::cout << "-p is not the last flag!";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }

    }

    auto is_p_flag_meeting_all_the_requirements(std::vector<std::string> arguments) -> void {
        replace_given_flag_alias_with_given_flag_name(arguments, "--palindromes", "-p");
        if (is_there_any_given_as_an_argument_flag(arguments, "-p")) {
            is_p_definitely_a_last_flag(arguments);
        }

        if (should_exception_be_called) {
            throw my_exception("-p flag problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto if_i_flag_is_the_only_flag(const std::vector<std::string> &arguments) -> void {
        if (arguments.size() == 1) {
            std::cout << "There's no input file path!";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }
        auto amount_of_flags = std::count_if(
                arguments.begin(), arguments.end(),
                [](const auto &argument) {
                    return argument.substr(0, 1) == "-";
                }
        );
        if (amount_of_flags > 1) {
            std::cout << "-i is not the only flag, as it should be!\n";
            should_exception_be_called = true;
//            exit(EXIT_FAILURE);
        }
    }

    auto is_there_any_i_flag(std::vector<std::string> &arguments) -> bool {
        replace_given_flag_alias_with_given_flag_name(arguments, "--input", "-i");
        if (std::find_if(arguments.begin(), arguments.end(),
                         [](const auto &argument) {
                             return argument == "-i";
                         }) != arguments.end()) {
            return true;
        } else {
            return false;
        }
    }

    auto is_i_flag_meeting_all_the_requirements(std::vector<std::string> arguments) -> void {
        replace_given_flag_alias_with_given_flag_name(arguments, "--input", "-i");
        if (is_there_any_given_as_an_argument_flag(arguments, "-i")) {
            if_i_flag_is_the_only_flag(arguments);
        }

        if (should_exception_be_called) {
            throw my_exception("-i flag problem");
        }
    }

//----------------------------------------------------------------------------------------------------------------------
    auto is_input_correct(const std::vector<std::string> &arguments,
                          const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void {
//        is_every_flag_in_arguments_a_valid_flag(arguments, map);
//        is_every_alias_in_arguments_a_valid_alias(arguments, map);
        is_f_flag_meeting_all_the_requirements(arguments);
        is_o_flag_meeting_all_the_requirements(arguments);
        is_a_flag_meeting_all_the_requirements(arguments);
        is_l_flag_meeting_all_the_requirements(arguments);
        is_p_flag_meeting_all_the_requirements(arguments);
        is_i_flag_meeting_all_the_requirements(arguments);
    }

}

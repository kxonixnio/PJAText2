//
// Created by Mikołaj on 31.05.2021.
//

#ifndef PJATEXT2_ISINPUTCORRECT_HPP
#define PJATEXT2_ISINPUTCORRECT_HPP

#include <memory>
#include <set>
#include "abstract_flag.hpp"

namespace input_correctness {

/**
 * Replaces given alias of the flag with the given flag name
 * @param arguments - std::vector<std::string> where changes will happen
 * @param alias - flag alias
 * @param flag - flag name
 */
    auto replace_given_flag_alias_with_given_flag_name(std::vector<std::string> &arguments, const std::string &alias,
                                                       const std::string &flag) -> void;

    /**
     *
     * @param arguments //uzupelnij
     * @param flag
     * @return
     */
    auto
    is_there_any_given_as_an_argument_flag(const std::vector<std::string> &arguments, const std::string &flag) -> bool;

    /**
     *Checks if -f flag meets all the requirements to start PJAText2.
     * @param arguments - std::vector<std::string> of provided arguments by user.
     */
    auto is_f_flag_meeting_all_the_requirements(std::vector<std::string> arguments) -> void;
//----------------------------------------------------------------------------------------------------------------------
/**
 * Checks if there is a file path after -o/--output.
 * If there's a flag instead, function exit() is called.
 * @param arguments - std::vector<std::string> of provided arguments by user.
 */
    auto check_if_there_is_file_path_after_o_flag(const std::vector<std::string> &arguments) -> void;

    /**
     * Checks if there's anything after -o/--output.
     * If not, function exit() is called.
     * @param arguments - std::vector<std::string> of provided arguments by user.
     */
    auto check_if_o_is_not_a_last_input(std::vector<std::string> arguments) -> void;

    /**
     * Checks if -o flag meets all the requirements to start PJAText2
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_o_flag_meeting_all_the_requirements(const std::vector<std::string> &arguments) -> void;
//----------------------------------------------------------------------------------------------------------------------
    /**
     * Removes these arguments, which are not considered as a candidate to be a flag
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto remove_everything_except_flags(std::vector<std::string> &arguments) -> void;

    /**
     * Returns a container which contains all the possible flags
     * @param map - map which connects flag name with appropriate flag object
     * @return available_flags - container filled with all possible flags
     */
    auto get_available_flags(const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> std::set<std::string>;

    /**
     * Checks if each of the provided flags is one of the available flags - if not, the function exit starts
     * @param arguments_only_flags - selected arguments, which are all supposed to be flags
     * @param available_flags - container filled with all possible flags
     */
    auto is_each_candidate_a_valid_flag(const std::vector<std::string> &arguments_only_flags,
                                        const std::set<std::string> &available_flags) -> void;

    /**
     * If there's at least one invalid flag in arguments function exit() is called
     * @param arguments - std::vector<std::string> of provided arguments by user
     * @param map - map which connects flag name with appropriate flag object
     */
    auto is_every_flag_in_arguments_a_valid_flag(std::vector<std::string> arguments,
                                                 const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void;

    /**
     * Checks if provided argument is a valid flag/alias.
     * Valid flags are terminated in map.
     * @param argument - flag/alias to check
     * @param map - map which connects flag name with appropriate flag object
     * @return
     */
    auto is_this_a_valid_flag_or_alias(const std::string &argument,
                                       const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> bool;
//----------------------------------------------------------------------------------------------------------------------
    /**
     * Removes these arguments, which are not considered as a candidate to be a alias
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto remove_everything_except_aliases(std::vector<std::string> &arguments) -> void;

    /**
     * Returns a container which contains all the possible aliases
     * @param map - map which connects flag name with appropriate flag object
     * @return available_aliases - container filled with all possible aliases
     */
    auto
    get_available_aliases(const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> std::set<std::string>;

    /**
     * Checks if each of the provided aliases is one of the available aliases - if not, the function exit starts
     * @param arguments_only_aliases - selected arguments, which are all supposed to be aliases
     * @param available_flags - container filled with all possible aliases
     */
    auto is_each_candidate_a_valid_alias(const std::vector<std::string> &arguments_only_aliases,
                                         const std::set<std::string> &available_aliases) -> void;

    /**
     * If there's at least one invalid alias in arguments function exit() is called
     * @param arguments - std::vector<std::string> of provided arguments by user
     * @param map - map which connects flag name with appropriate flag object
     */
    auto is_every_alias_in_arguments_a_valid_alias(std::vector<std::string> arguments,
                                                   const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void;
//----------------------------------------------------------------------------------------------------------------------
    /**
     * Extract only these arguments, which are flags or aliases
     * @param arguments - std::vector<std::string> of provided arguments by user
     * @return vector, which includes flags and aliases only
     */
    auto get_only_flags_and_aliases(const std::vector<std::string> &arguments) -> std::vector<std::string>;

    /**
     * Checks if "-a" is a last typed flag. If not, function exit() is called
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_a_definitely_a_last_flag(const std::vector<std::string> &arguments) -> void;

    /**
     * "Parent" function, which connects all functions above in one.
     * If "-a" flag is not meeting all the requirements calls exit() function
     * Only this one should be called in "is_input_correct"
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_a_flag_meeting_all_the_requirements(const std::vector<std::string> &arguments) -> void;

//----------------------------------------------------------------------------------------------------------------------
    /**
     * "Parent" function, which connects all functions above in one.
     * Only this one should be called in "is_input_correct".
     * If "-l" flag is not meeting all the requirements calls exit() function.
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_l_flag_meeting_all_the_requirements(const std::vector<std::string> &arguments) -> void;

//----------------------------------------------------------------------------------------------------------------------
    /**
     * Checks if "-p" is a last typed flag. If not, function exit() is called
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_p_definitely_a_last_flag(const std::vector<std::string> &arguments) -> void;

    /**
     * "Parent" function, which connects all functions above in one.
     * Only this one should be called in "is_input_correct".
     * If "-p" flag is not meeting all the requirements calls exit() function.
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_p_flag_meeting_all_the_requirements(std::vector<std::string> arguments) -> void;
//----------------------------------------------------------------------------------------------------------------------
    /**
     * Checks if -i flag is the only one that exists in arguments
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto if_i_flag_is_the_only_flag(const std::vector<std::string> &arguments) -> void;

    /**
     * Checks if -i flag even exists in arguments
     * @param arguments - std::vector<std::string> of provided arguments by user
     * @return true if there's at least one -i flag. False otherwise
     */
    auto is_there_any_i_flag(std::vector<std::string> &arguments) -> bool;

    /**
     * "Parent" function, which connects all functions above in one.
     * Only this one should be called in "is_input_correct".
     * If "-i" flag is not meeting all the requirements calls exit() function.
     * @param arguments - std::vector<std::string> of provided arguments by user
     */
    auto is_i_flag_meeting_all_the_requirements(std::vector<std::string> arguments) -> void;
//---------------------------------------------------------------------------------------------------------------------=
    /**
     * "main" function in this hpp. Connects all the functions in one, and only this one should be used in main
     * to check arguments correctness. Any function in this function can throw exception if input is incorrect.
     * @param arguments - std::vector<std::string> of provided arguments by user
     * @param map - map which connects flag name with appropriate flag object
     */
    auto is_input_correct(const std::vector<std::string> &arguments,
                          const std::map<std::string, std::unique_ptr<abstract_flag>> &map) -> void;

}
#endif //PJATEXT2_ISINPUTCORRECT_HPP

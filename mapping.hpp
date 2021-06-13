//
// Created by Mikołaj on 11.06.2021.
//

#ifndef PJATEXT2_MAPPING_HPP
#define PJATEXT2_MAPPING_HPP

#include <vector>
#include <string>
#include <map>
#include <memory>
#include "abstract_flag.hpp"

//https://stackoverflow.com/questions/25465224/making-a-map-in-which-the-value-type-is-an-abstract-class-in-c
//https://stackoverflow.com/questions/2160920/why-cant-we-declare-a-stdvectorabstractclass

namespace mapping {

/**
 * Adds -n flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_n_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_line_by_line) -> void;

/**
 * Adds -d flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_line_by_line - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_d_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_line_by_line) -> void;

/**
 * Adds -dd flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_dd_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                     const std::vector<std::string> &file_content_word_by_word) -> void;

/**
 * Adds -c flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_c_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word,
                    const std::vector<std::string> &file_content_line_by_line) -> void;

/**
 * Adds -w flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_w_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void;

/**
 * Adds -s flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_s_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void;

/**
 * Adds -rs flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_rs_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                     const std::vector<std::string> &file_content_word_by_word) -> void;

/**
 * Adds -l flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 */
    auto map_l_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void;

/**
 * Adds -a flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @param arguments - user input
 */
    auto map_a_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word,
                    const std::vector<std::string> &arguments) -> void;

/**
 * Adds -p flag to the map of valid flags
 * @param map - map of valid flags
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @param arguments - user input
 */
    auto map_p_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word,
                    const std::vector<std::string> &arguments) -> void;

/**
 * Adds -o flag to the map of valid flags
 * @param map - map of valid flags
 * @param arguments - user input
 */
    auto map_o_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &arguments) -> void;

/**
 * Adds -i flag to the map of valid flags
 * @param map - map of valid flags
 * @param arguments - user input
 */
    auto map_i_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &arguments) -> void;

/**
 *
 * @param map
 * @param file_content_word_by_word
 */
    auto map_t_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void;

/**
 * Returns a map which connects flag name with appropriate flag object
 * @param file_content_line_by_line
 * @param file_content_word_by_word
 * @param arguments
 * @return
 */
    auto get_mapped_flags(const std::vector<std::string> &file_content_line_by_line,
                          const std::vector<std::string> &file_content_word_by_word,
                          const std::vector<std::string> &arguments) -> std::map<std::string, std::unique_ptr<abstract_flag>>;
}
#endif //PJATEXT2_MAPPING_HPP

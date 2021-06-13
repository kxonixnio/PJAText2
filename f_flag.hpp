//
// Created by Mikołaj on 13.05.2021.
//

#ifndef PJATEXT2_F_FLAG_HPP
#define PJATEXT2_F_FLAG_HPP

#include <vector>
#include <string>

#include "abstract_flag.hpp"

/**
 * Returns a string vector, which storage a content read from the file line by line.
 * Each line from a file is a different string
 * @param arguments - user input
 * @return content from file separated line by line in string vector
 */
auto read_file_by_line(const std::vector<std::string> &arguments) -> std::vector<std::string>;

/**
 * Returns a string vector, which storage a content read from the file word by word.
 * Each word from a file is a different string
 * @param arguments - user input
 * @return content from file separated word by word in string vector
 */
auto read_file_by_word(const std::vector<std::string> &arguments) -> std::vector<std::string>;

/**
 * Insert file content into to vectors - line by line and word by word
 * @param arguments - user input
 * @param file_content_line_by_line - vector, where every line is a separate string
 * @param file_content_word_by_word - vector, where every word is a separate string
 */
auto read_file_and_insert_output_into_two_vectors(const std::vector<std::string> &arguments,
                                                  std::vector<std::string> &file_content_line_by_line,
                                                  std::vector<std::string> &file_content_word_by_word) -> void;


#endif //PJATEXT2_F_FLAG_HPP

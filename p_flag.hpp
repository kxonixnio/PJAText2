//
// Created by Mikołaj on 10.06.2021.
//

#ifndef PJATEXT2_P_FLAG_HPP
#define PJATEXT2_P_FLAG_HPP

#include "abstract_flag.hpp"

/**
 * Takes vector and returns it without everything, what was before -p flag (-p included)
 * @param arguments - user input
 */
auto extract_words_after_p_flag(std::vector<std::string> &arguments) -> void;

/**
 * Checks whether a provided word is a palindrome or not.
 * @param word - potential palindrome
 * @return true if the word is a palindrome, false otherwise
 */
auto is_palindrome(const std::string &word) -> bool;

/**
 * Checks whether a provided palindrome exists in a file.
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @param palindrome - word that reads the same backwards as forwards
 * @return
 */
auto does_palindrome_exist_in_file(const std::vector<std::string> &file_content_word_by_word,
                                   const std::string &palindrome) -> bool;

/**
 * Takes two vectors and returns container with words from arguments considered as palindromes, which also exists
 * in file_content_word_by_word
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @param arguments - words to be checked
 * @return - std::set<std::string> which contains words considered as palindromes, which exists in both vectors
 */
auto find_palindromes_in_two_vectors(const std::vector<std::string> &file_content_word_by_word,
                                     const std::vector<std::string> &arguments) -> std::set<std::string>;

/**
 * Prints all palindromes of words precised after -p flag, which also exists in file content
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @param arguments - user input, potential palindromes
 */
auto
find_palindromes(const std::vector<std::string> &file_content_word_by_word, std::vector<std::string> arguments) -> void;

struct p : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;
    std::vector<std::string> arguments;

public:
    p(const std::vector<std::string> &content, const std::vector<std::string> &arguments);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_P_FLAG_HPP

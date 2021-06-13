//
// Created by Mikołaj on 09.06.2021.
//

#ifndef PJATEXT2_A_FLAG_HPP
#define PJATEXT2_A_FLAG_HPP

#include "abstract_flag.hpp"
#include <set>

/**
 * Takes vector and returns it without everything, what was before -a flag (-a included)
 * @param arguments - user input
 */
auto extract_words_after_a_flag(std::vector<std::string> &arguments) -> void;

/**
 * Takes two vectors and returns container with words from vector1, which are anagrams of words from vector2
 * @param vector1 - contains words, which can be an anagrams of words from vector2
 * @param vector2 - words to be compared
 * @return - std::set<std::string> which contains words from vector1, which are anagrams of any word in vector2
 */
auto find_anagrams_in_two_vectors(const std::vector<std::string> &vector1,
                                  const std::vector<std::string> &vector2) -> std::set<std::string>;

/**
 * Prints all anagrams of words precised after -a flag from file read previously by user
 * @param file_content_word_by_word - std::vector<std::string> which should be received earlier by one of the -f
 * flag functions
 * @param arguments - user input, potential anagrams
 */
auto print_anagrams_of_words_from_file_typed_after_a_flag(const std::vector<std::string> &file_content_word_by_word,
                                                          std::vector<std::string> arguments) -> void;

struct a : abstract_flag {
private:
    std::vector<std::string> file_content;
    std::string flag_name;
    std::string flag_alias;
    std::vector<std::string> arguments;

public:
    a(const std::vector<std::string> &content, const std::vector<std::string> &arguments);

    void do_stuff() const override;

    const std::string &get_flag_name() const override;

    const std::string &get_flag_alias() const override;
};

#endif //PJATEXT2_A_FLAG_HPP

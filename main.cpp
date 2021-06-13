#include <vector>
#include <string>
#include <map>
#include <memory>
#include <algorithm>

#include "isInputCorrect.hpp"
#include "mapping.hpp"
#include "introducing.hpp"
#include "my_exception.hpp"
#include "f_flag.hpp"
#include "o_flag.hpp"
#include "i_flag.hpp"

/**
 * Function which provides, that program will accept not only flags names, but also theirs aliases.
 * Changes current flag alias to appropriate flag name.
 * @param current_flag - std::string which is current examined flag
 * @param map - map which connects flag name with appropriate flag object
 */
auto handle_flag_aliases(std::string &current_flag, const std::map<std::string, std::unique_ptr<abstract_flag>> &map) {
    for (auto const&[key, val] : map) {
        if (current_flag == val->get_flag_alias()) {
            current_flag = val->get_flag_name();
        }
    }
}

/**
 * Takes each flag from arguments and do its stuff.
 * Make sure that arguments were read and map mapped previously.
 * @param arguments - user input
 * @param map - map which connects flag name with appropriate flag object
 */
auto do_every_flag_stuff(const std::vector<std::string> &arguments,
                         std::map<std::string, std::unique_ptr<abstract_flag>> &map) {

    //Pierwszeństwo flagi -o nad wszystkimi innymi. Trzeba zadecydować i wysłać sygnał czy output idzie do pliku
    o_flag_functions::decide_whether_output_should_be_send_to_file(arguments, map);

    for (int i = 2; i < arguments.size(); i++) {        //omijamy -f i plik źródłowy
        auto current_flag = std::string(arguments[i]);

        if (*current_flag.begin() == '-') {
            handle_flag_aliases(current_flag, map);

            if (input_correctness::is_this_a_valid_flag_or_alias(current_flag, map)) {
                if (map[current_flag]->get_flag_name() != "-o") { //-o zostało już wykonane, nie chcemy tego powtarzać
                    map[current_flag]->do_stuff();
                }
            }
        }
    }
}

int main(int argc, const char **argv) {
    auto arguments = std::vector<std::string>(argv + 1, argv + argc);

    auto file_content_line_by_line = std::vector<std::string>();
    auto file_content_word_by_word = std::vector<std::string>();

    try {
        if (!arguments.empty()) {
            read_file_and_insert_output_into_two_vectors(arguments, file_content_line_by_line,
                                                         file_content_word_by_word);
        } else {
            introducing::introduce_program();
        }

        auto map = mapping::get_mapped_flags(file_content_line_by_line, file_content_word_by_word, arguments);

        input_correctness::is_input_correct(arguments, map);

        if (!input_correctness::is_there_any_i_flag(arguments)) {
            do_every_flag_stuff(arguments, map);

        } else {
            auto input_file_arguments_word_by_word = i_flag_functions::get_input_file_arguments(arguments);

            if (!input_file_arguments_word_by_word.empty()) {
                read_file_and_insert_output_into_two_vectors(input_file_arguments_word_by_word,
                                                             file_content_line_by_line,
                                                             file_content_word_by_word);
            } else {
                introducing::introduce_program();
            }

            map = mapping::get_mapped_flags(file_content_line_by_line, file_content_word_by_word,
                                            input_file_arguments_word_by_word);

            input_correctness::is_input_correct(input_file_arguments_word_by_word, map);
            do_every_flag_stuff(input_file_arguments_word_by_word, map);
        }
    } catch (const my_exception &exception) {
        exception.what();
    }

    return 0;
}
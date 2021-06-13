//
// Created by Mikołaj on 11.06.2021.
//

#include "mapping.hpp"
#include "n_flag.hpp"
#include "d_flag.hpp"
#include "dd_flag.hpp"
#include "c_flag.hpp"
#include "w_flag.hpp"
#include "s_flag.hpp"
#include "rs_flag.hpp"
#include "l_flag.hpp"
#include "a_flag.hpp"
#include "p_flag.hpp"
#include "o_flag.hpp"
#include "i_flag.hpp"
#include "t_flag.hpp"

namespace mapping {

    auto map_n_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_line_by_line) -> void {
        map["-n"] = std::unique_ptr<abstract_flag>(new n(file_content_line_by_line));
    }

    auto map_d_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_line_by_line) -> void {
        map["-d"] = std::unique_ptr<abstract_flag>(new d(file_content_line_by_line));
    }

    auto map_dd_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                     const std::vector<std::string> &file_content_word_by_word) -> void {
        map["-dd"] = std::unique_ptr<abstract_flag>(new dd(file_content_word_by_word));
    }

    auto map_c_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word,
                    const std::vector<std::string> &file_content_line_by_line) -> void {
        map["-c"] = std::unique_ptr<abstract_flag>(new c(file_content_word_by_word, file_content_line_by_line));
    }

    auto map_w_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void {
        map["-w"] = std::unique_ptr<abstract_flag>(new w(file_content_word_by_word));
    }

    auto map_s_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void {
        map["-s"] = std::unique_ptr<abstract_flag>(new s(file_content_word_by_word));
    }

    auto map_rs_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                     const std::vector<std::string> &file_content_word_by_word) -> void {
        map["-rs"] = std::unique_ptr<abstract_flag>(new rs(file_content_word_by_word));
    }

    auto map_l_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void {
        map["-l"] = std::unique_ptr<abstract_flag>(new l(file_content_word_by_word));
    }

    auto map_a_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word,
                    const std::vector<std::string> &arguments) -> void {
        map["-a"] = std::unique_ptr<abstract_flag>(new a(file_content_word_by_word, arguments));
    }

    auto map_p_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word,
                    const std::vector<std::string> &arguments) -> void {
        map["-p"] = std::unique_ptr<abstract_flag>(new p(file_content_word_by_word, arguments));
    }

    auto map_o_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &arguments) -> void {
        map["-o"] = std::unique_ptr<abstract_flag>(new o(arguments));
    }

    auto map_i_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &arguments) -> void {
        map["-i"] = std::unique_ptr<abstract_flag>(new i(arguments));
    }

    auto map_t_flag(std::map<std::string, std::unique_ptr<abstract_flag>> &map,
                    const std::vector<std::string> &file_content_word_by_word) -> void {
        map["-t"] = std::unique_ptr<abstract_flag>(new t(file_content_word_by_word));
    }

    auto get_mapped_flags(const std::vector<std::string> &file_content_line_by_line,
                          const std::vector<std::string> &file_content_word_by_word,
                          const std::vector<std::string> &arguments) -> std::map<std::string, std::unique_ptr<abstract_flag>> {

        auto map = std::map<std::string, std::unique_ptr<abstract_flag>>();

        map_n_flag(map, file_content_line_by_line);
        map_d_flag(map, file_content_line_by_line);
        map_dd_flag(map, file_content_word_by_word);
        map_c_flag(map, file_content_word_by_word, file_content_line_by_line);
        map_w_flag(map, file_content_word_by_word);
        map_s_flag(map, file_content_word_by_word);
        map_rs_flag(map, file_content_word_by_word);
        map_l_flag(map, file_content_word_by_word);
        map_a_flag(map, file_content_word_by_word, arguments);
        map_p_flag(map, file_content_word_by_word, arguments);
        map_o_flag(map, arguments);
        map_i_flag(map, arguments);
        map_t_flag(map, file_content_word_by_word);

        return map;
    };
}

//
// Created by Mikołaj on 08.06.2021.
//

#ifndef PJATEXT2_ABSTRACT_FLAG_HPP
#define PJATEXT2_ABSTRACT_FLAG_HPP

#include <string>
#include <vector>


struct abstract_flag {

    virtual void do_stuff() const = 0;

    virtual const std::string &get_flag_name() const = 0;

    virtual const std::string &get_flag_alias() const = 0;

};

#endif //PJATEXT2_ABSTRACT_FLAG_HPP

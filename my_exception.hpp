//
// Created by Mikołaj on 12.06.2021.
//

#ifndef PJATEXT2_MY_EXCEPTION_HPP
#define PJATEXT2_MY_EXCEPTION_HPP

#include <stdexcept>

struct my_exception : std::logic_error {

    my_exception(const char *text) : logic_error(text) {};

};


#endif //PJATEXT2_MY_EXCEPTION_HPP

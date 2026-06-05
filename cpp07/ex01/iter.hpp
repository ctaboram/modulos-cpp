#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>
template<typename T_array, typename T_function>
void iter(T_array *array, std::size_t length, T_function function)
{
    for (std::size_t i = 0; i < length; ++i)
    {
        function(array[i]);
    }
}
#endif
#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

void increment(int &i)
{
    i++;
}

void to_up(std::string &str)
{
    for (std::size_t i = 0; i < str.length(); ++i)
        str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
}

int main(void)
{
    int int_array[] = {4, 2, 1};
    ::iter(int_array, 3, increment);
    for (int i = 0; i < 3; i++)
        std::cout << int_array[i] << std::endl;
    std::cout << std::endl;
    std::string str_array[] = {"Hello", "carlos", "goOd"};

    ::iter(str_array, 3, to_up);
    for (int i = 0; i < 3; i++)
        std::cout << str_array[i] << std::endl;

    return 0;
}
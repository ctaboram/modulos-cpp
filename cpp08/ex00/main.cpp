#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        vec.push_back(42);
        std::cout << "looking for 42" << std::endl;
        std::vector<int>::iterator it = easyfind(vec,42);
        std::cout << *it << std::endl;
        std::cout << "Throw exception" << std::endl;
        std::cout << "Looking for 100: " << std::endl;
        easyfind(vec, 100);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: value not found in container" << std::endl;
    }
    return 0;
}

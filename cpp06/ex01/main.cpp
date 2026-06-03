#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    data.values = 34;

    Data *original = &data;

    uintptr_t raw = Serializer::serialize(original);
    Data *deserialized = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Serialized data : " << raw << std::endl;
    std::cout << "Deserialzed ptr : " << deserialized << std::endl;

    std::cout << "\nChecking if pointing to the same address..." << std::endl;
    if (original == deserialized) {
        std::cout << "SUCCESS! Pointers match." << std::endl;
        std::cout << "Original value = " << original->values << std::endl;
        std::cout << "Deserialized value = " << deserialized->values << std::endl;
    } else {
        std::cout << "FAILURE! Pointers do not match." << std::endl;
    }

    return 0;
}
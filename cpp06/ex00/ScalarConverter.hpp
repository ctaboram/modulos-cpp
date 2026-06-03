#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER
#include <string>

enum e_type{
    T_CHAR,
    T_INT,
    T_FLOAT,
    T_DOUBLE,
    T_PSEUDO,
    T_UNKNOWN
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(const std::string &target);
};
e_type getType(const std::string &target);
#endif
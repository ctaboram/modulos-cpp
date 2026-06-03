#include "ScalarConverter.hpp"
#include <iostream> 
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudo(const std::string &target) {
    return (target == "-inff" || target == "+inff" || target == "nanf" ||
            target == "-inf" || target == "+inf" || target == "nan");
}

static bool isChar(const std::string &target) {
    return target.length() == 1 && !std::isdigit(target[0]) && std::isprint(target[0]);
}

static bool isInt(const std::string &target) {
    size_t i = 0;
    if (target.empty()) 
		return false;
    if (target[i] == '-' || target[i] == '+') 
		i++;
    if (i == target.length()) 
		return false;

    while (i < target.length()) {
        if (!std::isdigit(target[i])) 
			return false;
        i++;
    }
    return true;
}

static bool isDouble(const std::string &target) {
    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (target.empty()) 
		return false;
    if (target[i] == '-' || target[i] == '+') 
		i++;
    if (i == target.length()) 
		return false;
    while (i < target.length()) {
        if (target[i] == '.') {
            if (hasDot) 
				return false;

            hasDot = true;
        } else if (std::isdigit(target[i])) {
            hasDigit = true;
        } else {
            return false;
        }
        i++;
    }
    return hasDot && hasDigit;
}

static bool isFloat(const std::string &target) {
    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (target.length() < 2)
		return false;
    if (target[target.length() - 1] != 'f') 
		return false;
    if (target[i] == '-' || target[i] == '+') 
		i++;
    if (i >= target.length() - 1) 
		return false;

    while (i < target.length() - 1) {
        if (target[i] == '.') {
            if (hasDot) 
				return false;
            hasDot = true;
        } else if (std::isdigit(target[i])) {
            hasDigit = true;
        } else {
            return false;
        }
        i++;
    }
    return hasDot && hasDigit;
}

e_type getType(const std::string &target)
{
    if (isChar(target))   return T_CHAR;
    if (isPseudo(target)) return T_PSEUDO;
    if (isInt(target))    return T_INT;
    if (isFloat(target))  return T_FLOAT;
    if (isDouble(target)) return T_DOUBLE;
    
    return T_UNKNOWN;
}

static double toDouble(const std::string& s, e_type type)
{
    if (type == T_CHAR)
        return static_cast<double>(s[0]);
    return std::strtod(s.c_str(), NULL);
}

static void printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 255) {
        std::cout << "impossible\n";
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }
}

static void printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(value) << "\n";
    }
}

static void printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf\n";
    } else if (std::isinf(value)) {
        if (value > 0) std::cout << "+inff\n";
        else std::cout << "-inff\n";
    } else {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f - static_cast<int>(f) == 0.0 && f >= -999999.0 && f <= 999999.0) {
            std::cout << ".0";
        }
        std::cout << "f\n";
    }
}

static void printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan\n";
    } else if (std::isinf(value)) {
        if (value > 0) std::cout << "+inf\n";
        else std::cout << "-inf\n";
    } else {
        std::cout << value;
        if (value - static_cast<int>(value) == 0.0 && value >= -999999.0 && value <= 999999.0) {
            std::cout << ".0";
        }
        std::cout << "\n";
    }
}

void ScalarConverter::convert(const std::string &target)
{
    e_type type = getType(target);

	if (type == T_UNKNOWN)
	{
		std::cout << "Invalid input\n";
		return;
	}

	double value = toDouble(target, type);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-16 10:59:17 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-16 10:59:17 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <sstream>
/*
    ./convert 0
    char: Non displayable
    int: 0
    float: 0.0f
    double: 0.0
    ./convert nan
    char: impossible
    int: impossible
    float: nanf
    double: nan
    ./convert 42.0f
    char: '*'
    int: 42
    float: 42.0f
    double: 42.0
*/

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter(void) { }

static void print_char(std::string toConvert) {
    if (isprint(static_cast<unsigned char>(toConvert[0])))
        std::cout << "char: '" << static_cast<char>(toConvert[0]) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(toConvert[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(toConvert[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(toConvert[0]) << ".0" << std::endl;
}

static void print_int(std::string toConvert) {
    std::stringstream ss;
    long long i = 0;

    ss << toConvert;
    ss >> i;
    if (i > std::numeric_limits<int>::max() ||
        i < std::numeric_limits<int>::min())
        std::cout << "char: impossible" << std::endl;
    else if (isprint(i))
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (i > std::numeric_limits<int>::max() ||
        i < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void print_float(std::string toConvert) {
    toConvert.erase(toConvert.length() - 1);
    std::stringstream ss;
    float f = 0.0f;

    ss << toConvert;
    ss >> f;
    std::string trailing_float = (f - static_cast<int>(f) == 0) ? ".0f" : "f";
    std::string trailing_double = (f - static_cast<int>(f) == 0) ? ".0" : "";
    if (isprint(f))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (f > static_cast<double>(std::numeric_limits<int>::max()) ||
        f < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << trailing_float << std::endl;
    std::cout << "double: " << static_cast<double>(f) << trailing_double << std::endl;
}

static void print_double(std::string toConvert) {
    std::stringstream ss;
    double d = 0.0;

    ss << toConvert;
    ss >> d;
    std::string trailing_float = (d - static_cast<int>(d) == 0) ? ".0f" : "f";
    std::string trailing_double = (d - static_cast<int>(d) == 0) ? ".0" : "";
        if (isprint(d))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
        d < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << trailing_float << std::endl;
    std::cout << "double: " << d << trailing_double << std::endl;
}

static void print_error(void) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
} 

static void print_specdouble(std::string toConvert) {
    if (toConvert == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (toConvert == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

static void print_specfloat(std::string toConvert) {
    if (toConvert == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (toConvert == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string toConvert) {
    std::string _type;
    if (toConvert.empty())
        _type = "error";
    else if (toConvert.compare("nan") == 0 || toConvert.compare("-inf") == 0 || toConvert.compare("+inf") == 0)
        _type = "sdouble";
    else if (toConvert.compare("nanf") == 0 || toConvert.compare("-inff") == 0 || toConvert.compare("+inff") == 0)
        _type = "sfloat";
    else if (toConvert.find_first_not_of("+-0123456789") == std::string::npos)
        _type = "int";
    else if (toConvert.find_first_not_of("+-0123456789.") == std::string::npos)
    {
        if ((toConvert.find_first_of(".") != toConvert.find_last_of(".")) ||
            !isdigit(toConvert[0]) || !isdigit(toConvert[toConvert.find(".") + 1]))
            _type = "error";
        else
            _type = "double";
    }
    else if (toConvert.find_first_not_of("+-0123456789.f") == std::string::npos)
    {
        if (toConvert.find_first_of(".") != toConvert.find_last_of(".") ||
            toConvert.find_first_of("f") != toConvert.find_last_of("f") ||
            !isdigit(toConvert[0]) || !isdigit(toConvert[toConvert.find(".") + 1]) ||
            toConvert[toConvert.find("f") + 1] != '\0')
            _type = "error";
        else
            _type = "float";
    }
    else if (toConvert.size() == 1)
        _type = "char";
    else 
        _type = "error";


    std::string types[7] = {"char", "int", "float", "double", "error", "sdouble", "sfloat"};
    int i = 0;
    for (; i < 7; i++)
        if (_type == types[i])
            break ;

    switch (i) {
        case (0):
            print_char(toConvert);
            break ;
        case (1):
            print_int(toConvert);
            break ;
        case (2):
            print_float(toConvert);
            break ;
        case (3):
            print_double(toConvert);
            break ;
        case (4):
            print_error();
            break ;
        case (5):
            print_specdouble(toConvert);
            break ;
        case (6):
            print_specfloat(toConvert);
            break ;
        default :
            std::cout << "Default case: " << _type << std::endl;
            break ;
    }
}

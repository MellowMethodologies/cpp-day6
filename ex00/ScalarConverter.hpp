#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <string.h>
#include <iomanip>

class ScalarConverter {
private:
    ScalarConverter();
public:
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);
    static void converter(std::string);
};
#endif // ScalarConverter_HPP

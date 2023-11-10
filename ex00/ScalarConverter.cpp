#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other){ *this = other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other) {
    }
    return *this;
}

int check_char(std::string str, char c)
{
	int count = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == c)
			count++;
	}
	return count;
}

bool is_digits(std::string& str)
{
	int c = 0;
    for (size_t i = 0; i < str.length(); i++) {
		if (str[0] == '-' && c == 0)
		{
			c++;
			continue;
		}
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool is_digits_1(std::string& str)
{
	int c = 0;
    for (size_t i = 0; i < str.length(); i++) {
		if (str[0] == '-' && c == 0)
		{
			c++;
			continue;
		}
		if (i == str.length() - 1 && str[i] == 'f')
			continue;
        if (!isdigit(str[i]) &&  str[i] != '.')
            return false;
    } 
    return true;
}

void printChar(char c)
{
	if (isprint(c))
		std::cout<<"char: "<<c<<std::endl;
	else
		std::cout<<"char: "<<"Non displayable"<<std::endl;
}

void printInt(int i)
{
	std::cout<<"int: "<<i<<std::endl;
}

void printFloat(float f)
{
	std::cout<<"float: "<< std::fixed << std::setprecision(1) <<f << "f"<<std::endl;
}

void printDouble(double d)
{
	std::cout<<"double: "<< std::fixed << std::setprecision(1) <<d <<std::endl;
}

void ScalarConverter::converter(std::string a)
{
    if(a.length() == 1 && isalpha(a[0]))
	{
        printChar(a[0]);
		printInt(static_cast<int>(a[0]));
		printFloat(static_cast<float>(a[0]));
		printDouble(static_cast<double>(a[0]));
	}
	else if(is_digits(a))
	{
		float tmp = std::atof(a.c_str());
		if(tmp > INT_MAX || tmp < INT_MIN)
			std::cout<<"int: impossible"<<std::endl;
		else
			printInt(static_cast<int>(tmp));
		printChar(static_cast<char>(tmp));
		printFloat(static_cast<float>(tmp));
		printDouble(static_cast<double>(tmp));
	}
	else if (a[a.length() - 1] == 'f' && is_digits_1(a))
	{
		float tmp = std::atof(a.c_str());
		printChar(static_cast<char>(tmp));
		printInt(static_cast<int>(tmp));
		printFloat(tmp);
		printDouble(static_cast<double>(tmp));
	}
	else if (check_char(a, '.') == 1 && is_digits_1(a))
	{
		double tmp = std::atof(a.c_str());
		printChar(static_cast<char>(tmp));
		printInt(static_cast<int>(tmp));
		printFloat(static_cast<double>(tmp));
		printDouble(tmp);
	}
	else if(a == "nan" || a == "+inf" || a == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << a << "f" << std::endl;
		std::cout << "double: " << a << std::endl;
	}
	else
		std::cout<<"Error: Wrong input"<<std::endl;
}
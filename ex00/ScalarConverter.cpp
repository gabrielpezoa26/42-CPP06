/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:06:31 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/24 22:41:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ------- Canonical form -------*/
ScalarConverter::ScalarConverter()
{
	if (DEBUG)
		printDebug("ScalarConverter-> Default constructor called");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	if (DEBUG)
		printDebug("ScalarConverter-> Default destructor called");
}




/* ------- special methods -------*/
void ScalarConverter::convert(std::string to_convert)
{
	if (DEBUG)
		printDebug("ScalarConverter-> convert() method called");

	std::string input_type;
	input_type = getInputType(to_convert);
	
	convert_and_print(input_type, to_convert);
}



/* ------- "main" methods -------*/
std::string ScalarConverter::getInputType(std::string to_detect)
{
	if (DEBUG)
		printDebug("ScalarConverter-> getInputType() method called");

	std::string type;
	if (isChar(to_detect))
		type = "char";
	else if (isInteger(to_detect))
		type = "int";
	else if (isFloat(to_detect))
		type = "float";
	else if (isDouble(to_detect))
		type = "double";
	else
		type = "impossible";
	return (type);
}

void ScalarConverter::convert_and_print(std::string input_type, std::string to_convert)
{
	if (DEBUG)
		printDebug("ScalarConverter-> convert_and_print() method called");

	std::string types_array[5] = {"char", "int", "float", "double", "impossible"};
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		if (types_array[i] == input_type) 
			break;
	}
	std::cout << "DEBUG: type = " << input_type << '\n' << std::endl;
	std::cout << "DEBUG: input = " << to_convert << '\n' << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	switch(i)
	{
		case 0: handleChar(to_convert); break;
		case 1: handleInt(to_convert); break;
		case 2: handleFloat(to_convert); break;
		case 3: handleDouble(to_convert); break;
		case 4: handle_impossible(); break;
	}
}


/* ------- auxiliary methods -------*/
bool ScalarConverter::isChar(std::string str)
{
	if (DEBUG)
		printDebug("Scalar-> isChar() called");

	if (str.length() != 1 || isdigit(str[0]))
		return false;
	if (!isascii(str[0]) || !isprint(str[0]) || str[0] == 32)
		return false;
	return true;
}

// mayyyybe should refactor this
bool ScalarConverter::isInteger(std::string str)
{
	if (DEBUG)
		printDebug("Scalar-> isInteger() called");

	if (str.empty())
		return false;

	int i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str.length() == 1)
			return false;
		i++;
	}
	while (i < (int)str.length())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	errno = 0;
	long value_in_long = 0;
	value_in_long = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE)
	{
		if (DEBUG)
			printDebug("overflow detected");

		return false;
	}
	if (value_in_long > INT_MAX || value_in_long < INT_MIN)
	{
		if (DEBUG)
			printDebug("out of 'int' ranges");
		return false;
	}
	return true;
}

// also maybe should refactor this
bool ScalarConverter::isFloat(std::string str)
{
	if (DEBUG)
		printDebug("Scalar-> isFloat() called");

	if (str.empty())
		return false;

	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
	{
		log("DEBUG: float pseudo literal");
		return true;
	}
	int i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str.length() == 1)
			return false;
		i++;
	}
	int size = str.length();
	int count = 0;
	for(i = 0; i < size; i++)
	{
		if (str[i] == '+' || str[i] == '-')
			count++;
	}
	if (count > 1)
		return false;
	if (str[size - 1] != 'f')
		return false;
	count = 0;
	for(int i = 0; i < size; i++)
	{
		if (str[i] == '.' || str[i] == 'f')
			count++;
	}
	if (count != 2)
		return false;
	for (i = 0; i < size; i++)
	{
		if (isdigit(str[i]) == 0 && str[i] != '.' 
			&& str[i] != 'f' && str[i] != '+' && str[i] != '-')
		{
			log("float()-> vishhh deu ruim");
			return false;
		}
	}
	return true;
}

// also shooould refactor this
bool ScalarConverter::isDouble(std::string str)
{
	if (DEBUG)
		printDebug("Scalar-> isDouble() called");

	if (str.empty())
		return false;
	if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
	{
		log("DEBUG: double pseudo literal");
		return true;
	}
	int i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str.length() == 1)
			return false;
		i++;
	}
	int size = str.length();
	int count = 0;
	for(i = 0; i < size; i++)
	{
		if (str[i] == '+' || str[i] == '-')
			count++;
	}
	if (count > 1)
		return false;
	count = 0;
	for(int i = 0; i < size; i++)
	{
		if (str[i] == '.' || str[i] == 'f')
			count++;
	}
	if (count != 1)
		return false;
	for (i = 0; i < size; i++)
	{
		if (isdigit(str[i]) == 0 && str[i] != '.'
			&& str[i] != '+' && str[i] != '-')
		{
			log("double()-> vishhh deu ruim");
			return false;
		}
	}
	return true;
}

void ScalarConverter::handleChar(std::string to_convert)
{
	if (DEBUG)
		printDebug("handleChar() called");

	std::cout << "char: '" << to_convert << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(to_convert[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(to_convert[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(to_convert[0]) << std::endl;

}

void ScalarConverter::handleInt(std::string to_convert)
{
	if (DEBUG)
		printDebug("handleInt() called");

	int value = atoi(to_convert.c_str());
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "char: " << "impossible" << std::endl;
	if (isprint(static_cast<unsigned char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'"<< std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::handleFloat(std::string to_convert)
{
	float value = atof(to_convert.c_str());

	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<unsigned char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if(value < std::numeric_limits<int>::max() && value > std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::handleDouble(std::string to_convert)
{
	double	value = atof(to_convert.c_str());
	
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(static_cast<unsigned char>(value)))
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if(value < std::numeric_limits<int>::max() && value > std::numeric_limits<int>::min())
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (value < std::numeric_limits<float>::max() && value > -std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::handle_impossible()
{
	if (DEBUG)
		printDebug("handle_impossible() called");

	logColor("char: impossible", RED);
	logColor("int: impossible", RED);
	logColor("float: impossible", RED);
	logColor("double: impossible", RED);
}

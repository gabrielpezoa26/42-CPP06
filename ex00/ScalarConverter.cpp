/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:06:31 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/24 16:20:26 by gcesar-n         ###   ########.fr       */
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
	
	mangoloko(input_type, to_convert);
}



/* ------- auxiliary methods -------*/
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

void ScalarConverter::mangoloko(std::string input_type, std::string to_convert)
{
	if (DEBUG)
		printDebug("ScalarConverter-> mangoloko() method called");

	std::string types_array[5] = {"char", "int", "float", "double", "impossible"};
	int i = 0;
	while(i < 5)
	{
		if (types_array[i] == input_type)
			break;
		i++;
	}
	std::cout << "DEBUG: type = " << input_type << std::endl;
	switch(i)
	{
		case 0:
			handleChar(to_convert);
			break;
		case 1:
			// handleInt(to_convert);
			break;
		case 2:
			// handleFloat(to_convert);
			break;
		case 3:
			// handleDouble(to_convert);
			break;
		case 4:
			log("impossibleeeeeee");
			// handle_impossible(to_convert);
			break;
	}
}

bool ScalarConverter::isChar(std::string str)
{
	if (DEBUG)
		printDebug("Scalar-> isChar() called");

	if (str.length() != 1)
		return false;
	if(isdigit(str[0]))
		return false;
	if (!isascii(str[0]))
		return false;
	if (!isprint(str[0]) || str[0] == 32)
		return false;
	return true;
}

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

	std::cout << "char: " << to_convert << std::endl;
	std::cout << "int: " << static_cast<int>(to_convert[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(to_convert[0]) << ".0" << std::endl;
	std::cout << "double: " << static_cast<double>(to_convert[0]) << ".0" << std::endl;

}

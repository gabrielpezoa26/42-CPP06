/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:06:31 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/23 18:47:35 by gcesar-n         ###   ########.fr       */
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
	std::cout << input_type << std::endl;
	// blablabla
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
		type = "integer";
	// else if (isFloat(to_detect))
	// 	type = "float";
	// else if (isDouble(to_detect))
	// 	type = "double";
	// else
	// {
	// 	logColor("vishhhhhhhhhhhhhh", RED);
	// }
	return (type);
}

bool ScalarConverter::isChar(std::string str)
{
	if (DEBUG)
		printDebug("Scalar-> isChar() called");

	if (str.length() != 1)
		return false;
	if(isdigit(str[0]))
		return false;
	if (!isprint(str[0]))
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
	error_number = 0;
	long value_in_long = 0;
	value_in_long = std::strtol(str.c_str(), NULL, 10);
	if (error_number == ERANGE)
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

	std::cout << "DEBUG" << str << std::endl; //apagar dps
	return true;
}

// bool ScalarConverter::isDouble(std::string str)
// {
// 	if (DEBUG)
// 		printDebug("Scalar-> isDouble() called");
// }



/* ------- Global Methods -------*/
void log(std::string message)
{
	std::cout << message << std::endl;
}

void logColor(std::string message, std::string color)
{
	std::cout << color << message << RESET << std::endl;
}

void printDebug(std::string debug_message)
{
	std::cout << PURPLE << debug_message << RESET << std::endl;
}


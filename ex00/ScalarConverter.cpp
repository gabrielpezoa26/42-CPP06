/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:06:31 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/22 16:35:23 by gcesar-n         ###   ########.fr       */
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

std::string ScalarConverter::getInputType(std::string to_detect)
{
	if (DEBUG)
		printDebug("ScalarConverter-> getInputType() method called");


	std::string type;
	if (isChar(to_detect))
		type = "char";
	// else if (isInteger(to_detect))
	// 	type = "integer";
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



/* ------- auxiliary methods -------*/
bool ScalarConverter::isChar(std::string str)
{
	if (isalpha(str[1]) == 0)
		return true;
	else
		return false;
}

// bool ScalarConverter::isInteger(std::string str)
// {
// 	if (isdigit(str[1]) == 0)
// 		return true;
// 	else
// 		return true;
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


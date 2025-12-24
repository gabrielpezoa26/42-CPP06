/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:03:39 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/23 23:47:58 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DEBUG false

#include <iostream>
#include <stdlib.h>
#include <cerrno>
#include <limits.h>

class ScalarConverter
{
	private:
		/* ------- auxiliary methods -------*/
		static std::string getInputType(std::string to_detect);
		static bool isChar(std::string str);
		static bool isInteger(std::string str);
		static bool isFloat(std::string str);
		static bool isDouble(std::string str);


		/* ------- Canonical form -------*/
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();



	public:
		/* ------- special method -------*/
		static void convert(std::string to_convert);
};

/* ------- Global Methods -------*/
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string debug_message);

#endif
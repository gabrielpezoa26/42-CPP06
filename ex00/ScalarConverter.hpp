/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:03:39 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/24 22:23:34 by gcesar-n         ###   ########.fr       */
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
#include <limits>
#include <limits.h>
#include <iomanip>
#include "utils.hpp"

class ScalarConverter
{
	private:
		/* ------- Canonical form -------*/
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();


		/* ------- "main" methods -------*/
		static std::string getInputType(std::string to_detect);
		static void convert_and_print(std::string input_type, std::string to_convert);


		/* ------- get-type methods -------*/
		static bool isChar(std::string str);
		static bool isInteger(std::string str);
		static bool isFloat(std::string str);
		static bool isDouble(std::string str);


		/* ------- conversion methods -------*/
		static void handleChar(std::string to_convert);
		static void handleInt(std::string to_convert);
		static void handleFloat(std::string to_convert);
		static void handleDouble(std::string to_convert);
		static void handle_pseudos(std::string to_convert);
		static void handle_impossible();


	public:
		/* ------- special method -------*/
		static void convert(std::string to_convert);
};

#endif
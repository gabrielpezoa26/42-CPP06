/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:03:39 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/19 20:22:48 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#define DEBUG false

class ScalarConverter
{
	private:


	public:
		/* ------- Canonical form -------*/
		ScalarConverter();
		~ScalarConverter();

	
};

/* ------- Global Methods -------*/
void log(std::string message);
void logColor(std::string message, std::string color);
void printDebug(std::string debug_message);

#endif
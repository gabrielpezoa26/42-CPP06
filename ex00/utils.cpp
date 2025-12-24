/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:42:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/24 11:11:47 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ------- global methods -------*/
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
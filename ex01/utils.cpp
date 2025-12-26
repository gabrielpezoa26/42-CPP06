/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 05:41:10 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 05:43:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void log(std::string message)
{
	std::cout << message << std::endl;
}

void printDebug(std::string message)
{
	std::cout << PURPLE << message << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:27 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 00:00:57 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	if (DEBUG)
		logDebug("Serializer-> Default constructor called");
}

Serializer::Serializer(const Serializer& s)
{
	if (DEBUG)
		logDebug("Serializer-> Copy constructor called");
	(void)s;
}

Serializer &Serializer::operator=(const Serializer& s)
{
	(void)s;
	return(*this);
}

Serializer::~Serializer()
{
	if (DEBUG)
		logDebug("Serializer-> Default destructor called");
}

void log(std::string message)
{
	std::cout << message << std::endl;
}

void logDebug(std::string message)
{
	std::cout << PURPLE << message << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:27 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 06:13:59 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "utils.hpp"

Serializer::Serializer()
{
	if (DEBUG)
		printDebug("Serializer-> Default constructor called");
}

Serializer::Serializer(const Serializer& s)
{
	if (DEBUG)
		printDebug("Serializer-> Copy constructor called");
	(void)s;
}

// Serializer &Serializer::operator=(const Serializer& s)
// {
// 	(void)s;
// 	return(*this);
// }

Serializer::~Serializer()
{
	if (DEBUG)
		printDebug("Serializer-> Default destructor called");
}

/*------- special methods ------- */
// uintptr_t Serializer::serialize(Data* ptr)
// {
// 	if (DEBUG)
// 		printDebug("serialize() method called");
// }

// Data* Serializer::deserialize(uintptr_t raw)
// {
// 	if (DEBUG)
// 		printDebug("deserialize() method called");
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:27 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 10:42:12 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "utils.hpp"

Serializer::Serializer()
{
	if (DEBUG)
		printDebug("Serializer-> Default constructor called");
}

Serializer::Serializer(const Serializer& x)
{
	if (DEBUG)
		printDebug("Serializer-> Copy constructor called");
	(void)x;
}

Serializer& Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer()
{
	if (DEBUG)
		printDebug("Serializer-> Default destructor called");
}


/*------- special methods ------- */
uintptr_t Serializer::serialize(Data *ptr)
{
	if (DEBUG)
		printDebug("serialize() called");
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	if (DEBUG)
		printDebug("deserialize() called");
	Data* ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}

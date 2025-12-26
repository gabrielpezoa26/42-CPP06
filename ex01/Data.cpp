/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:47 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 06:14:58 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include "utils.hpp"

Data::Data(const std::string given_name, long int given_aura)
 : name(given_name), aura(given_aura)
{
	if (DEBUG)
		printDebug("Data-> Default constructor called");
}

Data::Data(const Data &other) : name(other.name), aura(other.aura)
{
	if (DEBUG)
		printDebug("Data-> Copy constructor called");
}

Data &Data::operator=(const Data &other)
{
	if (&other != this)
		aura = other.aura;
	return (*this);
}

Data::~Data()
{
	if (DEBUG)
		printDebug("Data-> Default destructor called");
}

/* ------- getters ------- */
const std::string Data::getName() const
{
	return name;
}

long int	Data::getAura(void) const
{
	return aura;
}
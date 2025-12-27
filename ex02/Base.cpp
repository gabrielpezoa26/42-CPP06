/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:49:32 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/27 18:32:42 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	if (DEBUG)
		log("Base-> Destructor called");
}

Base* generate(void)
{
	Base* result = NULL;

	if(DEBUG)
		log("generate() called");
	return result;
}

// void identify(Base* p)
// {
// 	if(DEBUG)
// 		log("identify1() called");
// }

// void identify(Base& p)
// {
// 	if(DEBUG)
// 		log("generate2() called");
// }

void log(std::string message)
{
	std::cout << message << std::endl;
}

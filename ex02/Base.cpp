/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:49:32 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/27 19:35:10 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	if (DEBUG)
		log("Base-> Destructor called");
}

Base* generate(void)
{
	if(DEBUG)
		log("generate() called");

	Base* instance = NULL;
	static bool seed_flag = false;

	if (!seed_flag)
	{
		srand(time(NULL));
		seed_flag = true;
	}
	int random_value = rand() % 3;
	if (random_value == 0)
		A instance;
	else if (random_value == 1)
		B instance;
	else if (random_value == 2)
		C instance;
	return instance;
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

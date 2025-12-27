/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:51:02 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/27 19:01:30 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#define DEBUG true

class Base
{
	public:
		virtual ~Base();
};


Base* generate(void);
// void identify(Base* p);
// void identify(Base& p);

void log(std::string message);

#endif
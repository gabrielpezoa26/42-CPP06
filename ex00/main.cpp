/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:03:35 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/24 17:28:12 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <stdio.h>

int main(int ac, char **av)
{
	printf("%d\n", ac);
	if (ac != 2)
	{
		logColor("Error! Invalid argument count :((", RED);
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}


/*
	Write a program to test that your class works as expected.
	You have to first detect the type of the literal passed as a parameter, convert it from
	string to its actual type, then convert it explicitly to the three other data types. Lastly,
	display the results as shown below.
	If a conversion does not make any sense or overflows, display a message to inform
	the user that the type conversion is impossible. Include any header you need in order to
	handle numeric limits and special values.
*/
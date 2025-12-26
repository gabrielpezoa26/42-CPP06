/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 10:39:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include "utils.hpp"

int main()
{
	Data example("beta", 1);
	Data example2("alfa", 999999999);

	std::cout << "name = " << example.getName() << std::endl;
	std::cout << "aura = " << example.getAura() << std::endl << std::endl;

	std::cout << "name = " << example2.getName() << std::endl;
	std::cout << "aura = " << example2.getAura() << std::endl;

	return 0;
}

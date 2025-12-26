/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 10:47:45 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include "utils.hpp"

int main(void)
{
	Data* pointer = new Data("Bob", 42);

	uintptr_t adress_value = Serializer::serialize(pointer);
	Data* new_pointer = Serializer::deserialize(adress_value);

	std::cout << "Original Address: " << pointer << std::endl;
	
	std::cout << "Serialized (Hex): 0x" << std::hex << adress_value << std::dec << std::endl;
	std::cout << "Deserialized Address: " << new_pointer << std::endl;

	if (pointer == new_pointer)
		log("Sucess: both pointers are identical");
	else
		log("Error: pointers differ");
	delete pointer;
	return 0;
}

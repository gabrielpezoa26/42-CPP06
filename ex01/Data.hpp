/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:02:42 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 06:06:13 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		const std::string name;
		long int aura;



	public:
		Data(const std::string given_name, long int given_aura);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();


		/* ------- getters ------- */
		const std::string getName() const;
		long int getAura(void) const;


};

#endif
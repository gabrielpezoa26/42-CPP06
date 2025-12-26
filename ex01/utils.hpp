/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 05:41:45 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/12/26 05:53:28 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

#include <iostream>
#define DEBUG true
void log(std::string message);
void printDebug(std::string message);

#endif
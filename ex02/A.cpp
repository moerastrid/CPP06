/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:50:57 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 17:15:43 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A() {
	std::cout << "\033[1;34m" << "AAAAAAAAAAA" << "\033[0m" << std::endl;
}

A::~A() {
	std::cout << "\033[1;34m" << "~A" << "\033[0m" << std::endl;
}
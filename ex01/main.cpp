/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 15:01:14 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 16:42:04 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialization.hpp"

int main() {
	Data Josh;
	Data *Sean;
	Josh.name = "Josh";
	Josh.age = 36;
	uintptr_t ptr;

	std::cout << "Josh address : " << &Josh << std::endl;
	ptr = Serializer::serialize(&Josh);
	Sean = Serializer::deserialize(ptr);
	std::cout << "Sean address : " << Sean << " \nSean age : " << Sean->age << std::endl;
}

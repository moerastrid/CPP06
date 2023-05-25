/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialization.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:13:25 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 16:39:45 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &src) {
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src) {
	(void)src;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t returnptr = reinterpret_cast<uintptr_t>(ptr);
	return (returnptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* returndata = reinterpret_cast<Data*>(raw); 
	return (returndata);
}
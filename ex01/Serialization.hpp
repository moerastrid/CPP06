/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialization.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:01:06 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 16:43:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <string>
#include "Data.hpp"

class Serializer {
	private :
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
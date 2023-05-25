/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:37:14 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 14:59:24 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class 	ScalarConverter {
	private :
		explicit ScalarConverter();
		~ScalarConverter();
		explicit ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

	public :
		
		static void	convert(const std::string input);
};

void	errorMessage(std::string str);

#endif

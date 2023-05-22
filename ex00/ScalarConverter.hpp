/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:37:14 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/22 17:56:13 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

enum Type {
	typeError,
	typeInt,
	typeChar,
	typeFloat,
	typeDouble
};

class 	ScalarConverter {
	private :
		explicit ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);

		static Type		getType(const std::string input);

		static float	getFloat(char c);
		static float	getFloat(int i);
		static float	getFloat(double d);
		
	public :
		
		static void	convert(const std::string input);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:23:30 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/22 18:16:49 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

Type	ScalarConverter::getType(const std::string input) {
	if (std::isalpha(input[0]) == true && input.length() == 1)
		return typeChar;
	else if (input.find('f') == input.length() - 1) {
		const char	*temp = input.c_str();
		if (input.compare("0.0f") == 0 || std::atof(temp) != 0.0f)
			return typeFloat;
	}
	
	return typeError;
}

void	ScalarConverter::convert(const std::string input) {
	std::cout << input << std::endl;

	for (int i(0); input[i] != '\0'; i++) {
		if (std::isprint(input[i]) == false) {
			std::cerr << "invalid input, non-displayable characters should not be used as input" << std::endl;
			return ;
		}
	}
	
	int this_type = ScalarConverter::getType(input);
	std::cout << "type : " << this_type << std::endl;
	char c = 0;
	int i = 0;
	double d = 0.01;
	float f = 0.0f;
	switch (this_type)
	{
		case (typeChar):
			c = input[0];
			i = static_cast<const int>(c);
			d = static_cast<const double>(c);
			f = static_cast<const float>(c);
			break ;
			
		//case typeInt:
		case typeFloat:
			f = std::atof(input.c_str());
			c = static_cast<const char>(f);
			i = static_cast<const int>(c);
			d = static_cast<const double>(c);
			break ;
			
		case typeError:
			std::cout << "No scalar type :(" << std::endl;
	}
	
	if (std::isprint(c)) {
		std::cout << "char : " << c << std::endl;
	} else {
		std::cout << "char : invalid" << std::endl;
	}
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << f << std::endl;
	std::cout << "double : " << d << std::endl;

	return ;
}

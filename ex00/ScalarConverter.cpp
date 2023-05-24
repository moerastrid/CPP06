/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:23:30 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/24 21:27:08 by astrid        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum Type {
	typeError,
	typeInt,
	typeChar,
	typeFloat,
	typeDouble
};

// default constructor
ScalarConverter::ScalarConverter() {}

// default destructor
ScalarConverter::~ScalarConverter() {}

// '=' sign operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return (*this);
}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

// counting the dots (.)
unsigned int	countDot(const std::string input) {
	unsigned int	dotCount = 0;
	
	for (int i(0); input[i]; i++) {
		if (input[i] == '.') {
			dotCount++;
		}
	}
	return (dotCount);
}

// type identification
Type	identifyType(const std::string input) {
	const char	*temp = input.c_str();
	std::cout << "Dotcount : " << countDot(input) << std::endl;
	if (std::isalpha(input[0]) == true && input.length() == 1)
		return typeChar;
	else if ((input.find('f') == input.length() - 1) && countDot(input) <= 1) {
		if (input.compare("0f") == 0 || input.compare("0.0f") == 0 || std::atof(temp) != 0.0f)
			return typeFloat;
	}
	else if (countDot(input) == 0) {
		if (input.compare("0") == 0 || std::atoi(temp) != 0)
			return typeInt;
	}
	else if (countDot(input) == 1) {
		if (input.compare("0.0") == 0 || std::atof(temp) != 0)
			return typeDouble;
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
	
	int this_type = identifyType(input);
	std::cout << "type : " << this_type << std::endl;
	char c = 0;
	int i = 0;
	double d = 0.0;
	float f = 0.0f;
	switch (this_type)
	{
		case typeChar:
			c = input[0];
			i = static_cast<const int>(c);
			d = static_cast<const double>(c);
			f = static_cast<const float>(c);
			break ;
			
		case typeInt:
			i = std::atoi(input.c_str());
			c = static_cast<const char>(i);
			d = static_cast<const double>(i);
			f = static_cast<const float>(i);
			break ;

		case typeFloat:
			f = std::atof(input.c_str());
			c = static_cast<const char>(f);
			i = static_cast<const int>(f);
			d = static_cast<const double>(f);
			break ;
		
		case typeDouble:
			d = std::atof(input.c_str());
			c = static_cast<const char>(d);
			i = static_cast<const int>(d);
			f = static_cast<const float>(d);
			break ;
			
		case typeError:
			std::cout << "No scalar type :(" << std::endl;
			return ;
	}
	
	if (std::isprint(c)) {
		std::cout << "char : " << c << std::endl;
	} else {
		std::cout << "char : invalid" << std::endl;
	}
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << (float)f << 'f' << std::endl;
	std::cout << "double : " << (double)d << std::endl;

	return ;
}

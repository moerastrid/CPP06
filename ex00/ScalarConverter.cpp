/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 14:23:30 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 14:59:43 by ageels        ########   odam.nl         */
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

// pseudo literals
bool	pseudoLiterals(const std::string input) {
	std::string		pseudos[] = {"-inff", "+inff", "inff", "nanf", "-inf", "+inf", "inf", "nan"};
	int	n(-1);

	double d(0.0);
	float f(0.0f);

	for (int i(0); i < 8; i++) {
		if (input.compare(pseudos[i]) == 0)
			n = i;
	}
	//std::cout << "Type = pseudo : " << pseudos[n] << std::endl;

	switch (n) {
		case -1 : 
			return false;

		case 0 :
			f = -std::numeric_limits<float>::infinity();
			d = static_cast<const double>(f);
			break ;

		case 1 :
		case 2 :
			f = std::numeric_limits<float>::infinity();
			d = static_cast<const double>(f);
			break ;

		case 3 :
			f = std::numeric_limits<float>::signaling_NaN();
			d = static_cast<const double>(f);
			break ;

		case 4 :
			d = -std::numeric_limits<double>::infinity();
			f = static_cast<const float>(d);
			break ;

		case 5 :
		case 6 :
			d = std::numeric_limits<double>::infinity();
			f = static_cast<const float>(d);
			break ;

		case 7 :
			d = std::numeric_limits<double>::signaling_NaN();
			f = static_cast<const float>(d);
			break ;
	}
	
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << f << 'f' << std::endl;
	std::cout << "double : " << d << std::endl;
	return true;
}

// type identification
Type	identifyType(const std::string input, unsigned int *dotCount) {
	const char	*temp = input.c_str();

	// char
	if (std::isalpha(input[0]) == true && input.length() == 1)
		return typeChar;

	// error & count dots
	unsigned int i(0);
	while (input[i]) {
		if (input[i] == '+' || input[i] == '-')
			i++;
		else
			break ;
	}
	while (input [i]) {
		if (isdigit(input[i]) == false && input[i] != 'f' && input[i] != '.')
			return typeError;
		else if (input[i] == '.') 
			(*dotCount)++;
		i++;
	}
	//std::cout << "Dotcount : " << *dotCount << std::endl;
	
	// numbers: float, int & double
	if ((input.find('f') == input.length() - 1) && *dotCount <= 1) {
		if (input.compare("0f") == 0 || input.compare("0.0f") == 0 || std::atof(temp) != 0.0f)
			return typeFloat;
	}
	else if (*dotCount == 0) {
		if ((input.find('f') == std::string::npos) && (input.compare("0") == 0 || std::atoi(temp) != 0))
			return typeInt;
	}
	else if (*dotCount == 1) {
		if (input.compare("0.0") == 0 || std::atof(temp) != 0)
			return typeDouble;
	}
	return typeError;
}

// convert
void	ScalarConverter::convert(const std::string input) {
	unsigned int	dotCount = 0;

	// print input (for debugging)
	//std::cout << "input: " << input << std::endl;

	//check if input is printable
	for (int i(0); input[i] != '\0'; i++) {
		if (std::isprint(input[i]) == false) {
			errorMessage("invalid input, please only use displayable characters as input");
			return ;
		}
	}

	// check if input is pseudo literals
	if (pseudoLiterals(input) == true)
		return ;
	
	// identify type (& print for debugging)
	std::string typeNames[] = {"error", "int", "char", "float", "double"};
	int this_type = identifyType(input, &dotCount);
	//std::cout << "type : " << typeNames[this_type] << std::endl;
	
	//the different values 
	char c(0);
	int i(0);
	double d(0.0);
	float f(0.0f);

	//set the type it is, explicitely cast to the other values
	switch (this_type) {
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
			errorMessage("invalid input, please only use scalar types as input");
			return ;
	}
	
	// display the values
	if (std::isprint(c) && i >= 33 && i <= 126) {
		std::cout << "char : " << c << std::endl;
	} else {
		std::cout << "char : invalid" << std::endl;
	}
	std::cout << "int : " << i << std::endl;
	
	if (dotCount == 1) {
		std::cout << "float : " << (float)f << 'f' << std::endl;
		std::cout << "double : " << (double)d << std::endl;
	} else if (dotCount == 0) {
		std::cout << "float : " << (float)f << ".0f" << std::endl;
		std::cout << "double : " << (double)d << ".0" << std::endl;
	}

	return ;
}

void	errorMessage(std::string	str) {
	std::cerr << "\033[1;31m" << "Error - " << str << "\033[0m" << std::endl;
}

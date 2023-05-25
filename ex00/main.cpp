/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:12:10 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 12:47:54 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		errorMessage("invalid input, please pass at least 1 literal as parameter");
		return (-1);
	}
	for (int i(1); argv[i]; i++) {
		std::cout << "\033[1;34m" << "\nStart conversion " << i << " ... " << "\033[0m" << std::endl;
		ScalarConverter::convert(argv[i]);
	}
}

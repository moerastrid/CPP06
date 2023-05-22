/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:12:10 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/22 18:05:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else {
		std::cerr << "invalid input, please pass 1 literal as parameter" << std::endl;
		return (-1);
	}
}

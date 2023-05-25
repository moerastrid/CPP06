/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:19:52 by ageels        #+#    #+#                 */
/*   Updated: 2023/05/25 18:10:33 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	Base * abc[10];
	for (int i(0); i < 10; i ++) {
		abc[i] = generate();
	}
	for (int i(0); i < 10; i ++) {
		identify(abc[i]);
	}
	for (int i(0); i < 10; i ++) {
		identify(*abc[i]);
	}
	for (int i(0); i < 10; i ++) {
		delete(abc[i]);
	}
}

Base * generate(void) {
	uint32_t  n = arc4random() % 3;
	Base * ptr;
	switch (n) {
		case 0:
			ptr = new A;
			break;

		case 1:
			ptr = new B;
			break;

		case 2:
			ptr = new C;
			break;
	}
	return (ptr);
}

// cast -> check for NULL
void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "\033[1;32m" << "identified A!" << "\033[0m" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "\033[1;32m" << "identified B!" << "\033[0m" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "\033[1;32m" << "identified C!" << "\033[0m" << std::endl;
}

// a reference of an address can't be NULL, try/catch block instead
void identify(Base& p) {
	try {
		A &test = dynamic_cast <A &>(p);
		(void)test;
	}
	catch (const std::bad_cast& e) {
		try {
			B &test = dynamic_cast <B &>(p);
			(void)test;
		}
		catch (const std::bad_cast& e) {
			std::cout << "\033[1;33m" << "identified C!" << "\033[0m" << std::endl;
			return ;
		}
		std::cout << "\033[1;33m" << "identified B!" << "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;33m" << "identified A!" << "\033[0m" << std::endl;
}
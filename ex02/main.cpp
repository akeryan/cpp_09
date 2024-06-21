/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 08:30:44 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pme;
	
	for(int i = 1; i < argc; i++) {
		int value;
		std::istringstream iss(argv[i]);
		if (iss >> value) {
			pme.pushDeque(value);
			pme.pushList(value);
		} else
			std::cout << "Error: wrong input" << std::endl;
	}
	try {
		pme.sort();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
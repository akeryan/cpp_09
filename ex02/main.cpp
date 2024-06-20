/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/20 14:26:40 by akeryan          ###   ########.fr       */
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
		if (iss >> value)
			pme.pushDeque(value);
		else
			std::cout << "Error: wrong input" << std::endl;
	}
	pme.printDeque(pme.getD());
	std::cout << "---------------" << std::endl;
	pme.pairSort();
	pme.printDeque(pme.getD());
	std::cout << "---------------" << std::endl;
	pme.merge();
	return 0;
}
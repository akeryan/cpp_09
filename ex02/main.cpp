/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:34:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 09:21:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pme;
	
	try {
		for(int i = 1; i < argc; i++) {
			int value;
			std::istringstream iss(argv[i]);
			if (iss >> value) {
				pme.push(value);
			} else
				throw (std::runtime_error("Error: wrong input"));
		}
		pme.sort();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
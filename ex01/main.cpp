/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:19 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 16:25:00 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc !=2) {
		std::cout << "Error: should take a single string_argument" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.readString(argv[1]);
	try {
		std::cout << rpn.rpnEval() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
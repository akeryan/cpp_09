/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:19 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/19 11:20:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(void) 
{
	std::string str = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	RPN rpn;

	try {
		rpn.readString(str);
		rpn.print();
		std::cout << "result: " << rpn.compute() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
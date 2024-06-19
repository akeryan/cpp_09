/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:19 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/19 13:07:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc !=2) {
		std::cout << "Error: should take only one string argument";
		return 1;
	}
	RPN rpn;
	rpn.readString(argv[1]);
	rpn.compute();
	return 0;
}
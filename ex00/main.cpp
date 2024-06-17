/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:33:19 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/17 18:02:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: incorrect number of arguments" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc(argv[1]);
		btc.print();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
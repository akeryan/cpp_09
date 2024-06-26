/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:33:19 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/18 14:47:18 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: couldn't open file" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc;
		btc.importDB("data.csv", ".csv");
		btc.exchange(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
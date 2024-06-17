/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:33:47 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/17 18:21:20 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <sys/stat.h>
# include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange(const std::string &filePath);
		const BitcoinExchange &operator=(const BitcoinExchange &other);

		void importDB(const std::string &filePath);
		void print(void) ;
	private:
		void openFile(std::ifstream &infile, const std::string &inFileName);
		std::map<std::string, float> _db;
};

#endif
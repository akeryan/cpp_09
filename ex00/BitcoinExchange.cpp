/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:59:05 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/17 17:54:32 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::~BitcoinExchange() { }

const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		this->_db = other._db;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &filePath)
{
	importDB(filePath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (this != &other) {
		*this = other;
	}
}

void BitcoinExchange::openFile(std::ifstream &infile, const std::string &inFileName)
{
	struct stat fileInfo;	

	if (stat(inFileName.c_str(), &fileInfo) != 0) {
		throw (std::runtime_error("ERROR: Failed to get file information"));
    }
	// Check if the passed file is a folder..
	if (S_ISREG(fileInfo.st_mode) == false) {
		throw (std::runtime_error("ERROR: The file seems to be a folder..."));
	}

	infile.open(inFileName.c_str(), std::ifstream::in);
	// Check if file opened successfully
	if (!infile.is_open()) {
		throw (std::runtime_error("ERROR: Failed to open the file for reading"));
	}
	// Check if the file is readable
	if (!infile.good()) {
		throw (std::runtime_error("ERROR: Failed reading file"));
	}
}

void BitcoinExchange::importDB(const std::string &filePath)
{
	std::ifstream		inData;
	std::string			line;

	try {
		openFile(inData, filePath);
		while (std::getline(inData, line)) {
			float	fvalue;
			size_t pos = line.find(",");
			std::string keyStr = line.substr(0, pos);
			std::string valueStr = line.substr(pos);
			std::stringstream	ss(valueStr);
			ss >> fvalue;
			this->_db[keyStr] = fvalue;
		}
	} catch (std::exception &e) {
		throw ;
	}
}

void BitcoinExchange::print(void) {
	std::map<std::string, float>::iterator it;
	for ( it = this->_db.begin(); it != _db.end(); ++it) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
}


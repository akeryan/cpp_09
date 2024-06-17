/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:59:05 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/17 19:22:44 by akeryan          ###   ########.fr       */
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

void BitcoinExchange::openFile(std::ifstream &infile, const std::string &inFileName) const
{
	struct stat fileInfo;	

	if (inFileName.substr(inFileName.length() - 4) != ".csv") {
		throw (std::runtime_error("ERROR: Wrong file format, must be '.csv'"));
	}
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
		std::getline(inData, line);
		while (std::getline(inData, line)) {
			float	fvalue;
			size_t pos = line.find(",");
			std::string key = line.substr(0, pos);
			std::string valueStr = line.substr(pos + 1);
			std::stringstream	ss(valueStr);
			ss >> fvalue;
			this->_db[key] = fvalue;
		}
	} catch (std::exception &e) {
		throw ;
	}
}

void BitcoinExchange::print(void) const {
	std::map<std::string, float>::const_iterator it;
	std::cout << std::fixed << std::setprecision(2);
	for (it = this->_db.begin(); it != _db.end(); ++it) {
		std::cout << it->first << " -> " << it->second << std::endl;
	}
}

void BitcoinExchange::exchange(const std::string &filePath) const
{
	std::ifstream	inData;
	std::string		line;

	try {
		openFile(inData, filePath);
		std::getline(inData, line);
		while (std::getline(inData, line)) {
			float value;
			size_t pos = line.find(" | ");
			std::string key = line.substr(0, pos);
			std::string valueStr = line.substr(pos + 3);
			std::stringstream ss(valueStr);
			ss >> value;
			std::map<std::string, float>::const_iterator it = _db.find(key);
			if (it != _db.end()) {
				std::cout << it->first << " => " << value << " = " << it->second * value << std::endl;
			}
		}
	} catch (std::exception &e) {
		throw ;
	}
}



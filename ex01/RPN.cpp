/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/18 19:38:23 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::~RPN() { }

const RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {
		this->_expr = other._expr;
	}
	return *this;
}

RPN::RPN(const RPN &other)
{
	if (this != &other) {
		*this = other;
	}
}

void RPN::readString(const std::string &str)
{
	std::istringstream iss(str);
	char a;
	while (iss >> a) {
		_expr.push(a);
	}
}

void RPN::print(void) const 
{
	std::queue<char> tmp = _expr;
	while (!tmp.empty()) {
		std::cout << tmp.front() << std::endl;
		tmp.pop();
	}
}

void RPN::process(void) const
{
	std::queue<char> tmp = _expr;
	float result = 0.0f;
	int a;
	int b;
	char x;
	if (!tmp.empty()) {
		char ch = tmp.front();
		if (ch < '0' || ch > '9')
			throw(std::runtime_error("Error: element is not a digit"));
		a = ch - '0';
		tmp.pop();
	} else {
		throw(std::runtime_error("Error: RPN is of wrong format"));
	}
	result = a;
	if (!tmp.empty()) {
		char ch = tmp.front();
		if (ch < '0' || ch > '9')
			throw(std::runtime_error("Error: element is not a digit"));
		b = ch - '0';
		tmp.pop();
	} else {
		throw(std::runtime_error("Error: RPN is of wrong format"));
	}
	if (!tmp.empty()) {
		x = tmp.front();
		switch (x) {
			case 42:
				result = result * b;
				break ;
			case 47:
				result = result / b;
				break ;
			case 43:
				result = result + b;
				break;
			case 45:
				result = result - b;
				break;
			default:
				throw (std::runtime_error("Error: couldn't find correct operation (*, /, +, -)"));
		}
	} else {
		throw(std::runtime_error("Error: RPN is of wrong format"));
	}
	std::cout << "result: " << result << std::endl;
}
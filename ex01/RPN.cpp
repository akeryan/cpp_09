/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/19 11:18:58by akeryan          ###   ########.fr       */
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

float RPN::compute(void) const
{
	std::queue<char> que = _expr;
	float result = 0.0f;

	if (!que.empty()) {
		char ch = que.front();
		if (ch < '0' || ch > '9')
			throw(std::runtime_error("Error: element is not a digit"));
		result = ch - '0';
		que.pop();
	} else return 0.0f;
	_run(result, que);
	return result;
}

void RPN::_run(float &result, std::queue<char> &que) const
{
	int a;
	char x;

	if (!que.empty()) {
		char ch = que.front();
		if (ch < '0' || ch > '9')
			throw(std::runtime_error("Error: element is not a digit"));
		a = ch - '0';
		que.pop();
	} else {
		return ;
	}
	if (!que.empty()) {
		x = que.front();
		que.pop();
		if (x == '*')
			result = result * a;
		else if (x == '/')
			result = result / a;
		else if (x == '+')
			result = result + a;
		else if (x == '-')
			result = result - a;
		else
			throw (std::runtime_error("Error: couldn't find correct operation (*, /, +, -)"));
	} else {
		result = 0.0f;
		std::cerr << "Error: expression is in wrong format" << std::endl;
	}
	_run(result, que);	
}
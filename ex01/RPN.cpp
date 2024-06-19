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

void RPN::compute(void) const
{
	std::queue<char> que = _expr;
	float result = 0.0f;

	if (!que.empty()) {
		char ch = que.front();
		if (ch < '0' || ch > '9') {
			std::cout << "Error" << std::endl;
			return ;
		}
		result = ch - '0';
		que.pop();
	} else {
		std::cout << 0 << std::endl;
		return ;
	};
	if (_run(result, que) == -1) {
		return ;
	}
	std::cout << result << std::endl;
}

int RPN::_run(float &result, std::queue<char> &que) const
{
	int a;
	char x;

	if (!que.empty()) {
		char ch = que.front();
		if (ch < '0' || ch > '9') {
			if (ch == '(' || ch == ')') {
				std::cout << "Error" << std::endl;
				return -1;
			}
			result = 0.0f ;
			return 0;
		}
		a = ch - '0';
		que.pop();
	} else {
		return 0;
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
		else if (x == '(' || x == ')') {
				std::cout << "Error" << std::endl;
				return -1;
		} else { 
			result = 0.0f;
			return 0;
		}
	} else {
		result = 0.0f;
		return 0;
	}
	if (_run(result, que) == -1)	
		return -1;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/18 18:08:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::~RPN() { }

const RPN &RPN::operator=(const RPN &other)
{
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

RPN::RPN(const RPN &other)
{
	if (this != &other) {
		*this = other;
	}
}
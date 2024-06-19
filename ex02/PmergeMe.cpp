/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:46 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/19 19:26:33 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

const PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->D = other.D;
		this->_lst = other._lst;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) {
		*this = other;
	}
}

void PmergeMe::insertionSort(void) {
	for (std::deque<int>::iterator it1 = D.begin() + 1; it1 != D.end(); ++it1) {
		std::deque<int>::iterator it2 = it1;
		while (it2 != D.begin() && *(it2 - 1) > *it2) {
			int tmp = *(it2 - 1);
			*(it2 - 1) = *it2;
			*it2 = tmp;
			--it2;
		}
	}
}

void PmergeMe::pairSort(void) {
	std::deque<int>::iterator it = D.begin();
	while (D.end() - it >= 2) {
		if (*it > *(it + 1)) {
			int tmp = *it++;
			*(it - 1) = *it;
			*(it++) = tmp;
		}		
	}
}

void PmergeMe::printDeque(void) const {
	for (std::deque<int>::const_iterator it = D.begin(); it != D.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

void PmergeMe::pushDeque(int a) {
	D.push_back(a);
}
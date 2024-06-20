/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:46 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/20 18:27:10 by akeryan          ###   ########.fr       */
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

void PmergeMe::pushDeque(int a) { D.push_back(a); }

const std::deque<int> &PmergeMe::getD(void) const {
	return D;
}

void PmergeMe::advance(std::deque<int> &d, std::deque<int>::iterator &it, unsigned int steps) const {
	while (steps-- > 0 && it != d.end())
		it++;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) 
		*this = other;
}

void PmergeMe::sort(void) {
	pairSort();
	mergeSort();
}

void PmergeMe::pairSort(void) {
	std::deque<int>::iterator it = D.begin();
	while (D.end() - it >= 2) {
		if (*it > *(it + 1)) {
			int tmp = *it;
			*it = *(it + 1);
			*(it + 1) = tmp;
		} 
		advance(D, it, 2);
	}
}

void PmergeMe::printDeque(const std::deque<int> &d) const {
	if (d.empty())
		return ;
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergeSort(void) {
	if (D.empty()) 
		throw (std::runtime_error("Error: container is empty"));
	std::deque<int> S = D; //source
	long K = 2;
	while (K < (long)S.size())  {
		std::deque<int> d;
		std::deque<int>::iterator it1, it2;
		it1 = it2 = S.begin();
		do {
			advance(S, it2, K);
			int i1 = (S.end() - it1 >= K) ? K : S.end() - it1;
			int i2 = (S.end() - it2 >= K) ? K : S.end() - it2;
			while (i1 > 0 || i2 > 0) {
				if (i1 == 0 && it2 != S.end())	{
					d.push_back(*it2++);
					i2--;
				} else if (i2 == 0 && it1 != S.end()) {
					d.push_back(*it1++);
					i1--;
				} else if (it1 != S.end() && it2 != S.end()) {
					if (*it1 < *it2) {
						d.push_back(*it1++);
						i1--;
					} else {
						d.push_back(*it2++);
						i2--;
					}
				} else {
					while (it1 != S.end() && i1-- > 0)
						d.push_back(*it1++);
					while (it2 != S.end() && i2-- > 0)
						d.push_back(*it2++);
				}
			}
			advance(S, it1, K);
			it2 = it1;
		} while (it1 != S.end() && it2 != S.end());
		S = d;
		K *= 2;
	}
	D = S;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:46 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 08:28:36 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

const PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->D = other.D;
		this->V = other.V;
	}
	return *this;
}

void PmergeMe::pushDeque(int a) { D.push_back(a); }

void PmergeMe::pushList(int a) { V.push_back(a); }

std::deque<int> &PmergeMe::getD(void) { return D; }

std::vector<int> &PmergeMe::getL(void) { return V; }


PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) 
		*this = other;
}

void PmergeMe::sort(void) {
	pairSort(D);
	mergeSort(D);
	pairSort(V);
	mergeSort(V);
	print(D);
	print(V);
}

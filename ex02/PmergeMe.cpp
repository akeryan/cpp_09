/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:46 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 13:30:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) {
	if (this != &other) 
		*this = other;
}

const PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->D = other.D;
		this->V = other.V;
	}
	return *this;
}

void PmergeMe::push(const int a) { 
	if (a < 0)
		throw (std::runtime_error("Error"));
	D.push_back(a);
	V.push_back(a); 
}

// Ford-Johnson algorithm
void PmergeMe::sort(void) {
	std::cout << "Before:";
	print(D);
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	pairSort(D);
	mergeSort(D);
	std::cout << "After:";
	print(D);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	unsigned int long long duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout	<< "Time to process a range of " << D.size() << " elements with std::deque\t: " \
				<< std::fixed << std::setprecision(5) << (double long)duration/1000000 << " us" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	pairSort(V);
	mergeSort(V);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout	<< "Time to process a range of " << V.size() << " elements with std::vector\t: " \
				<< std::fixed << std::setprecision(5) << (double long)duration/1000000 << " us" << std::endl;
}

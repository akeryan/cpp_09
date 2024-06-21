/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:36 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 11:06:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <deque>
# include <vector>
# include <chrono>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		const PmergeMe &operator=(const PmergeMe &other);

		void push(const int a);
		void sort(void);

		template <typename Container>
		void print(const Container &C);

		template <typename Container>
		static void pairSort(Container &C);

		template <typename Container>
		static void mergeSort(Container &C);

	private:
		template <typename Container>
		static void advance(Container &C, typename Container::iterator &it, unsigned int steps);
		std::deque<int> D;
		std::vector<int> V;
};

template <typename Container>
void PmergeMe::pairSort(Container &C) {
	typename Container::iterator it = C.begin();
	while (C.end() - it >= 2) {
		if (*it > *(it + 1)) {
			int tmp = *it;
			*it = *(it + 1);
			*(it + 1) = tmp;
		} 
		advance(C, it, 2);
	}
}

template <typename Container>
void PmergeMe::advance(Container &C, typename Container::iterator &it, unsigned int steps) {
	while (steps-- > 0 && it != C.end())
		it++;
}

template <typename Container>
void PmergeMe::print(const Container &C) {
	if (C.empty())
		return ;
	unsigned int s;
	if (D.size() <= 10)
		s = D.size();
	else 
		s = 4;
	std::cout << "\t";
	for (typename Container::const_iterator it = C.begin(); it != C.end() && s-- > 0; ++it) {
		std::cout << *it << " ";
	}
	if (D.size() > 10)
		std::cout << "[...]" << std::endl;
	else
		std::cout << std::endl;
}

template <typename Container>
void PmergeMe::mergeSort(Container &C) {
	if (C.empty()) 
		throw (std::runtime_error("Error: container is empty"));
	Container S = C; //source
	long K = 2;
	while (K < (long)S.size())  {
		Container d;
		typename Container::iterator it1, it2;
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
	C = S;
}

#endif
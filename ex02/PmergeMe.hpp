/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:36 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/20 19:59:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <deque>
# include <iostream>
# include <list>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		const PmergeMe &operator=(const PmergeMe &other);

		template <typename Container>
		void print(const Container &C) const;
		
		template <typename Container>
		int distance(Container )

		void pushDeque(int a);
		void pushList(int a);
		//void sort(void);

		template <typename Container>
		void pairSort(Container &D_);

		void mergeSort(void);

		std::deque<int> &getD(void); 
		std::list<int> &getL(void); 

	private:
		template <typename Container>
		void advance(Container &C, typename Container::iterator &it, unsigned int steps) const;
		std::deque<int> D;
		std::list<int> L;
};

template <typename Container>
void PmergeMe::pairSort(Container &D_) {
	typename Container::iterator it = D_.begin();
	while (D_.end() - it >= 2) {
		if (*it > *(it + 1)) {
			int tmp = *it;
			*it = *(it + 1);
			*(it + 1) = tmp;
		} 
		advance(D_, it, 2);
	}
}

template <typename Container>
void PmergeMe::advance(Container &d, typename Container::iterator &it, unsigned int steps) const {
	while (steps-- > 0 && it != d.end())
		it++;
}

template <typename Container>
void PmergeMe::print(const Container &C) const {
	if (C.empty())
		return ;
	for (typename Container::const_iterator it = C.begin(); it != C.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


#endif
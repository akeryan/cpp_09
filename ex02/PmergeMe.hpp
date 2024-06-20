/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:36 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/20 14:05:14 by akeryan          ###   ########.fr       */
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

		void insertionSort(void);
		void printDeque(const std::deque<int> &d) const;
		void pushDeque(int a);
		void pairSort(void);
		void merge(void);
		const std::deque<int> &getD(void) const;

	private:
		void advance(std::deque<int> &d, std::deque<int>::iterator &it, unsigned int steps) const;
		std::deque<int> D;
		std::list<int> _lst;
};

#endif
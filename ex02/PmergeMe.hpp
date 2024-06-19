/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:36 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/19 19:10:23 by akeryan          ###   ########.fr       */
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
		void printDeque(void) const;
		void pushDeque(int a);
		void pairSort(void);
	private:
		std::deque<int> D;
		std::list<int> _lst;
};

#endif
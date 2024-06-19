/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/19 13:23:53 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <queue>
# include <sstream>
# include <iostream>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		const RPN &operator=(const RPN &other);
		void readString(const std::string &str);
		void print(void) const;
		void compute(void) const;
	private:
		int _run(float &r, std::queue<char> &que) const;
		std::queue<char> _expr;
};

#endif
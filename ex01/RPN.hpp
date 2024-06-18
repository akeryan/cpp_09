/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/18 19:22:48 by akeryan          ###   ########.fr       */
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
		void process(void) const;
	private:
		std::queue<char> _expr;
};

#endif
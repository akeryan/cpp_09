/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/21 16:14:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <stack>
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
		float rpnEval(void);
		float calculate(float a, float b, char ch);
	private:
		std::stack<float> _stack;
		std::queue<char> _tokens;
};

#endif
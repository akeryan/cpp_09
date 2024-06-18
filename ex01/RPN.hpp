/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:56:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/06/18 18:04:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <stack>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		const RPN &operator=(const RPN &other);
	private:
		std::stack<float> _stack;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-04 09:39:21 by nkuydin           #+#    #+#             */
/*   Updated: 2026-09-04 09:39:21 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN(std::string math_exp) {
    std::istringstream iss(math_exp);
    std::string token;
    double tokenNum;

    while (iss >> token) {
        if (std::istringstream(token) >> tokenNum) {
            _stack.push(tokenNum);
        }
        else {
            if (_stack.size() < 2)
                throw(RPN::Error());
            double SecondOp = _stack.top();
            _stack.pop();
            double FirstOp = _stack.top();
            _stack.pop();
            std::stringstream ss(token);
            char operand;
            ss >> operand;
            switch (operand) {
                case '+':
                    _stack.push(FirstOp + SecondOp); break ;
                case '*':
                    _stack.push(FirstOp * SecondOp); break ;
                case '-':
                    _stack.push(FirstOp - SecondOp); break ;
                case '/': {
                    if (SecondOp == 0)
                        throw(RPN::Error());
                    _stack.push(FirstOp / SecondOp); break ;
                }
                default: throw(RPN::Error()); break ;
            }
        }
    }
}

double RPN::getResult(void) {
    if (_stack.empty())
        throw(RPN::Error());
    else if (_stack.size() > 1)
        throw(RPN::Error());
    return (_stack.top());
}

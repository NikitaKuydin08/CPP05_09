/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-25 11:15:37 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-25 11:15:37 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span {
    private:
        std::vector<int> _vn;
        unsigned int _N;

    public:
        Span(void);
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span(void);

        void addNumber(int n);
        void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);

        class Full : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Unable to add new element: span is full");
                }
        };

        class NoSpan : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Unable to find a span: insufficient number of values stored");
                }
        };

        int shortestSpan(void);
        int longestSpan(void);
        void recursion(std::vector<int>::iterator first, std::vector<int>::iterator y, int& difference);
};

#endif
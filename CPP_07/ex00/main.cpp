/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-06 10:51:05 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-06 10:51:05 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <string>

int main(void) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    double e = 42.2;
    double f = 4.2;
    std::cout << "Before Swap operation, e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "After Swap operation, e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
    // Shouldn't work with the code below
    // int g = 67;
    // char h = 'A';
    // std::cout << "Before Swap operation, g = " << g << ", h = " << h << std::endl;
    // ::swap(g, h);
    // std::cout << "After Swap operation, g = " << g << ", h = " << h << std::endl;
    // std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
    // std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
    return 0;
}

// class Comparison {
//     private:
//         int _n;

//     public:
//         Comparison(int n) : _n(n) {}
//         Comparison& operator=(const Comparison& copy) {this->_n = copy._n; return (*this); }
//         bool operator<(const Comparison& copy) const { return (this->_n < copy._n); }
//         bool operator>(const Comparison& copy) const { return (this->_n > copy._n); }

//         int getN(void) const { return (this->_n); }
// };

// std::ostream &operator<<(std::ostream &oss, const Comparison& copy) {oss << copy.getN(); return (oss); }

// int main(void) {
//     Comparison a(2), b(3);

//     std::cout << "Before Swap operation, a = " << a << ", b = " << b << std::endl;
//     ::swap(a, b);
//     std::cout << "After Swap operation, a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// }

/*
    a = 3, b = 2
    min(a, b) = 2
    max(a, b) = 3
    c = chaine2, d = chaine1
    min(c, d) = chaine1
    max(c, d) = chaine2
*/
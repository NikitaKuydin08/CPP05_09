/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-11 23:38:17 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-11 23:38:17 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

class Iter {
    private:
        int _n;

    public:
        Iter(void) : _n(42) { return ; }
        int getN(void) const { return(this->_n); }
};

std::ostream &operator<<(std::ostream &oss, const Iter& copy) {
    oss << copy.getN();
    return (oss);
}

template <typename P>
void print(P &val) {
    std::cout << val << std::endl;
}

int main(void) {
    std::string tab[] = {"Kello", "World", "Okey", "Bye Bye"};
    const int len = 4;
    iter(tab, len, print<std::string>);

    int tab1[] = {0, 1, 2, 3, 4};
    const size_t len1 = 5;
    iter(tab1, len1, print<const int>);


    Iter tab2[4];
    const size_t len2 = 4;
    iter(tab2, len2, print<Iter>);
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-28 07:09:02 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-28 07:09:02 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
MutantStack<T>::MutantStack(void) {
    std::cout << "Created empty deque container" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : deque(copy.getDeque()) {
    std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& copy) {
    if (this != &copy) { this->deque = copy.deque; }
    std::cout << "Copy assigment operator called" << std::endl;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
    std::cout << "Default constructor called" << std::endl;
}

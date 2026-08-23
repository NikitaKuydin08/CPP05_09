/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-06 10:52:28 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-06 10:52:28 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const& min(T const &a, T const &b) { return (a < b) ? a : b; }

template <typename T>
T const& max(T const &a, T const &b) { return (a > b) ? a : b; }

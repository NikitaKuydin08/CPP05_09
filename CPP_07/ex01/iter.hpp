/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-07 09:22:37 by nkuydin           #+#    #+#             */
/*   Updated: 2026-08-07 09:22:37 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* arr, const size_t len, F func) {
    if (!arr || len == 0)
        return ;
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif
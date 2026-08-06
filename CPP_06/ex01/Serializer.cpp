/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-30 15:03:39 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-30 15:03:39 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) { }

Serializer::Serializer(const Serializer &copy) { (void)copy; }

Serializer& Serializer::operator=(const Serializer& copy) {
    (void)copy;
    return (*this);
}

Serializer::~Serializer(void) { }

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
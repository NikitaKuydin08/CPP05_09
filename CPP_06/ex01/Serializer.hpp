/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-30 14:55:23 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-30 14:55:23 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

struct Data {
    int number;
    char character;
};

class Serializer {
    private:
        Serializer(void);
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);
        ~Serializer(void);

    public:
        static uintptr_t serialize(Data* ptr);
        // It takes a pointer and converts it to the unsigned integer type uintptr_t
        static Data* deserialize(uintptr_t raw); 
        // It takes an unsigned integer parameter and converts it to a pointer to Data
};

#endif
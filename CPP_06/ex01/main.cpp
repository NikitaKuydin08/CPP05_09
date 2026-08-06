/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-30 16:16:06 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-30 16:16:06 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
    // Serializer put;
    Data *old_ptr = new Data;
    old_ptr->character = 'f';
    old_ptr->number = 67;
    std::cout << "Address before serialization: " << old_ptr << std::endl;
    std::cout << "Number: " << old_ptr->number << ", Char: " << old_ptr->character << std::endl;
    uintptr_t num = Serializer::serialize(old_ptr);
    std::cout << "value of uintptr_t: " << num << std::endl;

    Data *new_ptr = Serializer::deserialize(num);
    std::cout << "Address after serialization and reverse operation: " << new_ptr << std::endl;
    std::cout << "Number: " << new_ptr->number << ", Char: " << new_ptr->character << std::endl;
    delete old_ptr;

    if (old_ptr == new_ptr)
        std::cout << "Pointers Match" << std::endl;
    else
        std::cout << "Pointers do not match" << std::endl;
}

// int main(void) {
//     Data old_ptr = {64, 'd'};
//     std::cout << "Address before serialization: " << &old_ptr << std::endl;
//     std::cout << "Number: " << old_ptr.number << ", Char: " << old_ptr.character << std::endl;
//     uintptr_t num = Serializer::serialize(&old_ptr);
//     std::cout << "value of uintptr_t: " << num << std::endl;

//     Data *new_ptr = Serializer::deserialize(num);
//     std::cout << "Address after serialization and reverse operation: " << new_ptr << std::endl;
//     std::cout << "Number: " << new_ptr->number << ", Char: " << new_ptr->character << std::endl;

//     if (new_ptr == &old_ptr)
//         std::cout << "Pointers Match" << std::endl;
//     else
//         std::cout << "Pointers do not match" << std::endl;
// }
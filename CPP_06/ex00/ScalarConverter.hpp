/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-16 09:03:30 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-16 09:03:30 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter& operator=(const ScalarConverter &copy);
        ~ScalarConverter(void);

    public:
        static void convert(const std::string toConvert);
}

#endif
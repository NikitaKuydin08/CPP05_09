/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-09 12:31:19 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-09 12:31:19 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
    public:
        Intern(void);
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern(void);

        AForm* makeForm(const std::string _name, const std::string _target);
};

#endif
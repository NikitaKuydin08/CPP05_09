/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 11:55:30 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-08 11:55:30 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;
        virtual void doAction(void) const;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm(void);

        const std::string getTarget(void) const;
};

#endif
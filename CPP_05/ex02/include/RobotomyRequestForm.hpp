/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 11:56:59 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-08 11:56:59 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;
        virtual void doAction(void) const;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        ~RobotomyRequestForm(void);

        const std::string getTarget(void) const;
};

#endif
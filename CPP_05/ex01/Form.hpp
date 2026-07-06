/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nikitakuydin@qmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-06 12:19:04 by nkuydin           #+#    #+#             */
/*   Updated: 2026-07-06 12:19:04 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        int _sign;
        int _exec;

    public:
        Form(void);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form(void);

        void beSigned(const Bureaucrat& other);
        void signForm(void);
}

#endif
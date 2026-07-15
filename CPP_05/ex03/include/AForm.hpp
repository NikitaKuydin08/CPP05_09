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

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _toSign;
        const int _toExec;
        virtual void doAction(void) const = 0;

    public:
        AForm(void);
        AForm(const std::string name, const int toSign, const int toExec);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm(void);

        void beSigned(const Bureaucrat& other);

        void execute(const Bureaucrat& executor) const;

        void setIsSigned(bool Signed);
        const std::string getName(void) const;
        int getToSign(void) const;
        int getToExec(void) const;
        bool getIsSigned(void) const;

        std::string info(void) const;

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormIsSigned : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &o, const AForm& other);

#endif
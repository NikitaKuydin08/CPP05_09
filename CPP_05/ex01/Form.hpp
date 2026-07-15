/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:19:04 by nkuydin           #+#    #+#             */
/*   Updated: 2026/07/15 18:56:24 by nkuydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _toSign;
        const int _toExec;

    public:
        Form(void);
        Form(const std::string name, const int toSign, const int toExec);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form(void);

        void beSigned(const Bureaucrat& other);

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
};

std::ostream& operator<<(std::ostream &o, const Form& other);

#endif
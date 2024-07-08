
#ifndef FORM_HPP
# define FORM_HPP

// # include "Bureacrat.hpp"
# include <string>
# include <iostream>

class Bureaucrat;
class GradeTooLowException;

class Form
{
private:
    const std::string _name;
    const int   _sign_grade_requirement;
    const int   _excute_grade_requirement;
    bool    _signed;
public: 
    GradeTooLowException GradeTooLow;
    Form(std::string name, int sign_grade_requirement, int excute_grade_requirement);
    Form(Form &dup);
    Form    &operator=(const Form &other);
    ~Form();
    std::string getName();
    int         getSignGradeRequirement();
    void        setSignGradeRequirement(int value);
    int         getExcuteGradeRequirement();
    void        setExcuteGradeRequirement(int value);
    bool        isSigned() const;
    void        beSigned(Bureaucrat &responsible_guy);
    void        signForm(Bureaucrat &responsible_guy, bool print);
    // void        signForm(Bureaucrat &responsible_guy);
};

std::ostream &operator<<(std::ostream &o, Form& cur_form);

#endif



# pragma once

// # include "Bureacrat.hpp"
# include <string>
# include <iostream>
# include <fstream>
# include "GradeTooLowException.hpp"
class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    const int       _sign_grade_requirement;
    const int       _excute_grade_requirement;
    bool            _signed;
protected:
    std::string _target;
    AForm(std::string name, int sign_grade_requirement, int excute_grade_requirement);
    virtual void    execute_action(Bureaucrat const & executor) const = 0;

public: 
    GradeTooLowException GradeTooLow;
    AForm(AForm &dup);
    AForm    &operator=(const AForm &other);
    virtual ~AForm() = 0;
    std::string getName() const;
    int         getSignGradeRequirement();
    void        setSignGradeRequirement(int value);
    int         getExcuteGradeRequirement();
    void        setExcuteGradeRequirement(int value);
    bool        isSigned() const;
    void        beSigned(Bureaucrat &responsible_guy);
    // void        signForm(Bureaucrat &responsible_guy);
    void        execute(Bureaucrat const & executor) const;
    void        signForm(Bureaucrat &responsible_guy, bool print);
};

std::ostream &operator<<(std::ostream &o, AForm& cur_form);


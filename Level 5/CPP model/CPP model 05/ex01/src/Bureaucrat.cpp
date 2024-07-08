#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

const char *GradeTooHighException::what() const throw() {
    return ("Can't, Grade is too high");
}

const char *GradeTooLowException::what() const throw(){
    return ("Can't, Grade is too low");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)  {
    if (grade < 1)
    {
        throw (this->GradeTooLow);
    }
    if (grade > 150)
    {
        throw (this->GradeTooHigh);
    }
    this->_grade = grade;
}

void    Bureaucrat::increment_grade() {
    if (_grade == 150)
        throw (this->GradeTooHigh);
    _grade++;
}

void    Bureaucrat::decrement_grade() {
    if (_grade == 1)
        throw (this->GradeTooLow);
    _grade--;
}

Bureaucrat::Bureaucrat(Bureaucrat &dup) : _name(dup._name) {
    this->_grade = dup.get_grade();
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other) {
    this->_grade = other.get_grade();
    return (*this);
}


Bureaucrat::~Bureaucrat() {

}

std::string Bureaucrat::get_name() const {
    return (this->_name);
}

int Bureaucrat::get_grade() const {
    return (this->_grade);
}

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& cur_bureaucrat ) {
    o << cur_bureaucrat.get_name() << " as grade of " << cur_bureaucrat.get_grade();
    return (o);
}

void    Bureaucrat::signForm(Form &form) {
    if (this->_grade > form.getSignGradeRequirement()) {
        std::cout << _name <<  " couldn't sign " << form.getName() << " because it is not qualified to sign\n";
        return ;
    }
    form.signForm(*this, true);
}



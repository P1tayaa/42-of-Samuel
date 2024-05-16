# include "Bureaucrat.hpp"
# include "AForm.hpp"

AForm::AForm(std::string name, int sign_grade_requirement, int excute_grade_requirement)  : _name(name), _sign_grade_requirement(sign_grade_requirement), _excute_grade_requirement(excute_grade_requirement) {
    _signed = false;
}

AForm::AForm(AForm &dup) : _name(dup._name), _sign_grade_requirement(dup._sign_grade_requirement), _excute_grade_requirement(dup._excute_grade_requirement), _signed(dup._excute_grade_requirement) {

}

AForm    &AForm::operator=(const AForm &other) {
    _signed = other.isSigned();
    return (*this);
}

AForm::~AForm() {

}

std::string AForm::getName() const {
    return (_name);
}

int         AForm::getSignGradeRequirement() {
    return (_sign_grade_requirement);
}

int         AForm::getExcuteGradeRequirement() {
    return (_excute_grade_requirement);
}

bool        AForm::isSigned() const {
    return (_signed);
}

void    AForm::signForm(Bureaucrat &responsible_guy, bool print) {
    if (_signed)
    {
        if (print)
            std::cout << responsible_guy.get_name() << " couldn't sign " << _name << " because it is already signed\n";
        return ;
    }
    _signed = true;
    if (print)
        std::cout << responsible_guy.get_name() << " signed " << _name << std::endl;
}

void    AForm::signForm(Bureaucrat &responsible_guy) {
    if (responsible_guy.get_grade() < _sign_grade_requirement) {
        std::cout << responsible_guy.get_name() <<  " couldn't sign " << _name << " because it is not qualified to sign\n";
        return ;
    }
    signForm(responsible_guy, true);
}


void        AForm::beSigned(Bureaucrat &responsible_guy) {
    if (responsible_guy.get_grade() < _sign_grade_requirement)
        throw (GradeTooLow);
    signForm(responsible_guy, false);
}

std::ostream &operator<<(std::ostream &o, AForm& cur_form) {
    o << cur_form.getName() << " form can be signed by by people of grade " << cur_form.getSignGradeRequirement()
        << " and can excuted by people of grade " << cur_form.getExcuteGradeRequirement();
    if (cur_form.isSigned())
        o << " and is signed\n";
    else
        o << " and is not sign\n"; 
    return o;
}

void        AForm::execute(Bureaucrat const & executor) const {
    if (executor.get_grade() < _sign_grade_requirement)
        throw (GradeTooLow);
    this->execute_action(executor);
}


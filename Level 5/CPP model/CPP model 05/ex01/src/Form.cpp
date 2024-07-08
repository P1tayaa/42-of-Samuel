#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

Form::Form(std::string name, int sign_grade_requirement, int excute_grade_requirement)  : _name(name), _sign_grade_requirement(sign_grade_requirement), _excute_grade_requirement(excute_grade_requirement) {
	_signed = false;
}

Form::Form(Form &dup) : _name(dup._name), _sign_grade_requirement(dup._sign_grade_requirement), _excute_grade_requirement(dup._excute_grade_requirement), _signed(dup._excute_grade_requirement) {

}

Form    &Form::operator=(const Form &other) {
	_signed = other.isSigned();
	return (*this);
}

Form::~Form() {

}

std::string Form::getName() {
	return (_name);
}

int         Form::getSignGradeRequirement() {
	return (_sign_grade_requirement);
}

int         Form::getExcuteGradeRequirement() {
	return (_excute_grade_requirement);
}

bool        Form::isSigned() const {
	return (_signed);
}

void    Form::signForm(Bureaucrat &responsible_guy, bool print) {
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

// void    Form::signForm(Bureaucrat &responsible_guy) {
//     if (responsible_guy.get_grade() > _sign_grade_requirement) {
//         std::cout << responsible_guy.get_name() <<  " couldn't sign " << _name << " because it is not qualified to sign\n";
//         return ;
//     }
//     signForm(responsible_guy, true);
// }


void		Form::beSigned(Bureaucrat &responsible_guy) {
	if (responsible_guy.get_grade() > _sign_grade_requirement)
		throw (GradeTooLow);
	signForm(responsible_guy, false);
}

std::ostream &operator<<(std::ostream &o, Form& cur_form) {
	o << cur_form.getName() << " form can be signed by people of grade less " << cur_form.getSignGradeRequirement()
		<< " and can excuted by people of grade " << cur_form.getExcuteGradeRequirement();
	if (cur_form.isSigned())
		o << " and is signed\n";
	else
		o << " and is not sign\n"; 
	return o;
}


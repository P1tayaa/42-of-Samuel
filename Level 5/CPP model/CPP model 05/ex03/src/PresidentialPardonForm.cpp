# include "../include/PresidentialPardonForm.hpp"
# include "../include/Bureaucrat.hpp"

void    PresidentialPardonForm::execute_action(Bureaucrat const & executor) const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
    std::cout << executor.get_name() << " excuted Presidential Pardon Form " << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5) {
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}


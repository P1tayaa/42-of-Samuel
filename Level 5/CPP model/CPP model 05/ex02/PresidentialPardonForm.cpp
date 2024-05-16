# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

void    PresidentialPardonForm::execute_action(Bureaucrat const & executor) const {
    std::cout << executor.get_name() << " excuted Presidential Pardon Form " << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}


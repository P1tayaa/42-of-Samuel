# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

void    ShrubberyCreationForm::execute_action(Bureaucrat const & executor) const {
    std::cout << executor.get_name() << " excuted Shrubbery Creation Form " << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}


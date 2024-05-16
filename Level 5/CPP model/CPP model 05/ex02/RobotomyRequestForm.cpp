# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

void    RobotomyRequestForm::execute_action(Bureaucrat const & executor) const {
    std::cout << executor.get_name() << " excuted Robotomy Request Form " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}


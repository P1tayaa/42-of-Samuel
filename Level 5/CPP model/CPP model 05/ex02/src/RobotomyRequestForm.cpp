# include "../include/RobotomyRequestForm.hpp"
# include "../include/Bureaucrat.hpp"
# include <random>

void    RobotomyRequestForm::execute_action(Bureaucrat const & executor) const {
    std::cout << "*DRIP NOISE*\n";
        std::cout << "the opperation of " << this->getName(); 
    if ((std::rand() + 1) % 2) {
        std::cout << " was a success\n";
    } else {
        std::cout << " was not a success\n";
    }
    std::cout << executor.get_name() << " excuted Robotomy Request Form " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}


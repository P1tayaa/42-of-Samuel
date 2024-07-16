# include "../include/RobotomyRequestForm.hpp"
# include "../include/Bureaucrat.hpp"
# include <random>

void    RobotomyRequestForm::execute_action(Bureaucrat const & executor) const {
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(0,1);
    int random_num = dis(gen);
    std::cout << "*DRIP NOISE*\n";
        std::cout << "the opperation of " << _target; 
    if (random_num == 0) {
        std::cout << " was a success\n";
    } else {
        std::cout << " was not a success\n";
    }
    std::cout << executor.get_name() << " excuted Robotomy Request Form " << this->getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45) {
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}


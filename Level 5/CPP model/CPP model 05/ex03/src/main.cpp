
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main() {
    Bureaucrat *Michel;
    AForm *temp;
    ShrubberyCreationForm *ShrubberyForm;
    Intern low_life;

    
    Michel = new Bureaucrat("Michel", 1);
    temp = low_life.makeForm("don't exit", "BOB");
    temp = low_life.makeForm("robotomy request", "BOB");
    std::cout << "\n\n\n\n";
    ShrubberyForm = reinterpret_cast<ShrubberyCreationForm *>(temp);
    Michel->signForm(*ShrubberyForm);
    Michel->executeForm(*ShrubberyForm);

    delete Michel;
    delete ShrubberyForm;
    return 0;
}

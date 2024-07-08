
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat *Tiery;
    Bureaucrat *Michel;
    PresidentialPardonForm *PresidentForm;
    RobotomyRequestForm *RobotomyForm;
    ShrubberyCreationForm *ShrubberyForm;
    
    Tiery = new Bureaucrat("Tiery", 1);
    Michel = new Bureaucrat("Michel", 120);
    PresidentForm = new PresidentialPardonForm("PresidentForm");
    RobotomyForm = new RobotomyRequestForm("RobotomyForm");
    ShrubberyForm = new ShrubberyCreationForm("ShrubberyForm");
    Michel->signForm(*ShrubberyForm);
    Michel->signForm(*RobotomyForm);
    Tiery->signForm(*RobotomyForm);
    Tiery->signForm(*PresidentForm);
    Tiery->signForm(*PresidentForm);
    Michel->executeForm(*ShrubberyForm);
    Michel->executeForm(*RobotomyForm);
    Tiery->executeForm(*RobotomyForm);

    delete Tiery;
    delete Michel;
    delete PresidentForm;
    delete RobotomyForm;
    delete ShrubberyForm;
    return 0;
}

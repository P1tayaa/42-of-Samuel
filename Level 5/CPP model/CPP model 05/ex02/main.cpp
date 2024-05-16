
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
    ShrubberyForm->signForm(*Michel);
    RobotomyForm->signForm(*Tiery);
    PresidentForm->signForm(*Tiery);
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

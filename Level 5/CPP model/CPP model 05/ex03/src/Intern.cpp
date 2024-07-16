# include "../include/AForm.hpp"
# include "../include/Intern.hpp"
# include "../include/PresidentialPardonForm.hpp"
# include "../include/RobotomyRequestForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& dup) {return; (void)dup;}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& dup) {return *this; (void)dup;}

AForm *Intern::makeForm(std::string name, std::string target) {
        std::string name_forms[3] = {"shrubbery request",
            "robotomy request", "presidential request"};
        AForm *type_form[3] = {new ShrubberyCreationForm(target),
            new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
        int i;
        for (i = 0; i < 3; i++) {
            if (name == name_forms[i]) {
                for (int j = 0; j < 3; j++) {
                    if (i == j)
                        continue ;
                    delete type_form[j];
                }
                return type_form[i];
            }
        }
        for (int j = 0; j < 3; j++) {
            delete type_form[j];
        }
        std::cout << "form doesn't exist\n";
        return nullptr;
    }
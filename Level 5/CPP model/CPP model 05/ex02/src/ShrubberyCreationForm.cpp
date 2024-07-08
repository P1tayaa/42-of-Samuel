# include "../include/ShrubberyCreationForm.hpp"
# include "../include/Bureaucrat.hpp"

const std::string ASCII_tree = 
"   *    *  ()   *   *\n"
"*        * /\\\\         *\n"
"      *   /i\\\\    *  *\n"
"    *     o/\\  *      *\n"
" *       ///\\i\\    *\n"
"     *   /*/o\\  *    *\n"
"   *    /i//\\*\\      *\n"
"        /o/*\\\\i\\   *\n"
"  *    //i//o\\\\\\     *\n"
"    *  /i///o\\\\\\\\\n"
" *    //o//i\\\\*\\\\\\   *\n"
"   * /i///o/\\\\\\\\o\\   *\n"
"  *    *   ||     * \n";

void    ShrubberyCreationForm::execute_action(Bureaucrat const & executor) const {
    std::ofstream Myfile(this->getName() + "_Shrubbery");
    Myfile << ASCII_tree;
    Myfile.close();
    std::cout << executor.get_name() << " excuted Shrubbery Creation Form " << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}


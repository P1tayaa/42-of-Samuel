
#include "../include/Bureaucrat.hpp"

int main() {
    Bureaucrat *Tiery;
    Bureaucrat *Michel;

    Tiery = new Bureaucrat("Tiery", 1);
    Michel = new Bureaucrat("Michel", 150);
    std::cout << *Tiery << std::endl;
    std::cout << *Michel << std::endl;
    try
    {
        Tiery->decrement_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Michel->increment_grade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Tiery->increment_grade();
    std::cout << *Tiery << std::endl;
    delete Tiery;
    try
    {
        Tiery = new Bureaucrat("Tiery", 0);
        std::cout << *Tiery << std::endl;
        delete Tiery;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete Michel;
    try
    {
        Michel = new Bureaucrat("Michel", 151);
        std::cout << *Michel << std::endl;
        delete Michel; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

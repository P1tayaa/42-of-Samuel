
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat *Tiery;
    Bureaucrat *Michel;
    Form       *VideoGameTierList;
    Form       *NukeDeployment;

    Tiery = new Bureaucrat("Tiery", 1);
    Michel = new Bureaucrat("Michel", 150);
    NukeDeployment = new Form("Nuke Deplyment", 150, 150);
    VideoGameTierList = new Form("Video Game Tier List", 1, 1);
    try
    {
        NukeDeployment->beSigned(*Tiery);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    NukeDeployment->signForm(*Tiery);
    NukeDeployment->signForm(*Michel);
    NukeDeployment->signForm(*Michel);
    
    std::cout << *VideoGameTierList;
    std::cout << *NukeDeployment;
    delete Tiery;
    delete Michel;
    delete VideoGameTierList;
    delete NukeDeployment;
    return 0;
}

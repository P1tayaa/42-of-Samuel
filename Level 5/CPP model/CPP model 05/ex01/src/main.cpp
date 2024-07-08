
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
    Bureaucrat *Tiery;
    Bureaucrat *Michel;
    Form       *VideoGameTierList;
    Form       *NukeDeployment;

    Tiery = new Bureaucrat("Tiery", 1);
    Michel = new Bureaucrat("Michel", 150);
    NukeDeployment = new Form("Nuke Deplyment", 1, 1);
    VideoGameTierList = new Form("Video Game Tier List", 150, 150);
    try
    {
        NukeDeployment->beSigned(*Michel);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Michel->signForm(*NukeDeployment);
    Tiery->signForm(*NukeDeployment);
    Tiery->signForm(*NukeDeployment);
    // NukeDeployment->signForm(*Michel);
    // NukeDeployment->signForm(*Tiery);
    // NukeDeployment->signForm(*Tiery);
    
    std::cout << *VideoGameTierList;
    std::cout << *NukeDeployment;
    delete Tiery;
    delete Michel;
    delete VideoGameTierList;
    delete NukeDeployment;
    return 0;
}

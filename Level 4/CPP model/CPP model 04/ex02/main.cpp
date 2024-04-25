#include "animals.hpp"

int main()
{
    // const Animal* meta = new Animal();
    Dog* j = new Dog();
    Cat* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();
    j->get_access_brain()->set_idea(3, "test");
    std::cout << j->get_access_brain()->get_idea(3) << std::endl;

    // delete meta;
    delete j;
    delete i;
    return 0;
}

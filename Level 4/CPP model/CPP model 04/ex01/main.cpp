#include "animals.hpp"

int main()
{
    const Animal* meta = new Animal();
    Dog* j = new Dog();
    Cat* i = new Cat();

    j->get_access_brain()->set_idea(0, "test");
    {
        Dog* new_dog = new Dog(*j);
        std::cout << "idea of new_dog is " <<  new_dog->get_access_brain()->ideas[0] << std::endl;
        delete new_dog;
    }
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << j->get_access_brain()->get_idea(0) << std::endl;

    delete meta;
    delete j;
    delete i;
    return 0;
}

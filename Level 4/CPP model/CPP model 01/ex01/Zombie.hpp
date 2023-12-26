#include <iostream>
#include <string>


class Zombie
{
    public:
    Zombie() {};
    Zombie(std::string name) : name(name) {};
    ~Zombie();
    void    announce(void);

    private:
    std::string name;
};

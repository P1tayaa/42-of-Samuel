# include "../include/easyfind.hpp"
# include <vector>
# include <list>

int main(void) {
    std::vector<int> container_1;
    std::vector<int>::iterator it;
    bool return_val;
    for (size_t i = 0; i < 10; i++)
    {
        container_1.push_back(i);
    }
    return_val = easyfind(container_1, 3, it);
    std::cout << "should be 1 " << return_val << " value is " << *it;
    return_val = easyfind(container_1, 12, it);
    std::cout << ", should be 0 " << easyfind(container_1, 12, it)  << std::endl;
}

# include "../include/easyfind.hpp"
# include <vector>
# include <list>

int main(void) {
    std::vector<int> container_1;
    for (size_t i = 0; i < 10; i++)
    {
        container_1.push_back(i);
    }
    std::cout << "should be 1 " << easyfind(container_1, 3) << ", should be 0 " << easyfind(container_1, 12)  << std::endl;
}
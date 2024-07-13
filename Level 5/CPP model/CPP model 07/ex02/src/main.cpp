# include "../include/Array.hpp"

int main(void) {
    unsigned int size = 6;
    Array<int> test(size);
    for (uint i = 0; i < size; i++) {
        test[i] = i + 1;
    }
    for (uint i = 0; i < size; i++) {
        std::cout << test[i] << std::endl;
    }
    return 0;
}
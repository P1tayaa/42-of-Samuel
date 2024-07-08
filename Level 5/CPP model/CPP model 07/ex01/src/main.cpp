# include "../include/iter.hpp"

void print_num(int n) {
    std::cout << n<< std::endl;
}

int main(void) {
    int nums[4] = {1, 2, 3, 4,};
    iter(&nums[0], 4, &print_num);
}
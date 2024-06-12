# include "Serialize.hpp"

int main() {
    uintptr_t test1 = INTPTR_MIN;
    uintptr_t test2 = INTPTR_MAX;
    uintptr_t test3 = 0;
    std::cout << "test1 is " << test1 << std::endl;
    std::cout << "test2 is " << test2 << std::endl;
    std::cout << "test3 is " << test3 << std::endl;

    std::cout << "After made into Data test1 is " << Serialize::serialize(Serialize::deserialize(test1)) << std::endl;
    std::cout << "After made into Data test2 is " << Serialize::serialize(Serialize::deserialize(test2)) << std::endl;
    std::cout << "After made into Data test3 is " << Serialize::serialize(Serialize::deserialize(test3)) << std::endl;

}


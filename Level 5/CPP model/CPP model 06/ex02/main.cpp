# include "Base.hpp"

int main() {
    Base *test1 = generate();
    Base *test2 = generate();
    Base *test3 = generate();

    identify(test1);
    identify(&*test1);

    identify(test2);
    identify(&*test2);

    identify(test3);
    identify(&*test3);

    delete test1;
    delete test2;
    delete test3;
    return 0;
}


# include "Base.hpp"

Base::~Base() {};

// A::A() {};

// A::~A() {};


// B::B() {};

// B::~B() {};


// C::C() {};

// C::~C() {};

Base * generate(void) {
    // std::srand(std::time(nullptr));
    // int random_num = std::rand();
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(0,2);
    int random_num = dis(gen);
    Base *return_base;

    switch (random_num % 3) {
        case 0:
        return_base = new A;
        break;
        case 1:
        return_base = new B;
        break;
        case 2:
        return_base = new C;
        break;
        default:
        std::cout << "should never happen\n";
        break;
    }
    return (return_base);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "It is class A\n";
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "It is class B\n";
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "It is class C\n";
    }
    else {
        std::cout << "It is class not A, B or C\n";
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "It is class A\n";
        return ;
    }
    catch(std::bad_cast &) {}
    try {
        dynamic_cast<B&>(p);
        std::cout << "It is class B\n";
        return ;
    }
    catch(std::bad_cast &) {}
    try {
        dynamic_cast<C&>(p);
        std::cout << "It is class C\n";
        return ;
    }
    catch(std::bad_cast &) {}
    std::cout << "It is class not A, B or C\n";
}

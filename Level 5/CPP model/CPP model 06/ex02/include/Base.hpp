
#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <random>

class Base
{
public:
    virtual ~Base();
};

class A : public Base {};
// {
// private:
//     /* data */
// public:
//     A(/* args */);
//     ~A();
// };

class B : public Base {};
// {
// private:
//     /* data */
// public:
//     B(/* args */);
//     ~B();
// };

class C : public Base {};
// {
// private:
//     /* data */
// public:
//     C(/* args */);
//     ~C();
// };

void identify(Base& p);
void identify(Base* p);
Base * generate(void);

#endif

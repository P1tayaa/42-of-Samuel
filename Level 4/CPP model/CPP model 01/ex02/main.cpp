#include <iostream>
#include <string>

int main()
{
    std::string str_a;

    std::string* prt_str_a;

    std::string& ref_str_a = str_a;

    prt_str_a = &str_a;

    str_a = "HI THIS IS A BRAIN";

    std::cout << "memory address of string " << &str_a << std::endl;
    std::cout << "memory address of string stored by the pointer " << prt_str_a << std::endl;
    std::cout << "reference address of string " << &ref_str_a << std::endl << std::endl;

    std::cout << "value of original string " << str_a << std::endl;
    std::cout << "value at address of the pointer " << *prt_str_a << std::endl;
    std::cout << "value by the reference of string" << ref_str_a << std::endl;
    return (0);
}
#include "Harl.hpp"

int main()
{
    Harl	the_harl;

	the_harl.complain("debug");
	the_harl.complain("info");
	the_harl.complain("warning");
	the_harl.complain("error");
    return (0);
}
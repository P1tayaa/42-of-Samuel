# include "../Include/RPN.hpp"

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        RPN(argv[i]);
    }
}
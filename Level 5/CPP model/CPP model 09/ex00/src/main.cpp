# include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv) {
    BitcoinExchange test;
    if (argc == 1) {
        std::cout << "Error: could not open file.\n";
    }
    else for (int i = 1; i < argc; i++) {
        test.print_data_of_file(argv[i]);
    }
}
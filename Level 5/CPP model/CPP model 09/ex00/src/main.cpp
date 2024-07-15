# include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv) {
    BitcoinExchange test;
    for (int i = 1; i < argc; i++) {
        test.print_data_of_file(argv[i]);
    }
}
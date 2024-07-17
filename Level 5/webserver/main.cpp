# include "webserver.hpp"

int main() {
    std::ifstream fileToRead("file.conf"); //read from the text file
    // if (!fileToRead.good()) //if the reading fails
    // {
    //     std::cerr << "Error: Unable to open the input file." << std::endl;
    //     return;
    // }
    std::vector<server> * temp = make_all_server(fileToRead);
}
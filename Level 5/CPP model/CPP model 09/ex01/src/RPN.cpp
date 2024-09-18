# include "../Include/RPN.hpp"

int operate(int a, int b, std::string operation) {
    if (operation == "*") {
        a *= b;
    } else if (operation == "/") {
        if (b == 0) {
            throw std::exception();
        }
        a /= b;
    } else if (operation == "+") {
        a += b;
    } else if (operation == "-") {
        a -= b;
    }
    return a;
}

void RPN(std::string input) {
    std::deque<std::string> operation_list;
    std::stringstream src_fd(input);
    std::string temp_s;
    while (std::getline(src_fd, temp_s, ' '))
    {
        operation_list.push_back(temp_s);
    }
    std::deque<int> temp;
    try {
        while (!operation_list.empty()) {
            if (operation_list.front() == "*" || operation_list.front() == "-"
                || operation_list.front() == "/" || operation_list.front() == "+") {
                    if (temp.size() < 2)
                        throw std::exception();
                    int b = temp.front(); temp.pop_front();
                    int a = temp.front(); temp.pop_front();

                    temp.push_front(operate(a, b, operation_list.front())); operation_list.pop_front();
                }
            else {
                    temp.push_front(std::stoi(operation_list.front()));
                    operation_list.pop_front();
            }
        }
        if (temp.size() != 1) 
            throw std::exception();
    }
    catch(const std::exception& e) {
        std::cerr << "Error\n";
        return ;
    }
    std::cout << temp.front() << std::endl;
}
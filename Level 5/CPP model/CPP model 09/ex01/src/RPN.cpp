# include "../Include/RPN.hpp"

int operate(int a, int b, std::string operation) {
    if (operation == "*") {
        a *= b;
    } else if (operation == "/") {
        a /= b;
    } else if (operation == "+") {
        a += b;
    } else if (operation == "-") {
        a -= b;
    }
    return a;
}

void RPN(std::string input) {
    int size_input = input.size();
    std::deque<std::string> operation_list;
    for (int i = 0; i < size_input; i++) {
        if (isspace(input[i]))
            continue;
        operation_list.push_back(input.substr(i, input.find(' ', i) - i));
    }
    std::deque<int> temp;
    while (!operation_list.empty()) {
        if (operation_list.front() == "*" || operation_list.front() == "-"
            || operation_list.front() == "/" || operation_list.front() == "+") {
                int b = temp.front(); temp.pop_front();
                int a = temp.front(); temp.pop_front();
                temp.push_back(operate(a, b, operation_list.front())); operation_list.pop_front();
            }
        else {
            try {
                temp.push_front(std::stoi(operation_list.front()));
                operation_list.pop_front();
            }
            catch(const std::exception& e) {
                std::cerr << "Error\n";
                return ;
            }
        }
    }
    std::cout << temp.front() << std::endl;
}
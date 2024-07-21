
# include "../include/ScalarConverter.hpp"

int get_pressision(const std::string &arg) {
    int i = 0;
    int dot_index = -1;

    while (arg[i])
    {
        if (arg[i] == '.')
            dot_index = i + 1;
        i++;
    }
    if (dot_index == -1)
        return 1;
    dot_index = i - dot_index; 
    if (dot_index > 15)
        return 15;
    return (dot_index);
}

void ScalarConverter::convert(const std::string &arg) {
    float temp_float;
    double temp_double;
    int temp_int;
    char temp_char;

    try {
        temp_double = std::stod(arg);
        temp_float = static_cast<float>(temp_double);
    }
    catch(const std::exception& e)
    {
        std::cout << "not valid input\n";
        return ;
    }
    if (temp_double >= -2147483648 && temp_double <= 2147483647)
    {
        temp_int = static_cast<int>(temp_double);;
        temp_char = temp_int;
        if (std::isprint(temp_char))
            std::cout << "char: " << temp_char << std::endl;
        else
            std::cout << "char: impossible\n";
        std::cout << "int: " << temp_int << std::endl;
    }
    else {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
    }
    std::cout << std::fixed << std::setprecision(get_pressision(arg));
    std::cout << "float: " << temp_float << "f"  << std::endl;
    std::cout << "double: " << temp_double << std::endl;
}
# include "../Include/PmergeMe.hpp"

std::vector<int> get_list_num(int argc, char **argv) {
    std::vector<int> to_return;
    for (int i = 0; i < argc - 1; i++) {
        to_return.push_back(std::stoi(argv[i + 1]));
    }
    return to_return;
}

int binary_search(std::vector<int> &vector, int cur_start, int cur_size, int value) {
    int cur_index = cur_start + cur_size / 2;
    if (vector[cur_index] == value) {
        return cur_index;
    } else if (cur_size < 2){
        if (value < vector[cur_index])
            return cur_index;
        else
            return cur_index + 1;
    } else if (vector[cur_index] < value) {
        return binary_search(vector, cur_index, (cur_size + 1) / 2, value);
    } else {
        return binary_search(vector, cur_start, (cur_size + 1) / 2, value);
    }
}

void    pair_up_and_compare(int i, int size, std::vector<int> &small,
                            std::vector<int> &big, std::vector<int> &list_num) {
    std::pair<int, int>        pair_cell;

    for (;i < size; i += 2) {
        pair_cell.first = list_num[i];
        pair_cell.second = list_num[i + 1]; 
        if (pair_cell.first < pair_cell.second) {
            small.push_back(pair_cell.first);
            big.push_back(pair_cell.second);
        } else {
            small.push_back(pair_cell.second);
            big.push_back(pair_cell.first);
        }
    }
}

void merge_sort(int size, int extra_num, std::vector<int> &small, std::vector<int> &big) {
    int temp;
    for (size_t j = 0; j < small.size(); j++) {
        temp = binary_search(big, 0, big.size(), small[j]);
        if (temp >= int(big.size()))
            big.push_back(small[j]);
        else
            big.insert(big.begin() + temp, small[j]);
    }
    if (size % 2 == 1) {
        temp = binary_search(big, 0, big.size(), extra_num);
        if (temp > int(big.size()))
            big.push_back(extra_num);
        else
            big.insert(big.begin() + temp, extra_num);
    }
}

void print_vector(std::vector<int> &to_print, std::string message) {
    std::cout << message;
    for (size_t i = 0; i < to_print.size(); i++)
    {
        
        std::cout << to_print[i] << " | ";
    }    
    std::cout << std::endl;
}

void Pmerge(std::vector<int> &list_num, int size, bool first) {
    int extra_num = 0;
    int temp;
    auto first_part = std::chrono::system_clock::now();
    auto second_part = std::chrono::system_clock::now();
    auto start = std::chrono::system_clock::now();
    std::chrono::duration<double> first_elapsed_seconds;
    std::chrono::duration<double> second_elapsed_seconds;
    std::vector<int> small;
    std::vector<int> big;
    if (size % 2 == 1) {
        extra_num = list_num[0];
        pair_up_and_compare(1, size, small, big, list_num);
    } else
        pair_up_and_compare(0, size, small, big, list_num);
    if (first) {
        first_part = std::chrono::system_clock::now();
        first_elapsed_seconds = first_part-start;
    }
    if (big.size() == 2) {
        if (big[0] > big[1]){
            temp = big[0];
            big[0] = big[1];
            big[1] = temp;
        }
    } else if (big.size() > 1) {
        Pmerge(big, big.size(), false);
    }
    if (first) {
        second_part = std::chrono::system_clock::now();
        second_elapsed_seconds = second_part-first_part;
    }
    merge_sort(size, extra_num, small, big);
    list_num = big;
    if (first) {
        print_vector(list_num, "After: ");
        std::cout << std::fixed << std::setprecision(7);
        std::cout << "Time to process a range of " << size << " elements with std::pairs : " << first_elapsed_seconds.count() * size * std::log(size) << std::endl;
        std::cout << "Time to process a range of " << size << " elements with std::vectors : " << second_elapsed_seconds.count()  * size * std::log(size) << std::endl;
    }
}

int main(int argc, char **argv) {
    std::vector<int> list_num;
    
    try {
        list_num = get_list_num(argc, argv);
    }
    catch(const std::out_of_range &e) {
        std::cout << "invalid input\n";
        return 1;
    }
    print_vector(list_num, "Before: ");

    Pmerge(list_num, argc - 1, true);
    
}
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
        std::cout << "extra num added at index of " << temp << std::endl;
        if (temp > int(big.size()))
            big.push_back(extra_num);
        else
            big.insert(big.begin() + temp, extra_num);
    }
}

void Pmerge(std::vector<int> &list_num, int size) {
    int extra_num = 0;
    int temp;
    std::vector<int> small;
    std::vector<int> big;
    if (size % 2 == 1) {
        extra_num = list_num[0];
        pair_up_and_compare(1, size, small, big, list_num);
        std::cout << "extra_num is " << extra_num << std::endl;
    } else
        pair_up_and_compare(0, size, small, big, list_num);
    if (big.size() == 2) {
        if (big[0] > big[1]){
            std::cout << "big swap hgappen\n";
            temp = big[0];
            big[0] = big[1];
            big[1] = temp;
        }
    } else if (big.size() > 1) {
        Pmerge(big, big.size());
    }
    merge_sort(size, extra_num, small, big);
    
    for (size_t i = 0; i < big.size(); i++)
    {
        std::cout << big[i] << ", ";
    }
    std::cout << std::endl << std::endl;
    list_num = big;
}

int main(int argc, char **argv) {
    std::vector<int> list_num;

    try {
        list_num = get_list_num(argc, argv);
    }
    catch(const std::invalid_argument& e) {
        std::cout << "invalid input\n";
        return 1;
    }
    Pmerge(list_num, argc - 1);
}
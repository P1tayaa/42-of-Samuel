# include "../include/BitcoinExchange.hpp"

void BitcoinExchange::LoadData() {
    std::fstream data_fd(file);
    if (!data_fd.is_open())
        throw std::out_of_range("BTC:: data.csv is not accessible");
    std::string line;
    std::pair<std::string, float> input;
    size_t coma_pos;
    while (std::getline(data_fd, line)) {
        coma_pos = line.find(',');
        if (coma_pos == line.size()) {
            throw std::out_of_range("BTC:: data.csvdoesn't have correct format");
        }
        input.first = line.substr(0, coma_pos);
        input.second = std::atof(&line[coma_pos + 1]);
        data.insert(input);
    }
}

BitcoinExchange::BitcoinExchange() {
    LoadData();
};

BitcoinExchange::~BitcoinExchange() {};

void BitcoinExchange::PrintData() {
    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++) {
        std::cout << "on the " << it->first << "BTC was valued at " << it->second << std::endl;
    }
}

float BitcoinExchange::get_BTC_value_for(std::string date) {
    size_t dash_pos = date.find('-');
    size_t dash_pos_sec = date.find_last_of('-');
    if (dash_pos == date.size() || dash_pos_sec == date.size()) {
        throw std::out_of_range("Error: Bad Input");
    }
    std::string year = date.substr(0, dash_pos);
    std::string month = date.substr(dash_pos + 1, dash_pos_sec);
    std::string day = date.substr(dash_pos_sec + 1, date.size());
    int year_int = std::stoi(year);
    int month_int = std::stoi(month);
    int day_int = std::stoi(day);
    if (year_int > 2022 || year_int < 2009 || month_int < 1
        || month_int > 12 || day_int < 1 || day_int > 31 ) {
            throw std::out_of_range("Error: Bad Input");
        }
    while (!data.count(date))
    {
        if (day_int == 1) {
            day_int = 31;
            if (month_int == 1) {
                month_int = 12;
                if (year_int == 2009)
                    throw std::out_of_range("Error: Bad Input");
                year_int--;
            }
            else 
                month_int--;
        }
        else 
            day_int--;
        date = std::to_string(year_int) + "-" + std::to_string(month_int) + "-" + std::to_string(day_int);
    }
    return (data.at(date));
}

void BitcoinExchange::print_data_of_file(std::string file_src) {
    std::fstream src_fd(file_src);
    std::string line;
    size_t pos_split;
    std::string cur_date;
    double   BTC_val;
    double   BTC_quantity;
    if (!src_fd.is_open())
        throw std::out_of_range("BTC:: data.csv is not accessible");
    while (std::getline(src_fd, line)) {
        pos_split = line.find('|');
        if (pos_split == line.size()) {
            std::cout << "Error: Bad Input";
            continue ;
        }
        try {
            cur_date = line.substr(0, pos_split - 1);
            BTC_val = get_BTC_value_for(cur_date);
            BTC_quantity = std::stod(line.substr(pos_split + 1, line.size()));
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << " => " << cur_date <<'\n';
            continue ;
        }
        if (BTC_quantity < 0) {
            std::cout << "Error: not a positive number.\n";
            continue ;
        }
        if (BTC_quantity > 2147483647) {
            std::cout << "Error: too large a number.\n";
            continue ;  
        }
        std::cout << cur_date << " => " << BTC_quantity << " = " << BTC_quantity * BTC_val << std::endl;
    }
}
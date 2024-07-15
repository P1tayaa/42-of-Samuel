#pragma once
# include <iostream>
# include <map>
# include <string>
#include  <fstream>

const std::string file = "data.csv";

class BitcoinExchange
{
private:
    std::map<std::string, float> data;
    void LoadData();
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void PrintData();
    float get_BTC_value_for(std::string date);
    void print_data_of_file(std::string file_src);
};
# pragma once

# include <iostream>
# include <map>
# include <vector>
# include <sys/socket.h>
# include <sys/select.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <fstream>
# include <sstream>
# include <string>

enum method_type {
    GET,
    POST,
    DELETE,
    HEADER,
};

struct method_path_option {
    public:
        std::string path;
        std::string alias;
        bool autoindex;
        std::map<method_type, bool> method_type_allowed;
};

struct server
{
    public:
    int port;
    std::string name;
    std::string root;
    bool autoindex;
    std::map<int, std::string> error_pages;
    std::string index;
    std::string access_log;
    std::string error_log;
    std::vector<method_path_option> loc_method;
};

struct Parse
{
    std::map<std::string, std::string> basic;
    std::vector<Parse *> servers;
    std::string loc_name;
};

std::vector<server> *make_all_server(std::ifstream &fileToRead);
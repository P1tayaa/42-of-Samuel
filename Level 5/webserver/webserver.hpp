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


struct server
{
    public:
    // std::map<long, std::string>    requests;
    // sockaddr_in    addr;
    // long        fd;
    // long        newSocket;
    // int            addrLen;
    int port;
    std::string name;
    std::string root;
    bool autoindex;
    std::map<int, std::string> error_pages;
    std::string index;
    std::string access_log;
    std::string error_log;
    std::map<std::string, std::map<std::string, std::string>> loc_method;
};

struct Parse
{
    std::map<std::string, std::string> basic;
    std::vector<Parse *> servers;
    std::string loc_name;
};

std::vector<server> *make_all_server(std::ifstream &fileToRead);
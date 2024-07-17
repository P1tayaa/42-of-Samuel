# include "webserver.hpp"

bool is_all_space(std::string str) {
    int i = 0;
    while (str[i])
    {
        if (!isspace(str[i]))
            return false;
        i++;
    }
    return true;
}


std::size_t find_true_start(std::string line) {
    std::size_t i = 0;
    while (isspace(line[i]))
        i++;
    return i;
}

std::size_t find_true_space(std::string line) {
    size_t start =  find_true_start(line);
    std::size_t i = start;
    while (!isspace(line[i]))
        i++;
    i -= start;
    return i;
}


Parse *make_parse(std::ifstream &fileToRead) {
    Parse *my_parse = new Parse;
    std::string buffer;
    std::string no_commants;
    std::string key_word;
    std::size_t space_loc;
    size_t true_start;
    std::getline(fileToRead, buffer, '\n');
    while (buffer.find('}') == std::string::npos) //read all the file lines and write into buffer.
    {
        if (buffer[0] == '#') {

        }
        else if (buffer.find('#') != std::string::npos)
            no_commants = buffer.substr(0, buffer.find('#'));
        else 
            no_commants = buffer;


        if (no_commants.find('{') != std::string::npos) {
            (*my_parse).servers.push_back(make_parse(fileToRead)); // make a new child parse and added it to the vector
        }
        else if (no_commants.find(';')!= std::string::npos) {
            true_start = find_true_start(no_commants);
            space_loc = find_true_space(no_commants);
            key_word = no_commants.substr(true_start, space_loc);
            if ( (*my_parse).basic.find(key_word) != (*my_parse).basic.end()) { // this is to see if it is already an existant key
                (*my_parse).basic[key_word].append(no_commants.substr(space_loc + true_start, no_commants.length())); // if the key already exist I append the new value to the old one with the ;
            }
            else {
                (*my_parse).basic[key_word] = no_commants.substr(space_loc + true_start, no_commants.length());
            }
        } else if (no_commants.find('}')!= std::string::npos) {
            break ;
        }
        else if (!is_all_space(no_commants)) {
            std::cerr << no_commants << "    config wrong\n";
        }

        std::getline(fileToRead, buffer, '\n');
        if (fileToRead.eof())
            break ;
    }
    return my_parse;
}


void print_parse(Parse *my_parse, int num_tab) {
    for (auto it = (*my_parse).basic.cbegin(); it != (*my_parse).basic.cend(); it++) {
        for (int i = 0; i <=num_tab; i++) {
            std::cout << "|---|";
        }
        
        std::cout << "(" << it->first << ")"  << it->second << std::endl;
    }
    unsigned int vecSize = (*my_parse).servers.size();
    // run for loop from 0 to vecSize
    for(unsigned int i = 0; i < vecSize; i++)
    {
        print_parse((*my_parse).servers[i], num_tab + 1);
    }

    // for (Parse *i : (*my_parse).servers) {
    //     print_parse(i);
    // }
}

void    free_parse(Parse *my_parse) {
    unsigned int vecSize = (*my_parse).servers.size();
    // run for loop from 0 to vecSize
    for(unsigned int i = 0; i < vecSize; i++)
    {
        free_parse((*my_parse).servers[i]);
    }
    delete my_parse;
}

// Overloading the << operator for server struct
std::ostream& operator<<(std::ostream& o, const server& s) {
    o << "Server details:\n";
    o << "Port: " << s.port << "\n";
    o << "Name: " << s.name << "\n";
    o << "Root: " << s.root << "\n";
    o << "Autoindex: " << (s.autoindex ? "true" : "false") << "\n";
    o << "Error Pages:\n";
    // for (const auto& ep : s.error_pages) {
    //     o << "  " << ep.first << ": " << ep.second << "\n";
    // }
    o << "Index: " << s.index << "\n";
    o << "Access Log: " << s.access_log << "\n";
    o << "Error Log: " << s.error_log << "\n";
    return o;
}

// Overloading the << operator for vector of servers
std::ostream& operator<<(std::ostream& o, const std::vector<server>& to_printf) {
    for (size_t i = 0; i < to_printf.size(); ++i) {
        o << "Server " << i + 1 << ":\n";
        o << to_printf[i] << "\n";
    }
    return o;
}

std::vector<server > *make_all_server(std::ifstream &fileToRead) {
    Parse *parser = make_parse(fileToRead);
    std::string useless;
    print_parse(parser, 1);
    // pause();
    std::cin >> useless;
    std::vector<server> *all_server = new std::vector<server>;
    size_t i;
    server temp;
    for (i = 0; i < parser->servers.size(); i++) {
        // temp.port = std::stoi((parser->servers[i]->basic)["listen"]);
        temp.name = (parser->servers[i]->basic)["server_name"];
        temp.root = (parser->servers[i]->basic)["root"];
        temp.autoindex = parser->servers[i]->basic["autoindex"] == "on";
        // temp.error_log need a function for that one
        temp.index = parser->servers[i]->basic["index"];
        temp.access_log = parser->servers[i]->basic["access_log"];
        temp.error_log = parser->servers[i]->basic["error_log"];
    }
    std::cout << all_server;
    
    // int            _addrLen = i;

    // // Creating socket file descriptor
    // if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    //     perror("socket failed");
    //     exit(EXIT_FAILURE);
    // }
    //     struct sockaddr_in address;
    // // Attaching socket to the port 8080
    // address.sin_family = AF_INET;
    // address.sin_addr.s_addr = INADDR_ANY;
    // address.sin_port = htons(PORT);
    return all_server;
}


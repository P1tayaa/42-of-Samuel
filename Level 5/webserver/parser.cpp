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

const std::string loc_triger = "location";

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
            if (no_commants.find(loc_triger) != std::string::npos) {
            size_t start = no_commants.find(loc_triger) + loc_triger.size();
            size_t len = start - no_commants.find('{');
                (*my_parse).servers.back()->loc_name =
                    no_commants.substr(start, len);
            }
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
        if (!(*my_parse).servers[i]->loc_name.empty())
            std::cout << "location name is (" << (*my_parse).servers[i]->loc_name << ")\n";
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

const char* MethodToS(method_type v)
{
    switch (v)
    {
        case GET:   return "GET";
        case POST:   return "POST";
        case DELETE: return "DELETE";
        case HEADER: return "HEADER";
        default:      return "[Unknown OS_type]";
    }
}


std::ostream& operator<<(std::ostream& o, const std::map<method_type, bool>& s) {
    method_type temp;
    for (int i = GET; i != HEADER; i++) {
        temp = static_cast<method_type>(i); 
        if (s.find(temp)->second) {
            o << "|" << MethodToS(temp) << "|";
        }
    }
    o << std::endl;
    return o;
}

// Overloading the << operator for server struct
std::ostream& operator<<(std::ostream& o, const server& s) {
    o << "Server details:\n";
    o << "Port: " << s.port << "\n";
    o << "Name: " << s.name << "\n";
    o << "Root: " << s.root << "\n";
    o << "Autoindex: " << (s.autoindex ? "true" : "false") << "\n";
    o << "Error Pages: | ";
    for (auto it = s.error_pages.begin(); it != s.error_pages.end(); it++)
    {
        o << it->first << ": " << it->second << " | ";
    }
    o << std::endl;
    o << "Index: " << s.index << "\n";
    o << "Access Log: " << s.access_log << "\n";
    o << "Error Log: " << s.error_log << "\n";
    for (size_t i = 0; i < s.loc_method.size(); i++)
    {
        o << "Location Method:  path: " << s.loc_method[i].path << " alias: " << s.loc_method[i].alias << std::endl
            << "            auto index: " << s.loc_method[i].autoindex << " method: " << s.loc_method[i].method_type_allowed;
    }
    

    return o;
}

// Overloading the << operator for vector of servers
std::ostream& operator<<(std::ostream& o, const std::vector<server>* to_printf) {
    for (size_t i = 0; i < to_printf->size(); ++i) {
        o << "Server " << i + 1 << ":\n";
        o << (*to_printf)[i] << "\n";
    }
    return o;
}

std::vector<std::string> my_strsplit(std::string src, char delemiter) {
    std::vector<std::string> to_return;// = std::vector<std::string>;
    size_t start = 0;
    // size_t end = src.find(delemiter);
    // while (end == start && end != src.size()) {
    //         start = end + 1;
    //         end = src.find(delemiter, start);
    // }
    // while (end < src.size() && start < end) {
    //     // std::cout << "alive and did \n";
    //     to_return.push_back(src.substr(start, end - start));
    //     start = end + 1;
    //     end = src.find(delemiter, start);
    //     while (end == start && end != src.size()) {
    //         start = end + 1;
    //         end = src.find(delemiter, start);
    //     }
    //     // if (end == std::npo)
    // }
    std::string arg;
    std::istringstream iss(src);
    int i;
    while (std::getline(iss, arg, delemiter)) {
        for (i = 0; i < arg.size(); i++) {
            if (arg[i] != delemiter)
                break;
        }
        if (i == arg.size())
            continue ;
        to_return.push_back(arg);
    }
    return to_return;
}

std::map<int, std::string> treat_error_pages(std::string all) {
    std::vector<std::string> all_config = my_strsplit(all, ';');
    std::vector<std::string> cur_config;
    std::map<int, std::string> to_return;
    int key;
    std::string value;
    for (size_t i = 0; i < all_config.size(); i++) {
        std::cout << "doint this config error page rn (" << all_config[i] << ")\n";
        cur_config = my_strsplit(all_config[i], ' ');
        if (cur_config.size() == 2) {
            try {
                key = std::stoi(cur_config[0]);
                if (to_return.find(key) != to_return.end()) {
                    std::cout << "nooooon don't\n";
                    std::stoi("no!!!!!");
                }
                to_return[key] = cur_config[1];
            }
            catch(const std::exception& e)
            {
                std::cerr << "error_page not a num or dup: ()" << cur_config[0] <<  ") and other value is :" << cur_config[1] <<'\n';
                std::cin >> value;
            }
        } else {
            std::string template_file;
            template_file = cur_config[cur_config.size() - 1];
            size_t loc_x = template_file.find('x'); 
            if (loc_x == template_file.size()) {
                std::cerr << "error_page template doesn't have a x: " << template_file << '\n';
                std::cin >> value;
            }
            for (size_t i = 0; i < cur_config.size() - 1; i++) {
                try {
                    key = std::stoi(cur_config[i]);
                    to_return[key] =
                    template_file.substr(0, template_file.size());
                    to_return[key] = to_return[key].erase(loc_x, 1);
                    to_return[key] = to_return[key].insert(loc_x, cur_config[i]);
                }
                catch(const std::exception& e) {
                    std::cerr << "this error_page isn't a num: (" << cur_config[i] << ") with index of: " << i << '\n';
                    std::cin >> value;
                }
            }
        }
    }
    
    return to_return;
}

std::vector<method_path_option>  treat_loc_method(std::vector<Parse *> method, bool autoindex) {
    std::vector<method_path_option> to_return;
    method_path_option methot_temp;
    std::string temp;
    std::map<std::string, std::string> temp_rules;
    for (size_t i = 0; i < method.size(); i++) {
        methot_temp.autoindex = autoindex;
        if (method[i]->loc_name.empty()) {
            std::cout << "missing location\n";
            std::cin >> temp;
        }
        methot_temp.path = method[i]->loc_name;
        methot_temp.path.erase(methot_temp.path.size() - 2,methot_temp.path.size());
        if (!method[i]->basic["alias"].empty()) {
            methot_temp.alias = method[i]->basic["alias"];
        }
        else {
            methot_temp.alias.clear();
        }
        if (!method[i]->basic["autoindex"].empty()) {
            methot_temp.autoindex = method[i]->basic["autoindex"].find("on") != std::string::npos;
        }
        if (!method[i]->basic["allow"].empty()) {
            methot_temp.method_type_allowed[GET] = (method[i]->basic["allow"]).find("GET") != std::string::npos;
            methot_temp.method_type_allowed[POST] = (method[i]->basic["allow"]).find("POST") != std::string::npos;
            methot_temp.method_type_allowed[DELETE] = (method[i]->basic["allow"]).find("DELETE") != std::string::npos;
            methot_temp.method_type_allowed[HEADER] = (method[i]->basic["allow"]).find("HEADER") != std::string::npos;
        }
        else {
            methot_temp.method_type_allowed[GET] = false;
            methot_temp.method_type_allowed[POST] = false;
            methot_temp.method_type_allowed[DELETE] = false;
            methot_temp.method_type_allowed[HEADER] = false;
        }
        to_return.push_back(methot_temp);
    }
    return to_return;
}

std::vector<server > *make_all_server(std::ifstream &fileToRead) {
    Parse *parser = make_parse(fileToRead);
    std::string useless;
    print_parse(parser, 1);
    // pause();
    std::vector<server> *all_server = new std::vector<server>;
    size_t i;
    server temp;
    for (i = 0; i < parser->servers.size(); i++) {
        // temp.port = std::stoi((parser->servers[i]->basic)["listen"]);
        temp.name = (parser->servers[i]->basic)["server_name"];
        temp.root = (parser->servers[i]->basic)["root"];
        temp.autoindex = parser->servers[i]->basic["autoindex"].find("on");
        temp.error_pages = treat_error_pages(parser->servers[i]->basic["error_page"]);
        // std::cout << "did one errorpage\n";
        // std::cin >> useless;
        temp.index = parser->servers[i]->basic["index"];
        temp.access_log = parser->servers[i]->basic["access_log"];
        temp.error_log = parser->servers[i]->basic["error_log"];
        temp.loc_method = treat_loc_method(parser->servers[i]->servers, temp.autoindex);
        all_server->push_back(temp);
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


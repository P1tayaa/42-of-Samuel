#include "bad_sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "wrong args" << std::endl;
        return (1);
    }
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

	std::ifstream input_file(filename);
	if (!input_file.is_open())
	{
		std::cout << "the file does not exit\n";
		return (1);
	}
    if (s1 == s2)
        return 0;
    size_t  index_found;
    std::string line;
    std::string	finish_replaces;
    while (getline(input_file, line))
    {
        index_found = line.find(s1);
        while (index_found != std::string::npos)
        {
            line.erase(index_found, s1.length());
            line.insert(index_found, s2);
            index_found = line.find(s1, index_found + 1);
        }
		finish_replaces.append(line + '\n');
    }
	std::ofstream output_file;
	output_file.open(filename + ".replace", std::ios::out);
	output_file << finish_replaces;

    return (0);
}
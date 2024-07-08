


#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>

struct Data
{
    uintptr_t _num;
};

class  Serialize
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
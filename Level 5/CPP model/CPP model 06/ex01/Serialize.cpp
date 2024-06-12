
# include "Serialize.hpp"

uintptr_t Serialize::serialize(Data* ptr) {
    uintptr_t temp = (*ptr)._num;
    delete ptr;
    return (temp);
}

Data* Serialize::deserialize(uintptr_t raw) {
    Data    *data = new Data;

    data->_num = raw;
    return (data);
}

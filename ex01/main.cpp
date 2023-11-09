#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    data->s1 = "Hello World!";
    uintptr_t raw = Serializer::serialize(data);
    Data* data2 = Serializer::deserialize(raw);
    std::cout << data2->s1 << std::endl;
    delete data;
    return 0;
}
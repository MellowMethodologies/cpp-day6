#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>

struct Data {
    std::string s1;
};

class Serializer {
    Serializer();
public:
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // Serializer_HPP

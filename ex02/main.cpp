#include "Base.hpp"
#include "A.hpp"   
#include "B.hpp"
#include "C.hpp" 
#include <iostream>

class A;
class B;
class C;

Base * generate(void) {
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown class initiated." << std::endl;
    }
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown class initiated." << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    Base *basePtr = generate();
    Base &baseRef = *basePtr;
    identify(basePtr);
    identify(baseRef);
    delete basePtr;
    return 0;
}
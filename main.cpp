#include <iostream>
#include "bigint.hpp"

using namespace bigint;

int main(){
     BigInt a, b, c;
     a = 1024;
     b = "1024";

     c = a + b;
     std::cout << "a + b = " << c << std::endl;

     // type your aripth

     c = BigInt::pow(a, (int)b);
     std::cout << "Expower a ^ b = " << c << std::endl;

     return 0;
}

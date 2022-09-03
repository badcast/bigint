#include <iostream>

#include "bigint.hpp"

using namespace std;
int main() {
    Bigint h = 3;

    h = Bigint::factorial("3948756");

    mpz_class v;

    cout << "result " << h << "\n";
    return 0;
}

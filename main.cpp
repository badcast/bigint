#include <iostream>

#include "bigint.hpp"

using namespace std;
int main() {
    Bigint h = 3;

    h = Bigint::factorial(Bigint("23059823482348239084320942399432482309489023840239840923"), 10000);

    cout << "result " << h << "\n";
    return 0;
}

#include "BigInteger.h"
#include <iostream>

int main() {
    BigInteger a("200000000000000000000000000");
    BigInteger b("111111111111111111111111111");

    BigInteger sum = a + b;
    BigInteger diff = a - b;
    BigInteger prod = a * b;
    BigInteger quot = a / b;

    std::cout << "Sum: "; sum.print();
    std::cout << "Difference: "; diff.print();
    std::cout << "Product: "; prod.print();
    std::cout << "Quotient: "; quot.print();

    return 0;
}




//TO RUN THE OUTPUT
//g++ BigInteger.cpp main.cpp -o BigIntegerApp
//>> .\BigIntegerApp
# 📊 BigInteger Library in C++

A simple yet powerful C++ library that enables you to perform arithmetic operations on arbitrarily large integers — just like Java's `BigInteger` class!

> ✅ Built entirely using C++ and standard libraries — no external dependencies.

---

## 📑 Table of Contents
- [Features](#-features)
- [Getting Started](#-getting-started)
- [Usage](#-usage-example)
- [Sample Output](#-sample-output)
- [Folder Structure](#-folder-structure)
- [Future Enhancements](#-future-enhancements)
- [Author](#-author)
- [License](#-license)

---

## 🧠 Features

- Add, Subtract, Multiply, and Divide big integers of any length.
- Handles numbers larger than `long long int`.
- Written with clean OOP design using a `BigInteger` class.
- Easy to integrate into other C++ projects.

---

## 🚀 Getting Started

### Prerequisites
- C++ compiler (e.g., g++)
- A code editor (e.g., VS Code)

### Compile & Run

```bash
g++ BigInteger.cpp main.cpp -o BigIntegerApp
./BigIntegerApp

📌 Usage Example

#include "BigInteger.h"

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

🧾 Sample Output

Sum: 311111111111111111111111111
Difference: 88888888888888888888888889
Product: 22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
Quotient: 1

📁 Folder Structure
.
├── BigInteger.h       # Header file
├── BigInteger.cpp     # Implementation
├── main.cpp           # Sample usage
└── README.md

🚧 Future Enhancements
Support for negative numbers

Modulo operation

Comparison operators (<, >, ==)

CMake or Makefile integration

🙋‍♀️ Author
Hirva Rajdev
💼 Aspiring Learner | Loves DSA and C++

📜 License
This project is open-source under the MIT License.
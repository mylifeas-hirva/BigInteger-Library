#include "BigInteger.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

BigInteger::BigInteger(const std::string& num) {
    number = num;
}

void BigInteger::print() const {
    std::cout << number << std::endl;
}

int BigInteger::compare(const std::string& a, const std::string& b) {
    if (a.size() > b.size()) return 1;
    if (a.size() < b.size()) return -1;
    return a.compare(b);
}

std::string BigInteger::addStrings(const std::string& num1, const std::string& num2) {
    std::string result = "";
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int n1 = (i >= 0 ? num1[i--] - '0' : 0);
        int n2 = (j >= 0 ? num2[j--] - '0' : 0);
        int sum = n1 + n2 + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string BigInteger::subtractStrings(const std::string& num1, const std::string& num2) {
    if (compare(num1, num2) < 0) return "-" + subtractStrings(num2, num1);

    std::string result = "";
    int borrow = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0) {
        int n1 = num1[i--] - '0';
        int n2 = (j >= 0 ? num2[j--] - '0' : 0);
        n1 -= borrow;

        if (n1 < n2) {
            n1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back(n1 - n2 + '0');
    }

    while (result.size() > 1 && result.back() == '0') result.pop_back();
    std::reverse(result.begin(), result.end());
    return result;
}

std::string BigInteger::multiplyStrings(const std::string& num1, const std::string& num2) {
    if (num1 == "0" || num2 == "0") return "0";

    std::vector<int> result(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    std::string product = "";
    for (int digit : result) {
        if (!(product.empty() && digit == 0))
            product += (digit + '0');
    }

    return product.empty() ? "0" : product;
}

std::string BigInteger::divideStrings(const std::string& dividend, const std::string& divisor) {
    if (divisor == "0") return "Error";
    if (compare(dividend, divisor) < 0) return "0";
    if (divisor == "1") return dividend;

    std::string result = "", remainder = "";

    for (char digit : dividend) {
        remainder += digit;

        int count = 0;
        while (compare(remainder, divisor) >= 0) {
            remainder = subtractStrings(remainder, divisor);
            count++;
        }

        result += (count + '0');
    }

    // Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

BigInteger BigInteger::operator+(const BigInteger& other) const {
    return BigInteger(addStrings(number, other.number));
}

BigInteger BigInteger::operator-(const BigInteger& other) const {
    return BigInteger(subtractStrings(number, other.number));
}

BigInteger BigInteger::operator*(const BigInteger& other) const {
    return BigInteger(multiplyStrings(number, other.number));
}

BigInteger BigInteger::operator/(const BigInteger& other) const {
    return BigInteger(divideStrings(number, other.number));
}

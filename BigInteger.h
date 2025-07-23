#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>

class BigInteger {
private:
    std::string number;

    static std::string addStrings(const std::string&, const std::string&);
    static std::string subtractStrings(const std::string&, const std::string&);
    static std::string multiplyStrings(const std::string&, const std::string&);
    static std::string divideStrings(const std::string&, const std::string&);
    static int compare(const std::string&, const std::string&);

public:
    BigInteger(const std::string& num);

    BigInteger operator+(const BigInteger&) const;
    BigInteger operator-(const BigInteger&) const;
    BigInteger operator*(const BigInteger&) const;
    BigInteger operator/(const BigInteger&) const;

    void print() const;
};

#endif

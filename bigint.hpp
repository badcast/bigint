#pragma once

#include <gmpxx.h>
#include <cstdio>
#include <string>
#include <type_traits>

namespace bigint {

// main class for Big Integer
class BigInt;

#define _bigint_operator_ui(type) \
    BigInt::operator type() { return static_cast<type>(gmp_mpz.get_ui()); }

#define _bigint_operator_si(type) \
    BigInt::operator type() { return gmp_mpz.get_si(); }

#define _bigint_init(type) \
    BigInt(type value) : gmp_mpz(value) {}

//const BigInt operator+(const BigInt&, const BigInt);
//const BigInt operator-(const BigInt&, const BigInt&);
//const BigInt operator/(const BigInt&, const BigInt&);
//const BigInt operator*(const BigInt&, const BigInt&);
//const BigInt operator%(const BigInt&, const BigInt&);
//const BigInt operator<<(const BigInt&, const BigInt&);
//const BigInt operator>>(const BigInt&, const BigInt&);
//const BigInt operator^(const BigInt&, const BigInt&);
//const BigInt operator&(const BigInt&, const BigInt&);
//const BigInt operator|(const BigInt&, const BigInt&);
//
//bool operator<(const BigInt&, const BigInt&);
//bool operator>(const BigInt&, const BigInt&);
//bool operator==(const BigInt&, const BigInt&);
//bool operator!=(const BigInt&, const BigInt&);

// inline std::ostream& operator<<(std::ostream& o, const BigInt& expr);
// inline std::istream& operator>>(std::istream& i, BigInt& expr);

class BigInt {
   private:
    mpz_class gmp_mpz;

   public:
    class divide_by_zero : public std::exception {};

    BigInt() = default;
    BigInt(const BigInt&) = default;

    _bigint_init(const mpz_class&);
    _bigint_init(const std::string&);
    _bigint_init(const char*);
    _bigint_init(char);
    _bigint_init(short);
    _bigint_init(int);
    _bigint_init(long);
    _bigint_init(unsigned char);
    _bigint_init(unsigned short);
    _bigint_init(unsigned int);
    _bigint_init(unsigned long);

    const mpz_class &get_mpz_class() const;

#if defined(_STL_VECTOR_H) || defined(_GLIBCXX_VECTOR)
    std::vector<unsigned char> getBytes();
#endif
    /* ***operators*** */

    // unary operators
    BigInt operator-() const;
    BigInt& operator--();
    const BigInt operator--(int);
    BigInt& operator++();
    const BigInt operator++(int);
    BigInt operator~();

    BigInt& operator=(const BigInt&);

    BigInt& operator+=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator/=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator<<=(const long);
    BigInt& operator>>=(const long);
    BigInt& operator&=(const BigInt&);
    BigInt& operator|=(const BigInt&);
    BigInt& operator^=(const BigInt&);
    BigInt& operator%=(const BigInt&);

    // operators
    //    friend const BigInt operator+(const BigInt&, const BigInt&);
    //    friend const BigInt operator-(const BigInt&, const BigInt&);
    //    friend const BigInt operator/(const BigInt&, const BigInt&);
    //    friend const BigInt operator*(const BigInt&, const BigInt&);
    //    friend const BigInt operator%(const BigInt&, const BigInt&);
    //    friend const BigInt operator<<(const BigInt&, const BigInt&);
    //    friend const BigInt operator>>(const BigInt&, const BigInt&);
    //    friend const BigInt operator^(const BigInt&, const BigInt&);
    //    friend const BigInt operator&(const BigInt&, const BigInt&);
    //    friend const BigInt operator|(const BigInt&, const BigInt&);

    //    friend bool operator<(const BigInt&, const BigInt&);
    //    friend bool operator>(const BigInt&, const BigInt&);
    //    friend bool operator==(const BigInt&, const BigInt&);
    //    friend bool operator!=(const BigInt&, const BigInt&);

    friend const BigInt operator+(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz + rhs.gmp_mpz); }
    friend const BigInt operator-(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz - rhs.gmp_mpz); }
    friend const BigInt operator/(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz / rhs.gmp_mpz); }
    friend const BigInt operator*(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz * rhs.gmp_mpz); }
    friend const BigInt operator%(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz % rhs.gmp_mpz); }

    friend const BigInt operator<<(const BigInt& lhs, const long long& rhs) { return BigInt(lhs.gmp_mpz << rhs); }
    friend const BigInt operator>>(const BigInt& lhs, const long long& rhs) { return BigInt(lhs.gmp_mpz >> rhs); }
    friend const BigInt operator^(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz ^ rhs.gmp_mpz); }
    friend const BigInt operator&(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz & rhs.gmp_mpz); }
    friend const BigInt operator|(const BigInt& lhs, const BigInt& rhs) { return BigInt(lhs.gmp_mpz | rhs.gmp_mpz); }

    friend bool operator<(const BigInt& lhs, const BigInt& rhs) { return lhs.gmp_mpz < rhs.gmp_mpz; }
    friend bool operator>(const BigInt& lhs, const BigInt& rhs) { return lhs.gmp_mpz > rhs.gmp_mpz; }
    friend bool operator==(const BigInt& lhs, const BigInt& rhs) { return lhs.gmp_mpz == rhs.gmp_mpz; }
    friend bool operator!=(const BigInt& lhs, const BigInt& rhs) { return lhs.gmp_mpz != rhs.gmp_mpz; }

    operator std::string();
    operator char();
    operator short();
    operator int();
    operator long();
    operator long long();
    operator unsigned char();
    operator unsigned short();
    operator unsigned int();
    operator unsigned long();
    operator unsigned long long();

    explicit operator bool();

    operator float();
    operator double();

    void swap(BigInt& rhs);

    // static members

    static BigInt factorial(const BigInt& base);
    static BigInt fibonacci(const BigInt& base);

    static int sign(const BigInt& op);

    static BigInt abs(const BigInt& base);
    static BigInt nabs(const BigInt& base);
    static BigInt sqrt(const BigInt& root);
    static BigInt pow(const BigInt& base, unsigned long long power);

    friend inline std::ostream& operator<<(std::ostream& o, const BigInt& expr);
    friend inline std::istream& operator>>(std::istream& i, BigInt& expr);
};

_bigint_operator_si(char);
_bigint_operator_si(short);
_bigint_operator_si(int);
_bigint_operator_si(long);
_bigint_operator_si(long long);
_bigint_operator_ui(unsigned char);
_bigint_operator_ui(unsigned short);
_bigint_operator_ui(unsigned int);
_bigint_operator_ui(unsigned long);
_bigint_operator_ui(unsigned long long);

BigInt::operator bool() { return gmp_mpz.operator bool(); }

BigInt::operator float() { return gmp_mpz.get_d(); }

BigInt::operator double() { return gmp_mpz.get_d(); }

void BigInt::swap(BigInt& rhs) { this->gmp_mpz.swap(rhs.gmp_mpz); }

const mpz_class& BigInt::get_mpz_class() const { return gmp_mpz; }

#if defined(_STL_VECTOR_H) || defined(_GLIBCXX_VECTOR)
std::vector<unsigned char> BigInt::getBytes() {
    __mpz_struct* _struct = gmp_mpz.__get_mp();
    unsigned long long y = std::abs(_struct->_mp_size) * sizeof(mp_limb_t);
    std::vector<unsigned char> _bytes;
    _bytes.resize(y);
    std::memcpy(_bytes.data(), _struct->_mp_d, y);
    return _bytes;
}
#endif

BigInt BigInt::operator-() const { return BigInt(-this->gmp_mpz); }

BigInt& BigInt::operator--() {
    --gmp_mpz;
    return *this;
}
const BigInt BigInt::operator--(int) {
    BigInt state = *this;
    --gmp_mpz;
    return state;
}
BigInt& BigInt::operator++() {
    ++gmp_mpz;
    return *this;
}
const BigInt BigInt::operator++(int) {
    BigInt state = *this;
    ++gmp_mpz;
    return state;
}
BigInt BigInt::operator~() { return BigInt(gmp_mpz); }

BigInt& BigInt::operator=(const BigInt& rhs){
    gmp_mpz = rhs.gmp_mpz;
    return *this;
}

BigInt& BigInt::operator+=(const BigInt& rhs) {
    gmp_mpz += rhs.gmp_mpz;
    return *this;
}
BigInt& BigInt::operator-=(const BigInt& rhs) {
    gmp_mpz -= rhs.gmp_mpz;
    return *this;
}
BigInt& BigInt::operator/=(const BigInt& rhs) {
    gmp_mpz /= rhs.gmp_mpz;
    return *this;
}
BigInt& BigInt::operator*=(const BigInt& rhs) {
    gmp_mpz *= rhs.gmp_mpz;
    return *this;
}

BigInt& BigInt::operator<<=(const long rhs) {
    gmp_mpz <<= rhs;
    return *this;
}
BigInt& BigInt::operator>>=(const long rhs) {
    gmp_mpz >>= rhs;
    return *this;
}
BigInt& BigInt::operator&=(const BigInt& rhs) {
    gmp_mpz &= rhs.gmp_mpz;
    return *this;
}
BigInt& BigInt::operator|=(const BigInt& rhs) {
    gmp_mpz |= rhs.gmp_mpz;
    return *this;
}
BigInt& BigInt::operator^=(const BigInt& rhs) {
    gmp_mpz ^= rhs.gmp_mpz;
    return *this;
}
BigInt& BigInt::operator%=(const BigInt& rhs) {
    gmp_mpz %= rhs.gmp_mpz;
    return *this;
}

/**************** I/O operators ****************/

inline std::ostream& operator<<(std::ostream& output, const BigInt& expr) { return output << expr.gmp_mpz; }
inline std::istream& operator>>(std::istream& input, BigInt& expr) { return input >> expr.gmp_mpz; }

/****************   functions   ****************/
BigInt BigInt::factorial(const BigInt& base) { return BigInt(::factorial(base.gmp_mpz)); }
BigInt BigInt::fibonacci(const BigInt& base) { return BigInt(::fibonacci(base.gmp_mpz)); }

int BigInt::sign(const BigInt& op) { return sgn(op.gmp_mpz); }

BigInt BigInt::abs(const BigInt& base) { return BigInt(::abs(base.gmp_mpz)); }
BigInt BigInt::nabs(const BigInt& base) { return (sign(base) < 0 ? base : -base); }
BigInt BigInt::sqrt(const BigInt& root) { return BigInt(::sqrt(root.gmp_mpz));}
BigInt BigInt::pow(const BigInt& base, unsigned long long power) {
    BigInt op = 1;
    while (power--) op *= base;
    return op;
}

void swap(BigInt& lhs, BigInt& rhs) { lhs.swap(rhs); }

#undef _bigint_init
#undef _bigint_operator
}  // namespace bigint

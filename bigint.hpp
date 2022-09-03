#pragma once

#include <gmpxx.h>

#include <cstdio>
#include <string>
#include <type_traits>

// main class for Big Integer
class Bigint;

#define _bigint_operator_ui(type) \
    Bigint::operator type() { return static_cast<type>(gmp_mpz.get_ui()); }

#define _bigint_operator_si(type) \
    Bigint::operator type() { return gmp_mpz.get_si(); }

#define _bigint_init(type) \
    Bigint(type value) : gmp_mpz(value) {}

const Bigint operator+(const Bigint&, const Bigint&);
const Bigint operator-(const Bigint&, const Bigint&);
const Bigint operator/(const Bigint&, const Bigint&);
const Bigint operator*(const Bigint&, const Bigint&);
const Bigint operator%(const Bigint&, const Bigint&);
const Bigint operator<<(const Bigint&, const Bigint&);
const Bigint operator>>(const Bigint&, const Bigint&);
const Bigint operator^(const Bigint&, const Bigint&);
const Bigint operator&(const Bigint&, const Bigint&);
const Bigint operator|(const Bigint&, const Bigint&);

bool operator<(const Bigint&, const Bigint&);
bool operator>(const Bigint&, const Bigint&);
bool operator==(const Bigint&, const Bigint&);
bool operator!=(const Bigint&, const Bigint&);

inline std::ostream& operator<<(std::ostream& o, const Bigint& expr);
inline std::istream& operator>>(std::istream& i, Bigint& expr);

class Bigint {
   private:
    mpz_class gmp_mpz;

   public:
    class divide_by_zero : public std::exception {};

    _bigint_init(const mpz_class&);
    _bigint_init(const std::string&);
    _bigint_init(const char*);
    _bigint_init(const char);
    _bigint_init(const short);
    _bigint_init(const int);
    _bigint_init(const long);
    _bigint_init(const unsigned char);
    _bigint_init(const unsigned short);
    _bigint_init(const unsigned int);
    _bigint_init(const unsigned long);

    mpz_class* get_mpz_class();

    /* ***operators*** */

    // unary operators
    const Bigint operator-();
    Bigint& operator--();
    const Bigint operator--(int);
    Bigint& operator++();
    const Bigint operator++(int);
    Bigint operator~();

    Bigint& operator+=(const Bigint&);
    Bigint& operator-=(const Bigint&);
    Bigint& operator/=(const Bigint&);
    Bigint& operator*=(const Bigint&);
    Bigint& operator<<=(const long);
    Bigint& operator>>=(const long);
    Bigint& operator&=(const Bigint&);
    Bigint& operator|=(const Bigint&);
    Bigint& operator^=(const Bigint&);
    Bigint& operator%=(const Bigint&);

    // operators
    friend const Bigint operator+(const Bigint&, const Bigint&);
    friend const Bigint operator-(const Bigint&, const Bigint&);
    friend const Bigint operator/(const Bigint&, const Bigint&);
    friend const Bigint operator*(const Bigint&, const Bigint&);
    friend const Bigint operator%(const Bigint&, const Bigint&);
    friend const Bigint operator<<(const Bigint&, const Bigint&);
    friend const Bigint operator>>(const Bigint&, const Bigint&);
    friend const Bigint operator^(const Bigint&, const Bigint&);
    friend const Bigint operator&(const Bigint&, const Bigint&);
    friend const Bigint operator|(const Bigint&, const Bigint&);

    friend bool operator<(const Bigint&, const Bigint&);
    friend bool operator>(const Bigint&, const Bigint&);
    friend bool operator==(const Bigint&, const Bigint&);
    friend bool operator!=(const Bigint&, const Bigint&);

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

    // static members

    static Bigint factorial(const Bigint& base);
    static Bigint fibonacci(const Bigint& base);

    static Bigint abs(const Bigint& base);
    static Bigint nabs(const Bigint& base);
    static mpf_class sqrt(const Bigint& root);
    static Bigint pow(const Bigint& base, int power);

    friend inline std::ostream& operator<<(std::ostream& o, const Bigint& expr);

    friend inline std::istream& operator>>(std::istream& i, Bigint& expr);
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

Bigint::operator float() { return gmp_mpz.get_d(); }

Bigint::operator double() { return gmp_mpz.get_d(); }

Bigint::operator bool() { return gmp_mpz.operator bool(); }

mpz_class* Bigint::get_mpz_class() { return &gmp_mpz; }

const Bigint Bigint::operator-() { return Bigint(-this->gmp_mpz); }
Bigint& Bigint::operator--() {
    --gmp_mpz;
    return *this;
}
const Bigint Bigint::operator--(int) {
    Bigint state = *this;
    --gmp_mpz;
    return state;
}
Bigint& Bigint::operator++() {
    ++gmp_mpz;
    return *this;
}
const Bigint Bigint::operator++(int) {
    Bigint state = *this;
    ++gmp_mpz;
    return state;
}
Bigint Bigint::operator~() { return Bigint(gmp_mpz); }

Bigint& Bigint::operator+=(const Bigint& rhs) {
    gmp_mpz += rhs.gmp_mpz;
    return *this;
}
Bigint& Bigint::operator-=(const Bigint& rhs) {
    gmp_mpz -= rhs.gmp_mpz;
    return *this;
}
Bigint& Bigint::operator/=(const Bigint& rhs) {
    gmp_mpz /= rhs.gmp_mpz;
    return *this;
}
Bigint& Bigint::operator*=(const Bigint& rhs) {
    gmp_mpz *= rhs.gmp_mpz;
    return *this;
}

Bigint& Bigint::operator<<=(const long rhs) {
    gmp_mpz <<= rhs;
    return *this;
}
Bigint& Bigint::operator>>=(const long rhs) {
    gmp_mpz >>= rhs;
    return *this;
}
Bigint& Bigint::operator&=(const Bigint& rhs) {
    gmp_mpz &= rhs.gmp_mpz;
    return *this;
}
Bigint& Bigint::operator|=(const Bigint& rhs) {
    gmp_mpz |= rhs.gmp_mpz;
    return *this;
}
Bigint& Bigint::operator^=(const Bigint& rhs) {
    gmp_mpz ^= rhs.gmp_mpz;
    return *this;
}
Bigint& Bigint::operator%=(const Bigint& rhs) {
    gmp_mpz %= rhs.gmp_mpz;
    return *this;
}

const Bigint operator+(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz + rhs.gmp_mpz); }
const Bigint operator-(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz - rhs.gmp_mpz); }
const Bigint operator/(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz / rhs.gmp_mpz); }
const Bigint operator*(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz * rhs.gmp_mpz); }
const Bigint operator%(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz % rhs.gmp_mpz); }

const Bigint operator<<(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz << rhs.gmp_mpz); }
const Bigint operator>>(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz >> rhs.gmp_mpz); }
const Bigint operator^(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz ^ rhs.gmp_mpz); }
const Bigint operator&(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz & rhs.gmp_mpz); }
const Bigint operator|(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz | rhs.gmp_mpz); }

bool operator<(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz < rhs.gmp_mpz; }
bool operator>(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz > rhs.gmp_mpz; }
bool operator==(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz == rhs.gmp_mpz; }
bool operator!=(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz != rhs.gmp_mpz; }

/**************** I/O operators ****************/

// these should (and will) be provided separately
inline std::ostream& operator<<(std::ostream& output, const Bigint& expr) { return output << expr.gmp_mpz; }
inline std::istream& operator>>(std::istream& input, Bigint& expr) { return input >> expr.gmp_mpz; }

Bigint Bigint::factorial(const Bigint& base) { return Bigint(::factorial(base.gmp_mpz)); }
Bigint Bigint::fibonacci(const Bigint& base) { return Bigint(::fibonacci(base.gmp_mpz)); }

Bigint Bigint::abs(const Bigint& base) {}
Bigint Bigint::nabs(const Bigint& base) {}
mpf_class Bigint::sqrt(const Bigint& root) { return ::sqrt(root.gmp_mpz); }
Bigint Bigint::pow(const Bigint& base, int power) {}

#undef _bigint_init
#undef _bigint_operator

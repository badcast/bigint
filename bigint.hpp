#pragma once

#include <gmpxx.h>

#include <cstdio>
#include <string>
#include <type_traits>

// main class for Big Integer
class Bigint;

#define _bigint_operator(type)                          \
    Bigint::operator type() {                           \
        if constexpr (std::is_unsigned<type>()) {       \
            return static_cast<type>(gmp_mpz.get_ui()); \
        } else {                                        \
            return gmp_mpz.get_si();                    \
        }                                               \
    }

#define _bigint_init(type) \
    Bigint::Bigint(const type& value) : gmp_mpz(value) {}

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

    Bigint(const mpz_class&);

    Bigint(const std::string&);
    Bigint(const char&);
    Bigint(const short&);
    Bigint(const int&);
    Bigint(const long&);
    Bigint(const unsigned char&);
    Bigint(const unsigned short&);
    Bigint(const unsigned int&);
    Bigint(const unsigned long&);

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
    operator long double();

    // static members

    static Bigint factorial(const Bigint& base, long l);
    static Bigint fibonacci(const Bigint& base, long l);
    static Bigint factorial(const Bigint& base, unsigned long l);
    static Bigint fibonacci(const Bigint& base, unsigned long l);

    static Bigint abs(const Bigint& base);
    static Bigint nabs(const Bigint& base);
    static mpf_class sqrt(const Bigint& root);
    static Bigint pow(const Bigint& base, int power);

    friend inline std::ostream& operator<<(std::ostream& o, const Bigint& expr);

    friend inline std::istream& operator>>(std::istream& i, Bigint& expr);
};

_bigint_init(std::string);
_bigint_init(mpz_class);
_bigint_init(char);
_bigint_init(short);
_bigint_init(int);
_bigint_init(long);
_bigint_init(unsigned char);
_bigint_init(unsigned short);
_bigint_init(unsigned int);
_bigint_init(unsigned long);

_bigint_operator(char);
_bigint_operator(short);
_bigint_operator(int);
_bigint_operator(long);
_bigint_operator(long long);
_bigint_operator(unsigned char);
_bigint_operator(unsigned short);
_bigint_operator(unsigned int);
_bigint_operator(unsigned long);
_bigint_operator(unsigned long long);
_bigint_operator(float);
_bigint_operator(double);
_bigint_operator(long double);

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

Bigint Bigint::factorial(const Bigint& base, long l) { return Bigint(::factorial(base.gmp_mpz, l)); }
Bigint Bigint::factorial(const Bigint& base, unsigned long l) { return ::factorial(base.gmp_mpz, l); }
Bigint Bigint::fibonacci(const Bigint& base, long l) { return ::fibonacci(base.gmp_mpz, l); }
Bigint Bigint::fibonacci(const Bigint& base, unsigned long l) { return ::fibonacci(base.gmp_mpz, l); }

Bigint Bigint::abs(const Bigint& base) {}
Bigint Bigint::nabs(const Bigint& base) {}
mpf_class Bigint::sqrt(const Bigint& root) { return ::sqrt(root.gmp_mpz); }
Bigint Bigint::pow(const Bigint& base, int power) {}

#undef _bigint_init
#undef _bigint_operator

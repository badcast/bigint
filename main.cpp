#include <gmpxx.h>

#include <cstring>
#include <iostream>
#include <string>
#include <type_traits>

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
bool operator<(const Bigint&, const Bigint&);
bool operator>(const Bigint&, const Bigint&);
bool operator==(const Bigint&, const Bigint&);
bool operator!=(const Bigint&, const Bigint&);

template <class T, class U>
inline std::ostream& operator<<(std::ostream& o, const Bigint& expr);

template <class T>
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

    // operators

    // unary operators
    // const bigint operator-();
    // const bigint& operator--();
    // const bigint& operator++();

    // operators
    friend const Bigint operator+(const Bigint&, const Bigint&);
    friend const Bigint operator-(const Bigint&, const Bigint&);
    friend const Bigint operator/(const Bigint&, const Bigint&);
    friend const Bigint operator*(const Bigint&, const Bigint&);
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

    operator float();
    operator double();
    operator long double();

    // static members
    template <typename L>
    static Bigint factorial(const Bigint& base, L l);
    template <typename L>
    static Bigint fibonacci(const Bigint& base, L l);
    static Bigint abs(const Bigint& base);
    static Bigint nabs(const Bigint& base);
    static mpf_class sqrt(const Bigint& root);
    static Bigint pow(const Bigint& base, int power);

    template <class T, class U>
    friend inline std::ostream& operator<<(std::ostream& o, const Bigint& expr);

    template <class T>
    friend inline std::istream& operator>>(std::istream& i, Bigint& expr);

    //  inline static const bigint zero(0);
    //  inline static const bigint one(1);
    //  inline static const bigint minusOne(-1);
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

const Bigint operator+(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz + rhs.gmp_mpz); }
const Bigint operator-(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz - rhs.gmp_mpz); }
const Bigint operator/(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz / rhs.gmp_mpz); }
const Bigint operator*(const Bigint& lhs, const Bigint& rhs) { return Bigint(lhs.gmp_mpz * rhs.gmp_mpz); }
bool operator<(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz < rhs.gmp_mpz; }
bool operator>(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz > rhs.gmp_mpz; }
bool operator==(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz == rhs.gmp_mpz; }
bool operator!=(const Bigint& lhs, const Bigint& rhs) { return lhs.gmp_mpz != rhs.gmp_mpz; }

/**************** I/O operators ****************/

// these should (and will) be provided separately

template <class T, class U>
inline std::ostream& operator<<(std::ostream& o, const Bigint& expr) {
    return o << expr.gmp_mpz;
}

template <class T>
inline std::istream& operator>>(std::istream& i, Bigint& expr) {
    return i >> expr.gmp_mpz;
}

template <typename L>
Bigint Bigint::factorial(const Bigint& base, L l) {
    return ::factorial(base.gmp_mpz, l);
}
template <typename L>
Bigint Bigint::fibonacci(const Bigint& base, L l) {
    return ::fibonacci(base.gmp_mpz, l);
}
Bigint Bigint::abs(const Bigint& base) {}
Bigint Bigint::nabs(const Bigint& base) {}
mpf_class Bigint::sqrt(const Bigint& root) {}
Bigint Bigint::pow(const Bigint& base, int power) {}

#undef _bigint_init
#undef _bigint_operator

using namespace std;
int main() {
    Bigint h = 3;

    h = Bigint::factorial(Bigint("23059823482348239084320942399432482309489023840239840923"), 10000);

    cout << "result " << h << "\n";
    return 0;
}

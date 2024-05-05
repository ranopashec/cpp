#ifndef LAB6_RATIONAL_H
#define LAB6_RATIONAL_H
#include <cmath>
#include <memory>
#include <numeric>
#include <iostream>

long long Gcd(long long a, long long b);

class Rational {
private:
    long long n, d;
public:

    Rational() : n (0), d(1) {}

    Rational(long long n, long long d = 1);

    operator float() { return ((float) n) / d; } // NOLINT

    operator double() { return ((double) n) / d; } // NOLINT

    friend Rational operator+(const Rational &lhs, const Rational &rhs);

    friend Rational operator-(const Rational &lhs, const Rational &rhs);

    friend Rational operator*(const Rational &lhs, const Rational &rhs);

    friend Rational operator*(int lhs, const Rational &rhs);

    friend Rational operator*(const Rational &rhs, int lhs);

    friend Rational operator/(const Rational &lhs, const Rational &rhs);

    // составные операторы присваивания.
    friend Rational operator*=(Rational &lhs, const Rational &rhs);

    friend Rational operator-=(Rational &lhs, const Rational &rhs);

    friend Rational operator+=(Rational &lhs, const Rational &rhs);

    friend Rational operator/=(Rational &lhs, const Rational &rhs);

    bool operator==(const Rational &f) const;

    bool operator!=(const Rational &f) const;

    bool operator<(const Rational &f) const;

    bool operator>(const Rational &f) const;

    bool operator<=(const Rational &f) const;

    bool operator>=(const Rational &f) const;

    // bool operator==(size_t s) const;
    // auto operator<=>(size_t s) const;
    // friend bool operator==(size_t s, Rational &f);
    // friend auto operator<=>(size_t s, Rational &f);
    // bool operator==(double d) const;
    // auto operator<=>(double d) const;
    // friend bool operator==(double d, Rational &f);
    // friend auto operator<=>(double d, Rational &f);

    friend std::ostream &operator<<(std::ostream &strm, const Rational &a);

    friend std::istream &operator>>(std::istream &is, Rational &a);

    Rational operator!(); // обратная дробь

    Rational &operator++();

    Rational operator++(int);

    Rational &operator--();

    Rational operator--(int);

    Rational& operator=(const Rational &oth);
};

#endif

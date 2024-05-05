#include "rational.h"


long long Gcd(long long a, long long b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

Rational::Rational(long long num, long long dom) : n(num), d(dom) {
    if (dom == 0) throw std::runtime_error("denominator can't be 0");
    if (d == 0) {
        throw std::runtime_error("d may not be 0.");
    } else if (n == 0) {
        n = 0;
        d = 1;
    } else {
        int sign = 1;
        if (n < 0) {
            sign *= -1;
            n *= -1;
        }
        if (d < 0) {
            sign *= -1;
            d *= -1;
        }
        long long tmp = Gcd(n, d);
        n = n / tmp * sign;
        d = d / tmp;
    }
}


bool Rational::operator==(const Rational &f) const {
    return n == f.n && d == f.d;
}

bool Rational::operator!=(const Rational &f) const {
    return n != f.n || d != f.d;
}

bool Rational::operator<(const Rational &f) const {
    return n * f.d < f.n * d;
}

bool Rational::operator>(const Rational &f) const {
    return n * f.d > f.n * d;
}

bool Rational::operator<=(const Rational &f) const {
    return n * f.d <= f.n * d;
}

bool Rational::operator>=(const Rational &f) const {
    return n * f.d >= f.n * d;
}

Rational &Rational::operator++() {
    n += d;
    return *this;
}

Rational Rational::operator++(int) {
    Rational tmp = *this;
    n += d;
    return tmp;
}

Rational &Rational::operator--() {
    n -= d;
    return *this;
}

Rational Rational::operator--(int) {
    Rational tmp = *this;
    n -= d;
    return tmp;
}


Rational Rational::operator!() {
    Rational tmp(d, n); // NOLINT
    *this = tmp;
    return *this;
}


Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational tmp(lhs.n * rhs.d
                 + rhs.n * lhs.d,
                 lhs.d * rhs.d);
    return tmp;
}

Rational operator+=(Rational &lhs, const Rational &rhs) {
    Rational tmp(lhs.n * rhs.d
                 + rhs.n * lhs.d,
                 lhs.d * rhs.d);
    lhs = tmp;
    return lhs;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    Rational tmp(lhs.n * rhs.d
                 - rhs.n * lhs.d,
                 lhs.d * rhs.d);
    return tmp;
}

Rational operator-=(Rational &lhs, const Rational &rhs) {
    Rational tmp(lhs.n * rhs.d
                 - rhs.n * lhs.d,
                 lhs.d * rhs.d);
    lhs = tmp;
    return lhs;
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational tmp(lhs.n * rhs.n,
                 lhs.d * rhs.d);
    return tmp;
}

Rational operator*=(Rational &lhs, const Rational &rhs) {
    Rational tmp(lhs.n * rhs.n,
                 lhs.d * rhs.d);
    lhs = tmp;
    return lhs;
}

Rational operator*(int lhs, const Rational &rhs) {
    Rational tmp(lhs * rhs.n, rhs.d);
    return tmp;
}

Rational operator*(const Rational &rhs, int lhs) {
    Rational tmp(lhs * rhs.n, rhs.d);
    return tmp;
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    if(rhs.n == 0){
        throw std::runtime_error("division by zero");
    }
    Rational trhs (rhs);
    return lhs * !trhs;
}

std::ostream &operator<<(std::ostream &strm, const Rational &a) {
    if (a.d == 1) {
        strm << a.n;
    } else {
        strm << a.n << "/" << a.d;
    }
    return strm;
}

/* can read 2/5 to fraction */
std::istream &operator>>(std::istream &is, Rational &a) {
    std::string str;
    getline(is, str);

    bool den = false;
    std::string word{};
    long long tmn{};
    long long tmd{};
    for (char i : str) {
        if (i == '/') {
            tmn = strtoll(word.data(), nullptr, 0);
            word = "";
            den = true;
        } else word += i;
    }
    if (!den) {
        tmn = strtoll(word.data(), nullptr, 0);
        tmd = 1;
    } else {
        tmd = strtoll(word.data(), nullptr, 0);
    }
    a = Rational(tmn, tmd);
    return is;
}

Rational &Rational::operator=(const Rational &oth) = default;

Rational operator/=(Rational &lhs, const Rational &rhs){
    lhs = lhs / rhs;
    return lhs;
}

#include "fraction.h"


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

Fraction::Fraction(long long num, long long dom) : n(num), d(dom) {
    if (d == 0) {
        throw MyException("d may not be 0."); // NOLINT
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


bool Fraction::operator==(const Fraction &f) const {
    return n == f.n && d == f.d;
}

bool Fraction::operator!=(const Fraction &f) const {
    return n != f.n || d != f.d;
}

bool Fraction::operator<(const Fraction &f) const {
    return n * f.d < f.n * d;
}

bool Fraction::operator>(const Fraction &f) const {
    return n * f.d > f.n * d;
}

bool Fraction::operator<=(const Fraction &f) const {
    return n * f.d <= f.n * d;
}

bool Fraction::operator>=(const Fraction &f) const {
    return n * f.d >= f.n * d;
}

Fraction &Fraction::operator++() {
    n += d;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction tmp = *this;
    n += d;
    return tmp;
}

Fraction &Fraction::operator--() {
    n -= d;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction tmp = *this;
    n -= d;
    return tmp;
}


Fraction Fraction::operator!() {
    Fraction tmp(d, n); // NOLINT
    *this = tmp;
    return *this;
}


Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.n * rhs.d
                 + rhs.n * lhs.d,
                 lhs.d * rhs.d);
    return tmp;
}

Fraction operator+=(Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.n * rhs.d
                 + rhs.n * lhs.d,
                 lhs.d * rhs.d);
    lhs = tmp;
    return lhs;
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.n * rhs.d
                 - rhs.n * lhs.d,
                 lhs.d * rhs.d);
    return tmp;
}

Fraction operator-=(Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.n * rhs.d
                 - rhs.n * lhs.d,
                 lhs.d * rhs.d);
    lhs = tmp;
    return lhs;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.n * rhs.n,
                 lhs.d * rhs.d);
    return tmp;
}

Fraction operator*=(Fraction &lhs, const Fraction &rhs) {
    Fraction tmp(lhs.n * rhs.n,
                 lhs.d * rhs.d);
    lhs = tmp;
    return lhs;
}

Fraction operator*(int lhs, const Fraction &rhs) {
    Fraction tmp(lhs * rhs.n, rhs.d);
    return tmp;
}

Fraction operator*(const Fraction &rhs, int lhs) {
    Fraction tmp(lhs * rhs.n, rhs.d);
    return tmp;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
    if(rhs.n == 0){
        throw MyException("division by zero");
    }
    Fraction trhs (rhs);
    return lhs * !trhs;
}

std::ostream &operator<<(std::ostream &strm, const Fraction &a) {
    if (a.d == 1) {
        strm << a.n;
    } else {
        strm << a.n << "/" << a.d;
    }
    return strm;
}

std::istream &operator>>(std::istream &is, Fraction &a) {
    std::string str;
    getline(is, str);

    bool den = false;
    std::string word{};
    long long tmn{};
    long long tmd{};
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '/') {
            tmn = strtoll(word.data(), nullptr, 0);
            word = "";
            den = true;
            continue;
        }
        if (!den) {
            word += str[i];
        } else {
            word += str[i];
        }
    }
    if (!den) {
        tmn = strtoll(word.data(), nullptr, 0);
        tmd = 1;
    } else {
        tmd = strtoll(word.data(), nullptr, 0);
    }
    a = Fraction(tmn, tmd);
    return is;
}

Fraction &Fraction::operator=(const Fraction &oth) {
    n = oth.n;
    d = oth.d;
    return *this;
}

Fraction operator/=(Fraction &lhs, const Fraction &rhs){
    lhs = lhs / rhs;
    return lhs;
}

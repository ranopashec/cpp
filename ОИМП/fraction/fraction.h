#ifndef FRACTION_H
#define FRACTION_H

#include <cmath>
#include <memory>
#include <numeric>
#include <iostream>

// Для обработки исключительных ситуаций использовать собственный класс
// (можно простейший вариант).
class MyException {
public:
    MyException(char *msg) : cho(msg) {}

    char *what() { return cho; }

private:
    char *cho;
};

long long Gcd(long long a, long long b);

class Fraction {
private:
    long long n, d;
public:

    Fraction() : n (0), d(1) {}

    Fraction(long long n, long long d);

    // приведение к вещественному типу
    operator float() { return ((float) n) / d; } // NOLINT

    operator double() { return ((double) n) / d; } // NOLINT

    // Реализовать все возможные арифметические операторы над дробями
    friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);

    friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);

    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);

    friend Fraction operator*(int lhs, const Fraction &rhs);

    friend Fraction operator*(const Fraction &rhs, int lhs);

    friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);

    // составные операторы присваивания.
    friend Fraction operator*=(Fraction &lhs, const Fraction &rhs);

    friend Fraction operator-=(Fraction &lhs, const Fraction &rhs);

    friend Fraction operator+=(Fraction &lhs, const Fraction &rhs);

    friend Fraction operator/=(Fraction &lhs, const Fraction &rhs);

    // операторы сравнения
    bool operator==(const Fraction &f) const;

    bool operator!=(const Fraction &f) const;

    bool operator<(const Fraction &f) const;

    bool operator>(const Fraction &f) const;

    bool operator<=(const Fraction &f) const;

    bool operator>=(const Fraction &f) const;

    // bool operator==(size_t s) const;
    // auto operator<=>(size_t s) const;
    // friend bool operator==(size_t s, Fraction &f);
    // friend auto operator<=>(size_t s, Fraction &f);
    // bool operator==(double d) const;
    // auto operator<=>(double d) const;
    // friend bool operator==(double d, Fraction &f);
    // friend auto operator<=>(double d, Fraction &f);

    // ввод с потока
    friend std::ostream &operator<<(std::ostream &strm, const Fraction &a);

    // вывод в поток
    friend std::istream &operator>>(std::istream &is, Fraction &a);

    // унарный минус оператор отрицания перегрузить, как оператор получения обратной дроби
    Fraction operator!();

    // инкремента и декремента
    Fraction &operator++();

    Fraction operator++(int);

    Fraction &operator--();

    Fraction operator--(int);

// оператор присваивания
    Fraction& operator=(const Fraction &oth);
};

#endif

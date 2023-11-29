#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Exception{
public:
    Exception(char* w) : ex(w){}
    char* What() const{
        return ex;
    }
private:
    char* ex;
};

class matrix {
    size_t m, n;
    double** p;
public:
    matrix(); // конструктор по умолчанию
    matrix(size_t m, size_t n); // конструктор с параметрами
    matrix(const matrix&); // конструктор копирования
    ~matrix(); // деструктор
    // оператор присваивания;
    matrix& operator=(const matrix&);
    // составные операторы присваивания;
    matrix& operator+=(matrix m);
    matrix& operator-=(matrix m);
    matrix& operator*=(matrix m);
    matrix& operator+=(double val);
    matrix& operator-=(double val);
    matrix& operator*=(double val);
    matrix& operator/=(double val);
    // умножение на константу слева;
    friend matrix operator*(const matrix a, const double val);
    // умножение на константу справа;
    friend matrix operator*(const double val, const matrix a);
    // деление на константу;
    friend matrix operator/(const matrix a, const double val);
    // сложение матриц;
    friend matrix operator+(const matrix a, const matrix b);
    // вычитание матриц;
    friend matrix operator-(const matrix a, const matrix b);
    // умножение матриц;
    friend matrix operator*(const matrix a, const matrix b);
    // сравнение матриц на равенство и неравенство;
    friend bool operator!=(const matrix& a, const matrix& b);
    friend bool operator==(const matrix& a, const matrix& b);
    // вывод в поток
    friend std::ostream &operator<<(std::ostream &strm, const matrix &a);
    // ввод с потока
    friend std::istream &operator>>(std::istream &is, matrix &a);
    friend void out (matrix &a);
};
#endif //INC_231113_MATRIX_H


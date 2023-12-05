#include "matrix.h"
#include <iostream>

matrix::matrix() {
    p = nullptr;
    n = 0;
    m = 0;
}

matrix::matrix(size_t mi, size_t ni) : m(mi), n(ni) {
    p = new double*[m];
    for (size_t i = 0; i < m; ++i) {
        p[i] = new double[n]{};
    }
}
matrix& matrix::operator=(const matrix& mat){
    if (p == mat.p){
        return *this;
    }
    this->~matrix();
    m = mat.m;
    n = mat.n;
    p = new double *[m];
    for (size_t i = 0; i < m; ++i) {
        p[i] = new double[n]{};
        for (size_t j = 0; j < n; ++j) {
            p[i][j] = mat.p[i][j];
        }
    }
    return *this;
}


matrix::matrix(const matrix &mat) {
    m = mat.m;
    n = mat.n;
    p = new double *[mat.m];
    for (size_t i = 0; i < m; ++i) {
        p[i] = new double[n]{};
        for (size_t j = 0; j < n; ++j) {
            p[i][j] = mat.p[i][j];
        }
    }
}

matrix::~matrix() {
    if (p != nullptr) {
        for (size_t i = 0; i < m; ++i) {
            delete p[i];
        }
        delete p;
    }
}

// составные операторы присваивания;
matrix& matrix::operator+=(matrix m){
    *this = (*this + m);
    return *this;
}

matrix& matrix::operator-=(matrix m){
    *this = (*this - m);
    return *this;

}

matrix& matrix::operator*=(matrix m){
    *this = (*this * m);
    return *this;
}

matrix& matrix::operator*=(double m){
    *this = (*this * m);
    return *this;
}

matrix& matrix::operator/=(double m){
    *this = (*this / m);
    return *this;
}

// умножение на константу слева;
matrix operator*(const matrix a, const double val) {
    matrix ret{a.m, a.n};
    for (size_t i = 0; i < ret.m; ++i) {
        for (size_t j = 0; j < ret.n; ++j) {
            ret.p[i][j] = a.p[i][j] * val;
        }
    }
    return ret;
}

// умножение на константу справа;
matrix operator*(const double val, const matrix a) {
    matrix ret{a.m, a.n};
    for (size_t i = 0; i < ret.m; ++i) {
        for (size_t j = 0; j < ret.n; ++j) {
            ret.p[i][j] = a.p[i][j] * val;
        }
    }
    return ret;
}

// деление на константу;
matrix operator/(const matrix a, const double val) {
    if (val == 0) {
        throw Exception{"ploho delish"};
    }
    matrix ret{a.m, a.n};
    for (size_t i = 0; i < ret.m; ++i) {
        for (size_t j = 0; j < ret.n; ++j) {
            ret.p[i][j] = a.p[i][j] / val;
        }
    }
    return ret;
}

// сложение матриц;
matrix operator+(const matrix a, const matrix b) {
    if (a.m != b.m || a.n != b.n) {
        throw Exception{"not equal"};
    }
    matrix ret{a.m, a.n};
    for (size_t i = 0; i < ret.m; ++i) {
        for (size_t j = 0; j < ret.n; ++j) {
            ret.p[i][j] = a.p[i][j] + b.p[i][j];
        }
    }
    return ret;
}

// вычитание матриц;
matrix operator-(const matrix a, const matrix b) {

    if (a.m != b.m || a.n != b.n) {
        throw Exception{"not equal"};
    }
    matrix ret{a.m, a.n};
    for (size_t i = 0; i < ret.m; ++i) {
        for (size_t j = 0; j < ret.n; ++j) {
            ret.p[i][j] = a.p[i][j] - b.p[i][j];
        }
    }
    return ret;

}

// умножение матриц;
matrix operator*(const matrix a, const matrix b) {
    {
        if (a.n != b.m) {
            throw Exception{"not equal to multiply"};
        }
        matrix ret{a.m, b.n};
        for (size_t i = 0; i < a.m; i++) {
            for (size_t j = 0; j < b.n; j++) {
                long double sum = 0;
                for (size_t t = 0; t < b.m; t++) {
                    sum += (a.p[i][t] * b.p[t][j]);
                }
                ret.p[i][j] = double(sum);
            }
        }
        return ret;
    }
}

// сравнение матриц на равенство и неравенство;
bool operator==(const matrix &a, const matrix &b){
    if (a.m != b.m || a.n != b.n){
        return false;
    }
    for (size_t i = 0; i < a.m; ++i) {
        for (size_t j = 0; j < a.n; ++j) {
            if (a.p[i][j] != b.p[i][j]) return false;
        }
    }
    return true;
}

bool operator!=(const matrix &a, const matrix &b){
    return !(a == b);
}

// вывод в поток

std::ostream &operator<<(std::ostream &strm, const matrix &a){
    for (size_t i = 0; i < a.m; ++i) {
        for (size_t j = 0; j < a.n; ++j) {
            strm << a.p[i][j] << ' ';
        }
        strm << '\n';
    }
    return strm;
}

// ввод с потока
std::istream &operator>>(std::istream &is, matrix &a){
    for (size_t i = 0; i < a.m; ++i) {
        for (size_t j = 0; j < a.n; ++j) {
            double tmp;
            is >> tmp;
            a.p[i][j] = tmp;
        }
    }
    return  is;
}

void out (matrix &a){
    for (size_t i = 0; i < a.m; ++i) {
        for (size_t j = 0; j < a.n; ++j) {
            auto el = a.p[i][j];
            std::cout <<  el << ' ';
        }
        std::cout << '\n';
    }
}

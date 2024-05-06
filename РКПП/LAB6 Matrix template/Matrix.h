#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include "Rational.h"
#include <vector>
#include <stdexcept>
#include <iostream>

// THIS FILE HAVE BUGS, PLEASE OPEN ISSUE IF YOU FIND ONE

template<size_t M, size_t N, typename Field = Rational>
class Matrix {
public:

    Matrix() : _v(M, std::vector<Field>(N, 0)){
        if (M == N){
            for (size_t i = 0; i < M; ++i){
                _v[i][i] = 1;

            }
        }
    }


    Matrix(const Matrix<M, N, Field>& oth) : _v(M, std::vector<Field>(N, 0)){
        if(oth._v.size() == 0 || oth._v[0].size() == 0) throw std::runtime_error("empty vector");
        for (size_t i = 0; i < oth._v.size(); ++i) {
            for (size_t j = 0; j < oth._v[i].size(); ++j){
                _v[i][j] = Field(oth[i][j]);
            }
        }
    }

    template<class T>
    Matrix(const std::vector<std::vector<T>>& v) : _v(M, std::vector<Field>(N, 0)){
        if(v.size() == 0 || v[0].size() == 0) throw std::runtime_error("empty vector");
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j){
                _v[i][j] = Field(v[i][j]);
            }
        }
    }



    [[nodiscard]] Matrix transposed() const {
        std::vector<std::vector<Field>> v(N, std::vector<Field>(M, 0));
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                v[j][i] = _v[i][j];
            }
        }
        return Matrix<N, M, Field>(v);
    }

    Matrix operator+=(const Matrix<M, N, Field>& oth) {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                _v[i][j] += oth[i][j];
            }
        }
        return *this;
    }


    Matrix operator+(const Matrix<M, N, Field>& b) const{
        Matrix<M, N, Field> res(_v);
        res += b;
        return res;
    }

    Matrix operator-=(const Matrix<M, N, Field>& oth) {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                _v[i][j] -= oth[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix<M, N, Field>& b) const {
        Matrix<M, N, Field> res(_v);
        res -= b;
        return res;
    }

    template<size_t K>
    Matrix operator*(const Matrix<N, K, Field>& oth) const{
        std::vector<std::vector<Field>> v(M, std::vector<Field>(K, 0));
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < K; ++j) {
                Field sum = 0;
                for (size_t k = 0; k < N; ++k) {
                    sum += (_v[i][k] * oth[k][j]);
                }
                v[i][j] = sum;
            }
        }
        return Matrix<M, K, Field>(v);
    }

    template <bool b = N == M, typename = std::enable_if_t<(b)>>
    Matrix operator*=(const Matrix<N, M, Field>& oth) {
        *this = *this * oth;
        return *this;
    }

    Matrix operator*(const Field& num) const{
        std::vector<std::vector<Field>> v(_v);
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                v[i][j] *= num;
            }
        }
        return Matrix<M, N, Field>(v);
    }

    Matrix& operator*=(const Field& num) {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                _v[i][j] *= num;
            }
        }
        return *this;
    }

    bool operator!=(const Matrix<M, N, Field>& oth) {
        return !(*this == oth); // NOLINT
    }


    bool operator==(const Matrix<M, N, Field>& oth) {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                if (_v[i][j] != oth[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    Matrix& operator=(const Matrix<M, N, Field>& oth){
        _v = oth._v;
        return *this;
    }

    Matrix& operator=(Matrix<M, N, Field>&& oth)  noexcept {
        if (&oth == this) return *this;
        _v = std::move(oth._v);
    }
    ~Matrix() = default;

    std::vector<Field> operator[](size_t i) const {
        return getRow(i);
    }

    std::vector<Field>& operator[](size_t i){
        return _v[i];
    }

    std::vector<Field> getRow(size_t i) const{
        if (i >= M) throw std::runtime_error("bad index");
        return _v[i];
    }

    std::vector<Field> getColumn(size_t j){
        if (j >= N) throw std::runtime_error("bad index");
        std::vector<Field> v;
        for (size_t i = 0; i < N; ++i){
            v.push_back(_v[i][j]);
        }
        return v;
    }

    template <bool b = N == M, typename = std::enable_if_t<(b)>>
    Field det() {
        std::vector<std::vector<Field>> matrix = _v;
        Field det = 1.0;

        for (size_t k = 0; k < N; k++) {
            for (size_t i = k + 1; i < N; i++) {
                Field factor = matrix[i][k] / matrix[k][k];
                for (size_t j = k; j < N; j++) {
                    matrix[i][j] -= factor * matrix[k][j];
                }
            }
        }

        for (size_t i = 0; i < N; i++) {
            det *= matrix[i][i];
        }

        return det;
    }

    Field rank() {
        std::vector<std::vector<Field>> matrix = _v;
        Field rank = 0;

        for (size_t i = 0; i < M; i++) {
            size_t leading = -1;
            for (size_t j = 0; j < N; j++) {
                if (matrix[i][j] != Field(0)) {
                    leading = j;
                    break;
                }
            }

            if (leading != -1) {
                rank++;
                for (size_t j = 0; j < M; j++) {
                    if (j != i && matrix[j][leading] != Field(0)) {
                        Field factor = matrix[j][leading] / matrix[i][leading];
                        for (size_t k = 0; k < N; k++) {
                            matrix[j][k] -= factor * matrix[i][k];
                        }
                    }
                }
            }
        }

        return rank;
    }


    template <bool b = N == M, typename = std::enable_if_t<(b)>>
    void invert() {
        if (det() == Field(0)) throw std::runtime_error("determinant is 0, can't find inverted");
        std::vector<std::vector<Field>> augmentedMatrix(N, std::vector<Field>(2 * N, 0.0));
        // Создаем расширенную матрицу, добавляя единичную матрицу справа
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                augmentedMatrix[i][j] = _v[i][j];
            }
            augmentedMatrix[i][i + N] = 1.0;
        }

        // Приводим расширенную матрицу к единичной форме
        for (int i = 0; i < N; i++) {
            // Делим текущую строку на ведущий элемент
            Field leading = augmentedMatrix[i][i];
            for (int j = 0; j < 2 * N; j++) {
                augmentedMatrix[i][j] /= leading;
            }

            // Приводим остальные строки к нулевому виду
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    Field factor = augmentedMatrix[j][i];
                    for (int k = 0; k < 2 * N; k++) {
                        augmentedMatrix[j][k] -= factor * augmentedMatrix[i][k];
                    }
                }
            }

        }
        // Извлекаем обратную матрицу из расширенной матрицы
        _v = std::vector<std::vector<Field>>(N, std::vector<Field>(N, 0.0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                _v[i][j] = augmentedMatrix[i][j + N];
            }
        }
    }

    template <bool b = N == M, typename = std::enable_if_t<(b)>>
    Matrix inverted(){
        Matrix<M, N, Field> tmp(_v);
        tmp.invert();
        return tmp;
    }

    template <bool b = N == M, typename = std::enable_if_t<(b)>>
    Field trace(){
        Field res = 0;
        for (size_t i = 0; i < M; ++i) {
            res += _v[i][i];
        }
        return res;
    }

    friend std::ostream& operator<< (std::ostream& out, const Matrix& m){
        for (auto& e : m._v){
            for (auto el : e){
                out << el << ' ';
            }
            out << '\n';
        }
        return out;
    }

    friend std::ostream& operator>> (std::ostream& in, const Matrix& m){
        for (size_t i = 0; i < m._v.size(); ++i){
            for (size_t j = 0; j < m[i]._v.size(); ++j){
                Field el;
                in >> el;
                m[i][j] = el;
            }
        }
        return in;
    }

private:
    std::vector<std::vector<Field>> _v;
};


template <size_t N>
using SquareMatrix = Matrix<N, N, Rational>;

#endif

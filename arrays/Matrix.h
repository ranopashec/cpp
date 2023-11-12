#pragma once

#include <vector>
#include <stdexcept>

template <class T>
class Matrix {
   public:
    Matrix(size_t n, size_t m, const T& value = 0) : v_(n) {  // NOLINT
        for (auto& e : v_) {
            e = std::vector<T>(m, value);
        }
    }

    Matrix(size_t n) : v_(n) {  // NOLINT
        for (auto& e : v_) {
            e = std::vector<T>(n, 0);
        }
    }

    Matrix(const std::vector<std::vector<T>>& v) : v_(v.size()) {  // NOLINT
        if (v.empty()){
            throw std::length_error{"BACHOK POTIK"};
        }
        for (auto& e : v) {
            if (e.size() != v[0].size()) {
                throw std::runtime_error{"Bad vector construction"};
            }
        }
        for (size_t i = 0; i < v.size(); ++i) {
            v_[i] = v[i];
        }
    }

    Matrix(const Matrix& m) : v_(m.Rows()) {  // NOLINT
        for (size_t i = 0; i < Rows(); ++i) {
            v_[i] = m.v_[i];
        }
    }

    static Matrix<T> Identity(size_t num) {
        Matrix<T> a(num);
        for (size_t i = 0; i < num; ++i) {
            a(i, i) = 1;
        }
        return a;
    }

    T& operator()(size_t row, size_t col) {
        if ((row > (Rows() - 1)) || (col > (Columns() - 1))) {
            throw std::runtime_error{"Bad parenthesis"};
        }
        return v_[row][col];
    }

    T operator()(size_t row, size_t col) const {
        if ((row > (Rows() - 1)) || (col > (Columns() - 1))) {
            throw std::runtime_error{"Bad parenthesis"};
        }
        return v_[row][col];
    }

    [[nodiscard]] Matrix Transpose() const {
        Matrix<T> m(Columns(), Rows());
        for (size_t i = 0; i < Rows(); i++) {
            for (size_t j = 0; j < Columns(); j++) {
                m(j, i) = v_[i][j];
            }
        }
        return m;
    }

    Matrix operator+=(Matrix<T> m) {
        if (m.Rows() != Rows() || m.Columns() != Columns()) {
            throw std::runtime_error{"Slojeniye plohoye"};
        }
        for (size_t i = 0; i < Rows(); i++) {
            for (size_t j = 0; j < Columns(); j++) {
                v_[i][j] += m(i, j);
            }
        }
        return *this;
    }

    friend Matrix operator+(const Matrix<T> a, const Matrix<T> b) {
        if (a.Rows() != b.Rows() || a.Columns() != b.Columns()) {
            throw std::runtime_error{"Slojeniye plohoye"};
        }
        Matrix<T> matr(a.Rows(), a.Columns());
        matr += a;
        matr += b;
        return matr;
    }

    Matrix operator-=(Matrix<T> m) {
        if (m.Rows() != Rows() || m.Columns() != Columns()) {
            throw std::runtime_error{"Slojeniye plohoye"};
        }
        for (size_t i = 0; i < Rows(); i++) {
            for (size_t j = 0; j < Columns(); j++) {
                v_[i][j] -= m(i, j);
            }
        }
        return *this;
    }

    friend Matrix operator-(const Matrix<T> a, const Matrix<T> b) {
        if (a.Rows() != b.Rows() || a.Columns() != b.Columns()) {
            throw std::runtime_error{"Slojeniye plohoye"};
        }
        Matrix<T> matr(a.Rows(), a.Columns());
        matr += a;
        matr -= b;
        return matr;
    }

    friend Matrix operator*(const Matrix<T> a, const Matrix<T> b) {

        Matrix<T> matr(a.Rows(), b.Columns());
        for (size_t i = 0; i < a.Rows(); i++) {
            for (size_t j = 0; j < b.Columns(); j++) {
                T sum = 0;
                for (size_t t = 0; t < b.Rows(); t++) {
                    sum += (a(i, t) * b(t, j));
                }
                matr(i, j) = sum;
            }
        }
        return matr;
    }

    Matrix operator*=(const Matrix<T>& m) {
        *this = *this * m;
        return *this;
    }

    friend bool operator!=(const Matrix<T>& a, const Matrix<T>& b) {
        if (a.Rows() != b.Rows() || a.Columns() != b.Columns()) {
            return true;
        }
        for (size_t i = 0; i < a.Rows(); ++i) {
            for (size_t j = 0; j < a.Columns(); ++j) {
                if (a(i, j) != b(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    friend bool operator==(const Matrix<T>& a, const Matrix<T>& b) {
        return !(a != b);  // NOLINT
    }

    [[nodiscard]] size_t Rows() const {
        return v_.size();
    }

    [[nodiscard]] size_t Columns() const {
        return v_[0].size();
    }

    const std::vector<std::vector<T>>& Data() const {
        return v_;
    }

    Matrix& operator=(const Matrix<T>&) = default;
    Matrix& operator=(Matrix<T>&&) = delete;
    ~Matrix<T>() = default;

   private:
    std::vector<std::vector<T>> v_;
};

template <class T>
Matrix<T> Transpose(Matrix<T> m) {
    Matrix<T> trans(m.Columns(), m.Rows());
    for (size_t i = 0; i < m.Rows(); i++) {
        for (size_t j = 0; j < m.Columns(); j++) {
            trans(j, i) = m(i, j);
        }
    }
    return trans;
}

#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <stdexcept>

class Vector {
   public:
    class Iterator {
       public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = int;
        using difference_type = ptrdiff_t;
        using pointer = int*;
        using reference = int&;

        Iterator() : ptr_(nullptr) {
        }

        explicit Iterator(pointer rhs) : ptr_(rhs) {
        }

        Iterator(const Iterator& rhs) = default;
        Iterator(Iterator&& rhs) = default;

        void Del() {
            delete ptr_;
        }

        void Delarr() {
            delete[] ptr_;
        }

        void Reset() {
            ptr_ = nullptr;
        }

        inline Iterator& operator=(pointer rhs) {
            ptr_ = rhs;
            return *this;
        }

        inline Iterator& operator=(const Iterator& rhs) = default;
        inline Iterator& operator=(Iterator&& rhs) = default;

        inline Iterator& operator+=(size_t rhs) {
            ptr_ += rhs;
            return *this;
        }

        ~Iterator() = default;

        inline Iterator& operator-=(difference_type rhs) {
            ptr_ -= rhs;
            return *this;
        }

        inline reference operator*() const {
            return *ptr_;
        }

        inline pointer operator->() const {
            return ptr_;
        }

        inline reference operator[](size_t rhs) const {
            return ptr_[rhs];
        }

        inline Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        inline Iterator& operator--() {
            --ptr_;
            return *this;
        }

        inline Iterator operator++(int) {
            const Iterator tmp(*this);
            ++ptr_;
            return tmp;
        }

        inline Iterator operator--(int) {
            Iterator tmp(*this);  // NOLINT
            --ptr_;
            return tmp;
        }

        inline difference_type operator-(const Iterator& rhs) const {
            return ptr_ - rhs.ptr_;
        }

        inline Iterator operator+(size_t rhs) const {
            return Iterator(ptr_ + rhs);
        }

        inline Iterator operator-(difference_type rhs) const {
            return Iterator(ptr_ - rhs);
        }

        friend inline Iterator operator+(difference_type lhs, const Iterator& rhs) {
            return Iterator(lhs + rhs.ptr_);
        }

        friend inline Iterator operator-(difference_type lhs, const Iterator& rhs) {
            return Iterator(rhs.ptr_ - lhs);
        }

        inline bool operator==(const Iterator& rhs) const {
            return ptr_ == rhs.ptr_;
        }

        inline bool operator!=(const Iterator& rhs) const {
            return ptr_ != rhs.ptr_;
        }

        inline bool operator!=(const int* rhs) const {
            return ptr_ != rhs;
        }

        inline bool operator>(const Iterator& rhs) const {
            return ptr_ > rhs.ptr_;
        }

        inline bool operator<(const Iterator& rhs) const {
            return ptr_ < rhs.ptr_;
        }

        inline bool operator>=(const Iterator& rhs) const {
            return ptr_ >= rhs.ptr_;
        }

        inline bool operator<=(const Iterator& rhs) const {
            return ptr_ <= rhs.ptr_;
        }

       private:
        pointer ptr_;
    };

    explicit Vector(size_t size) : beg_(new int[size]), end_(beg_ + size), cap_(size) {
        for (size_t i = 0; i < cap_; ++i) {
            beg_[i] = 0;
        }
    }

    Vector(std::initializer_list<int> list) : Vector(list.size()) {
        std::copy(list.begin(), list.end(), beg_);
    }

    Vector& operator=(std::initializer_list<int> list) {
        beg_.Reset();
        beg_ = new int[list.size()];  // NOLINT
        end_ = beg_ + list.size();
        cap_ = list.size();
        std::copy(list.begin(), list.end(), beg_);
        return *this;
    }

    Vector(const Vector& other) {
        *this = other;
    }

    Vector(Vector&& other) : beg_(other.beg_), end_(other.end_), cap_(other.cap_) {  // NOLINT
        other.beg_ = nullptr;
        other.end_ = nullptr;
        other.cap_ = 0;
    }

    Vector& operator=(const Vector& other) {  // NOLINT
        if (this->beg_ == other.beg_) {
            return *this;
        }
        beg_.Delarr();
        beg_ = new int[other.cap_];  // NOLINT
        cap_ = other.cap_;
        std::copy(other.begin(), other.end(), beg_);
        end_ = beg_ + other.Size();
        return *this;
    }

    Vector& operator=(Vector&& other) {  // NOLINT
        if (this->beg_ == other.beg_) {
            return *this;
        }
        beg_.Delarr();
        beg_ = other.beg_;
        end_ = other.end_;
        other.beg_ = nullptr;
        other.end_ = nullptr;
        cap_ = other.cap_;
        other.cap_ = 0;
        return *this;
    }

    ~Vector() {
        if (beg_ != nullptr) {
            beg_.Delarr();
            cap_ = 0;
        }
    }

    void Swap(Vector& other) {
        std::swap(beg_, other.beg_);
        std::swap(end_, other.end_);
        std::swap(cap_, other.cap_);
    }

    int& operator[](size_t pos) {
        return beg_[pos];
    }

    const int& operator[](size_t pos) const {
        return beg_[pos];
    }

    [[nodiscard]] size_t Size() const {
        if (beg_.operator->() == nullptr) {
            return 0;
        }
        return end_ - beg_;  // NOLINT
    }

    void PushBack(const int& item) {
        const size_t s = Size();
        if (cap_ == 0) {
            beg_ = new int[1];  // NOLINT
            end_ = beg_;
            ++cap_;
        }
        if (cap_ == s) {
            cap_ *= 2;
            int* neg{new int[cap_]};
            std::move(beg_, end_, neg);
            beg_.Delarr();
            beg_ = neg;
            end_ = beg_ + s;
            neg = nullptr;
        }
        *end_ = item;
        ++end_;
    }

    void PopBack() {
        --end_;
    }

    void Clear() {
        beg_.Delarr();
        beg_ = new int[cap_];  // NOLINT
        end_ = beg_;
    }

    void Reserve(size_t new_cap) {
        const size_t s = Size();
        if (cap_ < new_cap) {
            cap_ = new_cap;
            int* neg{new int[cap_]};
            std::move(beg_, end_, neg);
            beg_ = neg;
            end_ = beg_ + s;
        }
    }

    [[nodiscard]] Iterator begin() const {
        return beg_;
    }

    [[nodiscard]] Iterator end() const {
        return end_;
    }

    [[nodiscard]] Iterator begin() {
        return beg_;
    }

    [[nodiscard]] Iterator end() {
        return end_;
    }

    Vector() : beg_(nullptr), end_(nullptr) {
    }

    [[nodiscard]] size_t Capacity() const {
        return cap_;
    }

   private:
    Iterator beg_{};
    Iterator end_{};
    size_t cap_{0};
};

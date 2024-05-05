#ifndef KDEQUE_H
#define KDEQUE_H
#include "memory"
#include <iostream>
#include <vector>
#include <initializer_list>

template<typename T>
class KDequeIterator;

int mod(int x, int m) {
    int r = x % m;
    return r < 0 ? r + m : r;
}

template <typename T>
class KDeque
{
public:
    friend class KDequeIterator<T>;

    KDeque()
            :
            storage{std::vector<T>(4)},
            size{0},
            capacity{4},
            head_index{0},
            tail_index{0}
    {}

    KDeque(int i)
            :
            storage{std::vector<T>(i + 4)},
            size{0},
            capacity{i + 4},
            head_index{0},
            tail_index{0}
    {}

    KDeque(int i, int element): KDeque(i) {
        for (int j = 0; j < i; ++j){
            this->Push_Back(element);
        }
    }

    KDeque(std::initializer_list<T> list) : KDeque(list.size()){
        auto iter = list.begin();
        for (size_t i = 0 ; i < list.size(); ++i){
            Push_Back(*iter);
            iter++;
        }
    }

    KDeque& operator=(std::initializer_list<T> list) {
        *this = KDeque<T>(list.size());
        auto iter = list.begin();
        for (size_t i = 0 ; i < list.size(); ++i){
            Push_Back(*iter);
            iter++;
        }
        return *this;
    }

    KDeque(const KDeque<T>& kdeq) : KDeque(kdeq.Size()) {
        for (int i = 0; i < kdeq.Size(); ++i){
            Push_Back(kdeq[i]);
        }
    }

    KDeque& operator=(const KDeque<T>& kdeq) { // NOLINT
        if (&kdeq.storage == &storage) return *this;
        storage = std::vector<T>(kdeq.Size()+4);
        size = 0;
        capacity = kdeq.Size()+4;
        head_index = 0;
        tail_index = 0;
        for (int i = 0; i < kdeq.Size(); ++i){
            Push_Back(kdeq[i]);
        }
        return *this;
    }

    T Back(){
        return storage[tail_index];
    }

    T Front(){
        return storage[head_index];
    }

    void Clear(){
        *this = KDeque<T>();
    }

    bool isFool(){
        return size == capacity;
    }

    bool isEmpty(){
        return size == 0;
    }

    void Push_Front(T elem)
    {
        ensure_capacity();
        storage[head_index = mod(head_index - 1, capacity)] = elem;
        size++;
    }

    void Push_Back(T elem)
    {
        ensure_capacity();
        storage[tail_index] = elem;
        tail_index = mod(tail_index + 1, capacity);
        size++;
    }

    T Pop_Front()
    {
        check_not_empty();
        T ret = storage[head_index];
        head_index = mod(head_index + 1, capacity);
        --size;
        return ret;
    }

    T Pop_Back()
    {
        check_not_empty();
        tail_index = mod(tail_index - 1, capacity);
        --size;
        return storage[tail_index];
    }

    T operator[](int i)
    {
        return storage[mod(i + head_index, capacity)];
    }

    T operator[] (int i) const
    {
        return storage[mod(i + head_index, capacity)];
    }

    int Size() const
    {
        return size;
    }
    std::shared_ptr<KDequeIterator<T>> Begin() const{
        return createIterator();
    }
    std::shared_ptr<KDequeIterator<T>> End() const;

private:
    std::shared_ptr<KDequeIterator<T>> createIterator() const;

    std::vector<T> storage;
    int size;
    int capacity;
    int head_index;
    int tail_index;

    void ensure_capacity()
    {
        if (size == capacity)
        {
            std::vector<T> new_storage (2 * capacity);
            for (int i = 0; i < size; ++i)
            {
                new_storage[i] = storage[(head_index + i) % size];
            }
            storage = std::move(new_storage);
            capacity *= 2;
            head_index = 0;
            tail_index = size;
        }
    }

    void check_not_empty()
    {
        if (size == 0)
        {
            throw std::runtime_error{"Popping an empty deque."};
        }
    }
};

template <typename T>
class KDequeIterator {
private:
    const KDeque<T>* deq;
    int index;
    void Last(){
        index = deq->size;
    }
public:
    KDequeIterator(const KDeque<T> * d) : deq(d), index(0) {}

    void operator++(){
        ++index;
    }
    void operator--(){
        ++index;
    }

    T operator*(){
        return (*deq)[index];
    }

    friend bool operator==(const KDequeIterator<T>& a, const KDequeIterator<T>& b){
        return a.deq == b.deq && a.index == b.index;
    }

    int Index () const {
        return index;
    }
    template<typename U>
    friend int Find (std::shared_ptr<KDequeIterator<U>>& begin, std::shared_ptr<KDequeIterator<U>>& end, U x);

    template<typename U>
    friend int RangesFind(const KDeque<U>& deq, U x);

    friend class KDeque<T>;

};

template<typename T>
std::shared_ptr<KDequeIterator<T>> KDeque<T>::createIterator() const{
    return std::make_shared<KDequeIterator<T>>(this);
}

template<typename T>

std::shared_ptr<KDequeIterator<T>> KDeque<T>::End() const{
    std::shared_ptr<KDequeIterator<T>> iter {createIterator()};
    iter->Last();
    return iter;
}

template<typename T>
std::ostream &operator<<(std::ostream &strm, const KDeque<T> &a) {
    auto iter = a.Begin();
    strm << "[ ";
    while (*iter != *a.End()){
        strm << **iter << " ";
        ++*iter;
    }
    strm << "]";
    return strm;
}

template<typename T>
int Find(std::shared_ptr<KDequeIterator<T>>& begin, std::shared_ptr<KDequeIterator<T>>& end, T x){
    const std::shared_ptr<KDequeIterator<T>>& cur = begin;
    while(*cur != *end){
        if (**cur == x) return cur->Index();
        ++(*cur);
    }
    return -1;
}

template<typename T>
int RangesFind(const KDeque<T>& deq, T x){
    const std::shared_ptr<KDequeIterator<T>>& cur = deq.Begin();
    while(*cur != *deq.End()){
        if (**cur == x) return cur->Index();
        ++(*cur);
    }
    return -1;
}

/*
 template<typename T>
 class KDequeIterator {
private:
    const KDeque<T>* deq;
    int index;
    void Last(){
        index = deq->size;
    }
public:
    KDequeIterator(const KDeque<T> * d) : deq(d), index(0) {}

    void Next(){
        ++index;
    }
    void Previous(){
        ++index;
    }
    int Value(){
        return (*deq)[index];
    }

    friend bool operator==(const KDequeIterator<T>& a, const KDequeIterator<T>& b){
        return a.deq == b.deq && a.index == b.index;
    }
};

 */


#endif

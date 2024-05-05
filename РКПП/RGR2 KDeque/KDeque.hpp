#ifndef KDEQUE_HPP
#define KDEQUE_HPP
#include <memory>
#include <iostream>
#include <vector>
#include <iterator>
#include <initializer_list>

class KDequeIterator;

int mod(int x, int m) {
    int r = x % m;
    return r < 0 ? r + m : r;
}

class KDeque
{
public:
    friend class KDequeIterator;

    KDeque()
            :
            storage{std::vector<int>(4)},
            size{0},
            capacity{4},
            head_index{0},
            tail_index{0}
    {}

    KDeque(int i)
            :
            storage{std::vector<int>(i + 4)},
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

    KDeque(std::initializer_list<int> list) : KDeque(list.size()){
        auto iter = list.begin();
        for (size_t i = 0 ; i < list.size(); ++i){
            Push_Back(*iter);
            iter++;
        }
    }

    KDeque& operator=(std::initializer_list<int> list) {
        *this = KDeque(list.size());
        auto iter = list.begin();
        for (size_t i = 0 ; i < list.size(); ++i){
            Push_Back(*iter);
            iter++;
        }
        return *this;
    }

    KDeque(const KDeque& kdeq) : KDeque(kdeq.Size()) {
        for (int i = 0; i < kdeq.Size(); ++i){
            Push_Back(kdeq[i]);
        }
    }

    KDeque& operator=(const KDeque& kdeq) { // NOLINT
        if (&kdeq.storage == &storage) return *this;
        storage = std::vector<int>(kdeq.Size()+4);
        size = 0;
        capacity = kdeq.Size()+4;
        head_index = 0;
        tail_index = 0;
        for (int i = 0; i < kdeq.Size(); ++i){
            Push_Back(kdeq[i]);
        }
        return *this;
    }

    int Back(){
        return storage[tail_index];
    }

    int Front(){
        return storage[head_index];
    }

    void Clear(){
        *this = KDeque();
    }

    bool isFool(){
        return size == capacity;
    }

    bool isEmpty(){
        return size == 0;
    }

    void Push_Front(int elem)
    {
        ensure_capacity();
        storage[head_index = mod(head_index - 1, capacity)] = elem;
        size++;
    }

    void Push_Back(int elem)
    {
        ensure_capacity();
        storage[tail_index] = elem;
        tail_index = mod(tail_index + 1, capacity);
        size++;
    }

    int Pop_Front()
    {
        check_not_empty();
        int ret = storage[head_index];
        head_index = mod(head_index + 1, capacity);
        --size;
        return ret;
    }

    int Pop_Back()
    {
        check_not_empty();
        tail_index = mod(tail_index - 1, capacity);
        --size;
        return storage[tail_index];
    }

    int operator[](int i)
    {
        return storage[mod(i + head_index, capacity)];
    }

    int operator[] (int i) const
    {
        return storage[mod(i + head_index, capacity)];
    }

    int Size() const
    {
        return size;
    }
    std::shared_ptr<KDequeIterator> Begin() const{
        return createIterator();
    }
    std::shared_ptr<KDequeIterator> End() const;

private:
    std::shared_ptr<KDequeIterator> createIterator() const;

    std::vector<int> storage;
    int size;
    int capacity;
    int head_index;
    int tail_index;

    void ensure_capacity()
    {
        if (size == capacity)
        {
            std::vector<int> new_storage (2 * capacity);
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

class KDequeIterator {
private:
    const KDeque* deq;
    int index;
    void Last(){
        index = deq->size;
    }
public:
    KDequeIterator(const KDeque * d) : deq(d), index(0) {}

    void operator++(){
        ++index;
    }
    void operator--(){
        ++index;
    }
    int operator*(){
        return (*deq)[index];
    }

    friend bool operator==(const KDequeIterator& a, const KDequeIterator& b){
        return a.deq == b.deq && a.index == b.index;
    }

    friend int Find(std::shared_ptr<KDequeIterator>& begin, std::shared_ptr<KDequeIterator>& end, int x);
    friend int RangesFind(const KDeque& deq, int x);
    friend class KDeque;
};

std::shared_ptr<KDequeIterator> KDeque::createIterator() const{
    return std::make_shared<KDequeIterator>(this);
}

std::shared_ptr<KDequeIterator> KDeque::End() const{
    std::shared_ptr<KDequeIterator> iter {createIterator()};
    iter->Last();
    return iter;
}

std::ostream &operator<<(std::ostream &strm, const KDeque &a) {
    auto iter = a.Begin();
    strm << "[ ";
    while (*iter != *a.End()){
        strm << **iter << " ";
        ++*iter;
    }
    strm << "]";
    return strm;
}

int Find(std::shared_ptr<KDequeIterator>& begin, std::shared_ptr<KDequeIterator>& end, int x){
    const std::shared_ptr<KDequeIterator>& cur = begin;
    while(*cur != *end){
        if (**cur == x) return cur->index;
        ++(*cur);
    }
    return -1;
}

int RangesFind(const KDeque& deq, int x){
    const std::shared_ptr<KDequeIterator>& cur = deq.Begin();
    while(*cur != *deq.End()){
        if (**cur == x) return cur->index;
        ++(*cur);
    }
    return -1;
}

/*
 class KDequeIterator {
private:
    const KDeque* deq;
    int index;
    void Last(){
        index = deq->size;
    }
public:
    KDequeIterator(const KDeque * d) : deq(d), index(0) {}

    void Next(){
        ++index;
    }
    void Previous(){
        ++index;
    }
    int Value(){
        return (*deq)[index];
    }

    friend bool operator==(const KDequeIterator& a, const KDequeIterator& b){
        return a.deq == b.deq && a.index == b.index;
    }
};
 
 */


#endif

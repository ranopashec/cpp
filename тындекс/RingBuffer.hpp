#include <cstddef>
#include <vector>

class RingBuffer {
   public:
    explicit RingBuffer(size_t cap) : cap_(cap){
    }

    [[nodiscard]] size_t Size() const {
        return size_;
    }

    [[nodiscard]] bool Empty() const {
        return 0 == size_;
    }

    bool TryPush(int element) {
        if (size_ >= cap_) {
            return false;
        }
        arr_[rear_] = element;
        rear_ = (rear_ + 1) % cap_;
        size_++;
        return true;
    }

    bool TryPop(int* el) {
        if (size_ <= 0) {
            return false;
        }
        *el = arr_[front_];
        front_ = (front_ + 1) % cap_;
        size_--;
        return true;
    }

   private:
    std::vector<int> arr_;
    size_t size_{0};
    size_t front_{0};
    size_t rear_{0};
    size_t cap_{0};
};

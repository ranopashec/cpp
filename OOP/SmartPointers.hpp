// IMPLEMENTATION OF SHARED AND WEAK POINTERS USING STD::STRING

#include <stdexcept>
#include <string>

struct ControlBlock {
    size_t shared = 0;
    size_t weak = 0;
};

class WeakPtr;

class SharedPtr {
   public:
    friend class WeakPtr;

    SharedPtr() = default;

    SharedPtr(const WeakPtr& ptr);                                             // NOLINT

    SharedPtr(std::string* strp) : res_(strp), cnt_(new ControlBlock{1, 0}) {  // NOLINT
    }

    SharedPtr(const SharedPtr& oth) {                                          // NOLINT
        if (oth.res_ != res_) {
            res_ = oth.res_;
            cnt_ = oth.cnt_;
            ++(cnt_->shared);
        }
    }

    SharedPtr(SharedPtr&& oth) {  // NOLINT
        if (oth.res_ != res_) {
            res_ = oth.res_;
            cnt_ = oth.cnt_;
            ++(cnt_->shared);
            oth.Destructor();
        }
    }

    SharedPtr& operator=(const SharedPtr& oth) {  // NOLINT
        if (oth.res_ != res_) {
            Destructor();
            res_ = oth.res_;
            cnt_ = oth.cnt_;
            if (cnt_ != nullptr) {
                ++(cnt_->shared);
            }
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& oth) {  // NOLINT
        if (oth.res_ != res_) {
            Destructor();
            res_ = oth.res_;
            cnt_ = oth.cnt_;
            ++(cnt_->shared);
            oth.Destructor();
        }
        return *this;
    }

    std::string& operator*() {
        if (res_ == nullptr) {
            throw std::runtime_error("ploho");
        }
        return *res_;
    }

    std::string& operator*() const {
        if (res_ == nullptr) {
            throw std::runtime_error("ploho");
        }
        return *res_;
    }

    std::string* operator->() {
        return res_;
    }

    std::string* operator->() const {
        return res_;
    }

    void Reset(std::string* strp) {
        Destructor();
        if (strp != nullptr) {
            cnt_ = {new ControlBlock{1, 0}};
        } else {
            cnt_ = nullptr;
        }
        res_ = strp;
    }

    [[nodiscard]] std::string* Get() const {
        if (cnt_ == nullptr || cnt_->shared == 0) {
            return nullptr;
        }
        return res_;
    }

    ~SharedPtr() {
        Destructor();
    }

    void Destructor() {
        if (cnt_ != nullptr) {
            if (cnt_->shared != 0) {
                --(cnt_->shared);
            }
            if (cnt_->shared == 0) {
                if (cnt_->weak == 0) {
                    delete cnt_;
                }
                delete res_;
            }
        }
        cnt_ = nullptr;
        res_ = nullptr;
    }

   private:
    std::string* res_{};
    ControlBlock* cnt_{};
};

class WeakPtr {
   public:
    friend class SharedPtr;

    WeakPtr() = default;

    WeakPtr(SharedPtr& ptr) : res_{ptr.res_}, cnt_(ptr.cnt_) {  // NOLINT
        if (cnt_ != nullptr) {
            const size_t tmp = cnt_->weak;  // NOLINT(clang-analyzer-core.uninitialized.Assign)
            cnt_->weak = tmp + 1;
        }
    }

    WeakPtr(const SharedPtr& ptr) : res_{ptr.res_}, cnt_(ptr.cnt_) {  // NOLINT
        if (cnt_ != nullptr) {
            const size_t tmp = cnt_->weak;  // NOLINT(clang-analyzer-core.uninitialized.Assign)
            cnt_->weak = tmp + 1;
        }
    }

    std::string* Get() {
        if (IsExpired()) {
            return nullptr;
        }
        return res_;
    }

    WeakPtr(const WeakPtr& oth) : res_(oth.res_), cnt_(oth.cnt_) {  // NOLINT
        if (cnt_ != nullptr) {
            const size_t tmp = cnt_->weak;  // NOLINT(clang-analyzer-core.uninitialized.Assign)
            cnt_->weak = tmp + 1;
        }
    }

    WeakPtr(WeakPtr&& oth) : res_(oth.res_), cnt_(oth.cnt_) {  // NOLINT
        oth.Destructor();
    }

    WeakPtr& operator=(const WeakPtr& oth) {  // NOLINT
        if (oth.res_ != res_) {
            Destructor();
            res_ = oth.res_;
            cnt_ = oth.cnt_;
            if (cnt_ != nullptr) {
                const size_t tmp = cnt_->weak;
                cnt_->weak = tmp + 1;
            }
        }
        return *this;
    }

    WeakPtr& operator=(WeakPtr&& oth) {  // NOLINT
        if (oth.res_ != res_) {
            Destructor();
            res_ = oth.res_;
            cnt_ = oth.cnt_;
            oth.Destructor();
        }
        return *this;
    }

    [[nodiscard]] SharedPtr Lock() const {
        return SharedPtr{*this};
    }

    ~WeakPtr() {
        Destructor();
    }

    void Destructor() {
        if (cnt_ != nullptr) {
            if (cnt_->weak != 0) {
                --(cnt_->weak);
            }
            if (cnt_->weak == 0 && cnt_->shared == 0) {
                delete cnt_;
            }
        }
        cnt_ = nullptr;
        res_ = nullptr;
    }

    [[nodiscard]] bool IsExpired() const {
        return cnt_ == nullptr || cnt_->shared == 0;
    }

   private:
    std::string* res_{nullptr};
    ControlBlock* cnt_{nullptr};
};

inline SharedPtr::SharedPtr(const WeakPtr& ptr) : res_(ptr.res_), cnt_(ptr.cnt_) {  // NOLINT
    if (cnt_ != nullptr && cnt_->shared != 0) {
        ++(cnt_->shared);
    } else {
        res_ = nullptr;
    }
}

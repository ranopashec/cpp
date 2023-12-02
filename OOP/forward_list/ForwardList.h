#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template<typename T>
class ForwardList {
private:
    struct Node {
        T Info;
        Node *Next;
    };
    void Clone(const ForwardList<T> &oth){
        for (auto node = oth.First; node != nullptr; node  = node->Next){
            InsertLast(node->Info);
        }
    }
public:
    ForwardList() {First = nullptr; Last = nullptr;}
    ForwardList(const ForwardList<T> &oth) : ForwardList(){
        Clone(oth);
    }
    ForwardList<T> &operator=(const ForwardList<T> &L){
        if (&L == this){
            return *this;
        }
        Erase();
        Clone(L);
        return *this;
    }
    ~ForwardList(){
        Erase();
    }
    void InsertFirst(const T info){
        Node *N = new Node;
        N->Info = info;
        N->Next = First;
        if (First == nullptr){
            Last = N;
        }
        First = N;
    }
    void InsertLast(const T info){
        Node *N = new Node;
        N->Info = info;
        if (Last != nullptr) {
            Last->Next = N;
            Last = N;
            N->Next = nullptr;
        } else {
            Last = N;
            N->Next = nullptr;
            if (First == nullptr){
                First = Last;
            }
        }
    }
    void DeleteFirst(){
        if (First == nullptr) {
            throw Exception("No first to delete");
        }
        if (First != Last) {
            Node *N = First;
            First = First->Next;
            delete N;
        } else {
            delete First;
            First = nullptr;
            Last = nullptr;
        }
    }
    void DeleteLast(){
        if (Last == nullptr){
            throw Exception("No last to delete");
        }
        if (First != Last) {
            auto node = First;
            while (node->Next != Last) {
                node = node->Next;
            }
            node->Next = nullptr;
            delete Last;
            Last = node;
        } else {
            delete First;
            First = nullptr;
            Last = nullptr;
        }
    }
    bool Delete(const T info){
        auto prev = First;
        auto cur = First;
        if (cur == nullptr){
            return false;
        }
        while (cur != Last && cur->Info != info){
            prev = cur;
            cur = cur->Next;
        }
        if (cur->Info == info){
            if (First == cur){
                DeleteFirst();
                return true;
            } else if (Last == cur){
                DeleteLast();
                return true;
            } else {
                prev->Next = cur->Next;
                delete cur;
                return true;
            }
        } else {
            return false;
        }
    }
    bool Contains(const T& info, size_t* cnt){
        auto cur = First;
        while (cur != Last && cur->Info != info){
            (*cnt)++;
            cur = cur->Next;
        }
        (*cnt)++;
        if (cur->Info == info){
            return true;
        } else {
            return false;
        }
    }
    void Print() const{
        Node* N = First;
        if (N == nullptr)
            std::cout << "list is empty\n";
        if (N != nullptr) {
            std::cout << "list:\n";
            while (N != nullptr) {
                std::cout << N->Info <<'\n';
                N = N->Next;
            }
        }
    }
    void ForEach(void foo(T& info)){
        Node* N = First;
        while (N != nullptr) {
            foo(N->Info);
            N = N->Next;
        }
    }
    void ForEach(void foo(const T& info)) const{
        Node* N = First;
        while (N != nullptr) {
            foo(N->Info);
            N = N->Next;
        }
    }
    void Erase(){
        Node *p, *q;
        p = First;
        while (p != nullptr) {
            q = p->Next;
            delete p;
            p = q;
        }
        First = nullptr;
        Last = nullptr;
    }
private:
    Node *First;
    Node *Last;
};

template<class T>
void Print(const T& info){
    std::cout << info << '\n';
}


#endif

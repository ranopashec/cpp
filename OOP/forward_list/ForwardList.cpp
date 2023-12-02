#include "ForwardList.h"
#include <iostream>
#include <cctype>

ForwardList::ForwardList(const ForwardList& oth) : ForwardList(){
    Clone(oth);
}
ForwardList& ForwardList::operator=(const ForwardList &L){
    if (&L == this){
        return *this;
    }
    Erase();
    Clone(L);
    return *this;
}
ForwardList::~ForwardList(){
    Erase();
}
void ForwardList::InsertFirst(const std::string &name, const std::string &author){
    Film *B = new Film;
    B->Name = name;
    B->Author = author;
    B->Next = First;
    if (First == nullptr){
        Last = B;
    }
    First = B;
}
void ForwardList::InsertLast(const std::string& name, const std::string & author){
        Film *B = new Film;
        B->Name = name;
        B->Author = author;
    if (Last != nullptr) {
        Last->Next = B;
        Last = B;
        B->Next = nullptr;
    } else {
        Last = B;
        B->Next = nullptr;
        if (First == nullptr){
            First = Last;
        }
    }
}
void ForwardList::DeleteFirst(){
    if (First == nullptr) {
        throw Exception("No first to delete");
    }
    if (First != Last) {
        Film *B = First;
        First = First->Next;
        delete B;
    } else {
        delete First;
        First = nullptr;
        Last = nullptr;
    }
}
void ForwardList::DeleteLast(){
    if (Last == nullptr){
        throw Exception("No last to delete");
    }
    if (First != Last) {
        auto film = First;
        while (film->Next != Last) {
            film = film->Next;
        }
        film->Next = nullptr;
        delete Last;
        Last = film;
    } else {
        delete First;
        First = nullptr;
        Last = nullptr;
    }
}

void ForwardList::Clone(const ForwardList &oth){
    for (auto film = oth.First; film != nullptr; film  = film->Next){
        InsertLast(film->Name, film->Author);
    }
}

bool ForwardList::Delete(const std::string& name, const std::string & author){
    auto prev = First;
    auto cur = First;
    if (cur == nullptr){
        return false;
    }
    while (cur != Last && cur->Name != name && cur->Author != author){
        prev = cur;
        cur = cur->Next;
    }
    if (cur->Name == name && cur->Author == author){
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

bool ForwardList::Contains(const std::string &name, const std::string &author, size_t* cnt){
    auto cur = First;
    while (cur != Last && cur->Name != name && cur->Author != author){
        (*cnt)++;
        cur = cur->Next;
    }
    if (cur->Name == name && cur->Author == author ){
        return true;
    } else {
        return false;
    }
}
void ForwardList::Print() const{
    Film* B = First;
    if (B == nullptr)
        std::cout << "list is empty\n";
    if (B != nullptr) {
        std::cout << "list:\n";
        while (B != nullptr) {
            std::cout << "\"" << B->Name << "\" " << B->Author << '\n';
            B = B->Next;
        }
    }
}
void ForwardList::Erase() {
    Film *p, *q;
    p = First;
    while (p != nullptr) {
        q = p->Next;
        delete p;
        p = q;
    }
    First = nullptr;
    Last = nullptr;
}

void ForwardList::ForEach(void foo(std::string& name, std::string& author)){
    Film* B = First;
    while (B != nullptr) {
        foo(B->Name, B->Author);
        B = B->Next;
    }
}
void ForwardList::ForEach(void foo(const std::string& name, const std::string& author)) const{
    Film* B = First;
    while (B != nullptr) {
        foo(B->Name, B->Author);
        B = B->Next;
    }
}

void Print(const std::string& name, const std::string& author) {
    std::cout << "\"" << name << "\" " << author << '\n';
}

void NameToLower(std::string& name, std::string& author){
    for (auto & e : name) {
         e = std::tolower(e);
    }
}

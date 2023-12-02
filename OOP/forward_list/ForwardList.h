#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <string>

class Exception {
public:
    Exception(char* name) : Name(name){}
    char* What() const{
        return Name;
    }
private:
    char* Name;

};

class ForwardList {
private:
    struct Book {
        std::string Name;
        std::string Author;
        Book *Next;
    };
    void Clone(const ForwardList &);
public:
    ForwardList() { First = nullptr; }
    ForwardList(const ForwardList &);
    ForwardList &operator=(const ForwardList &);
    ~ForwardList();
    void InsertFirst(const std::string &name, const std::string &author);
    void InsertLast(const std::string &name, const std::string &author);
    void DeleteFirst();
    void DeleteLast();
    bool Delete(const std::string &name, const std::string &author);
    bool Contains(const std::string &name, const std::string &author, size_t *cnt);
    void Print() const;
    void ForEach(void foo(std::string& name, std::string& author));
    void ForEach(void foo(const std::string& name, const std::string& author)) const;
    void Erase();
private:
    Book *First;
    Book *Last;
};

void Print(const std::string& name, const std::string& author);
void NameToLower(std::string& name, std::string& author);

#endif

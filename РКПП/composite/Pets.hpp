#ifndef PETS_HPP
#define PETS_HPP
#include <string>
#include "Owner.hpp"
#include <memory>
#include <utility>

enum class Kind {
    PetGroup = 0,
    Cat = 1,
    Dog = 2,
    Budgie = 3,
    Fish = 4,
};

std::string KindToString(Kind kind){
    switch (kind){
        case Kind::Dog:
            return "Dog";
        case Kind::Cat:
            return "Cat";
        case Kind::Budgie:
            return "Budgie";
        case Kind::Fish:
            return "Fish";
        case Kind::PetGroup:
            return "PetGroup";
        default:
            return "Unknown kind";
    }
}

class Animal {
protected:
    std::shared_ptr<Owner> _owner;
    std::string _name;
    int _age;
    int m_ID;
    static inline int ID_st = 1;
public:
    Animal(std::shared_ptr<Owner>& own, std::string name, int age) : _owner(own), _name(std::move(name)), _age(age), m_ID(ID_st++) {}
    Animal& operator=(const Animal& oth){ // NOLINT
        if (oth.m_ID == m_ID) return *this;
        _owner = oth._owner;
        _name = oth._name;
        _age = oth._age;
        m_ID = ID_st++;
        return *this;
    }


    virtual ~Animal() = default;

    [[nodiscard]] virtual Kind GetKind() const = 0;

    [[maybe_unused]] [[nodiscard]] virtual std::string Say() const = 0; // NOLINT

    [[nodiscard]] std::string GetName() const {
        return _name;
    }

    [[nodiscard]] std::shared_ptr<Owner> GetOwner() const{
        return _owner;
    }

    [[nodiscard]] int GetAge() const {
        return _age;
    }

    [[maybe_unused]] [[nodiscard]] size_t GetId() const {
        return m_ID;
    }

    void SetName(std::string name){
        _name = std::move(name);
    }

    void SetAge(int age){
        _age = age;
    }

    void SetOwner(const std::shared_ptr<Owner>& owner){
        _owner = owner;
    }

    virtual void Print(int naste) const = 0;
};

class Cat : public Animal {
public:
    Cat(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, std::move(name), age} {}

    [[nodiscard]] Kind GetKind() const override {
        return Kind::Cat;
    }

    [[nodiscard]] std::string Say() const override {
        return "\"mew\"";
    }
    void Print(int naste) const override{
        for(int i = 0; i < naste; ++i) std::cout << ' ';
        std::cout << KindToString(GetKind()) << ' ' << GetName();
    }

};

class Dog : public Animal {
public:
    Dog(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, std::move(name), age} {}

    [[nodiscard]] Kind GetKind() const override {
        return Kind::Dog;
    }

    [[nodiscard]] std::string Say() const override {
        return "\"bark\"";
    }
    void Print(int naste) const override{
        for(int i = 0; i < naste; ++i) std::cout << ' ';
        std::cout << KindToString(GetKind()) << ' ' << GetName();
    }
};

class Budgie : public Animal {
public:
    Budgie(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, std::move(name), age} {}

    [[nodiscard]] Kind GetKind() const override {
        return Kind::Budgie;
    }

    [[nodiscard]] std::string Say() const override {
        return "\"chik\"";
    }
    void Print(int naste) const override{
        for(int i = 0; i < naste; ++i) std::cout << ' ';
        std::cout << KindToString(GetKind()) << ' ' << GetName();
    }
};

class Fish : public Animal {
public:
    Fish(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, std::move(name), age} {}

    [[nodiscard]] Kind GetKind() const override {
        return Kind::Fish;
    }

    [[nodiscard]] std::string Say() const override {
        return "\"blb\"";
    }
    void Print(int naste) const override{
        for(int i = 0; i < naste; ++i) std::cout << ' ';
        std::cout << KindToString(GetKind()) << ' ' << GetName();
    }
};


#endif

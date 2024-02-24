#ifndef PETS_H
#define PETS_H
#include <string>
#include "Owner.h"
#include <memory>

class Animal {
private:
    std::shared_ptr<Owner> owner;
    std::string Name;
    int Age;
    size_t m_ID;
    static inline size_t ID_st = 0;
public:
    Animal(std::shared_ptr<Owner>& own, std::string name, int age) : owner(own), Name(name), Age(age), m_ID(ID_st++) {}

    virtual std::string GetKind() const = 0;

    virtual std::string Say() const = 0;

    std::string GetName() const {
        return Name;
    }

    std::shared_ptr<Owner>& GetOwner() {
        return owner;
    }

    int GetAge() const {
        return Age;
    }

    size_t GetId() const {
        return m_ID;
    }
};

class Cat : public Animal {
public:
    Cat(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, name, age} {}

    std::string GetKind() const {
        return "кот";
    }

    std::string Say() const {
        return "мяу";
    }

    std::string Jump() const {
        return "прыг";
    }
};

class Dog : public Animal {
public:
    Dog(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, name, age} {}

    std::string GetKind() const {
        return "собака";
    }

    std::string Say() const {
        return "\"гав\"";
    }
};

class GuineaPig : public Animal {
public:
    GuineaPig(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, name, age} {}

    std::string GetKind() const {
        return "морская свинка";
    }

    std::string Say() const {
        return "\"хрю\"";
    }

};

class Budgie : public Animal {
public:
    Budgie(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, name, age} {}

    std::string GetKind() const {
        return "попугайчик";
    }

    std::string Say() const {
        return "\"чирик\"";
    }
};

class Fish : public Animal {
public:
    Fish(std::shared_ptr<Owner>& own, std::string name, int age) : Animal{own, name, age} {}

    std::string GetKind() const {
        return "рыбка";
    }

    std::string Say() const {
        return "\"буль\"";
    }
};
#endif

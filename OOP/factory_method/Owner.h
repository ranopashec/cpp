#ifndef OWNER_H
#define OWNER_H
#include <string>
#include <vector>
#include "Pets.h"

class Owner {
private:
    std::string Name;
    size_t m_ID;
    static inline size_t ID_st = 0;
public:
    Owner(std::string name) : Name(name), m_ID(ID_st++){}

    std::string GetName() const {
        return Name;
    }

    size_t GetId() const {
        return m_ID;
    }
};

#endif 

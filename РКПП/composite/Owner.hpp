#ifndef OWNER_HPP
#define OWNER_HPP
#include <string>
#include <utility>
#include <vector>
#include "Pets.hpp"

class Owner {
private:
    std::string Name;
    int m_ID;
    static inline int ID_st = 0;
public:
    explicit Owner(std::string name) : Name(std::move(name)), m_ID(ID_st++){}

    [[nodiscard]] std::string GetName() const {
        return Name;
    }

    [[nodiscard]] size_t GetId() const {
        return m_ID;
    }
};

#endif

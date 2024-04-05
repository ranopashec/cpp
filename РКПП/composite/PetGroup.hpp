#ifndef PETGROUP_HPP
#define PETGROUP_HPP
#include <utility>
#include <memory>
#include "iostream"
#include "Pets.hpp"

class PetGroup : public Animal{
public:
    PetGroup(std::shared_ptr<Owner> &own, std::string name, int age) : Animal(own, std::move(name), age) {}

    void Add(std::unique_ptr<Animal>& p) {
        c.emplace_back(std::move(p));
    }

    void Add(std::unique_ptr<PetGroup>& p) {
        c.emplace_back(std::move(p));
    }

    [[nodiscard]] Kind GetKind() const override {
        return Kind::PetGroup;
    }

    [[nodiscard]] std::string Say() const override{
        return "\"A lot of voices\"";
    }

    [[nodiscard]] std::vector<std::unique_ptr<Animal>>& GetAnimals(){
        return c;
    };

    void Print(int naste) const override{
        for (int i = 0 ; i < naste; ++i) std::cout << ' ';
        std::cout << GetName() <<":\n";
        for (auto& e : c){
            for (int i = 0 ; i < naste; ++i) std::cout << ' ';
            std::cout << "  ";
            e->Print(naste+1);
            std::cout << '\n';
        }
    }

    [[nodiscard]] size_t GetCount () const{
        return c.size();
    }

private:
    std::vector<std::unique_ptr<Animal>> c;
};


#endif

#ifndef FACTORY_H
#define FACTORY_H
#include "Pets.h"
#include "memory"
namespace df{
    class PetsFactory {
    public:
        static std::unique_ptr<Animal> CreatePet(std::string kind, std::shared_ptr<Owner>& owne, std::string name, int age){
            if (kind == "кот") {
                return std::make_unique<Cat>(owne, name, age);
            } else if (kind == "собака") {
                return std::make_unique<Dog>(owne, name, age);
            } else if (kind == "попугайчик") {
                return std::make_unique<Budgie>(owne, name, age);
            } else if (kind == "морская свинка") {
                return std::make_unique<GuineaPig>(owne, name, age);
            } else if (kind == "рыбка") {
                return std::make_unique<Fish>(owne, name, age);
            }
        }
    };
}
#endif

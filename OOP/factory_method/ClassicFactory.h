#ifndef DZ2_CLASSICFACTORY_H
#define DZ2_CLASSICFACTORY_H
#include "Pets.h"
#include "memory"
namespace cf{
    class PetsFactory {
    public:
        virtual std::unique_ptr<Animal> CreatePet(std::shared_ptr<Owner>& owne, std::string name, int age) const = 0;
    };

    class CatFactory : PetsFactory {
    public:
        std::unique_ptr<Animal> CreatePet(std::shared_ptr<Owner>& owne, std::string name, int age) const {
            return std::make_unique<Cat>(owne, name, age);
        }
    };

    class DogFactory : PetsFactory {
    public:
        std::unique_ptr<Animal> CreatePet(std::shared_ptr<Owner>& owne, std::string name, int age) const{
            return std::make_unique<Dog>(owne, name, age);
        }
    };

    class GuineaPigFactory : PetsFactory {
    public:
        std::unique_ptr<Animal> CreatePet(std::shared_ptr<Owner>& owne, std::string name, int age) const{
            return std::make_unique<GuineaPig>(owne, name, age);
        }
    };

    class BudgieFactory : PetsFactory {
    public:
        std::unique_ptr<Animal> CreatePet(std::shared_ptr<Owner>& owne, std::string name, int age) const{
            return std::make_unique<Budgie>(owne, name, age);
        }
    };

    class FishFactory : PetsFactory {
    public:
        std::unique_ptr<Animal> CreatePet(std::shared_ptr<Owner>& owne, std::string name, int age) const{
            return std::make_unique<Fish>(owne, name, age);
        }
    };

}
#endif //DZ2_CLASSICFACTORY_H

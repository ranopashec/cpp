#include <iostream>
#include "PetGroup.h"
/*
 * Преобразовать решение задания лабораторной работы No1
 * (в соответствии с вашим вариантом) с использованием паттерна Composite,
 * реализовав подклассы Primitive и Composite.
 * Обобщенный метод для всех классов выбрать самостоятельно.
 */

using namespace std;

int main() {
    shared_ptr<Owner> owner = make_shared<Owner>("Vasya");

    unique_ptr<Animal> dog1 = make_unique<Dog>(owner, "Rex", 2);
    unique_ptr<Animal> dog2 = make_unique<Dog>(owner, "Fex", 3);


    unique_ptr<PetGroup> pet_union = make_unique<PetGroup>(owner, "Pets1", 0);

    pet_union->Add(dog1);
    pet_union->Add(dog2);

    pet_union->Print(0);


    shared_ptr<Owner> owner1 = make_shared<Owner>("Olya");

    unique_ptr<Animal> dog3 = make_unique<Dog>(owner1, "Mex", 1);
    unique_ptr<Animal> cat1 = make_unique<Cat>(owner1, "Kisa", 1);

    unique_ptr<PetGroup> pet_union2 = make_unique<PetGroup>(owner1, "Pets2", 0);


    pet_union2->Add(dog3);
    pet_union2->Add(cat1);

    pet_union2->Print(0);
    std::cout << "pet_union size: " << pet_union->GetCount() << '\n';

    pet_union->Add(pet_union2);

    pet_union->Print(0);

}

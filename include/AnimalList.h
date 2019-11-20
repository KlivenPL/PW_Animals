#ifndef ANIMALLIST_H
#define ANIMALLIST_H
#include <functional>
#include "Animal.h"
class AnimalList {
    private:
        Animal *head = nullptr;
        void PrintAnimals(Animal *node);
        Animal *FindAnimalById(Animal *node, int id);
        Animal *GetAnimalAtIndex(int i);
        int GetIndexOf(Animal *animal);
        void Insert(Animal *animal, int index);
        int FindIndexForNewAnimal(Animal *newAnimal);
        void RemoveAnimal(Animal *animal);

    public:
        AnimalList();
        ~AnimalList();
        AnimalList &operator = (const AnimalList &);
        AnimalList (const AnimalList &);
        AnimalList operator - (const AnimalList &) const;
        friend AnimalList operator + (const AnimalList &list1const, const AnimalList &list2const);

        int Count(Animal *node, int prevCount = 0);
        Animal *FindFirstThat(std::function<bool(Animal &animal)> predicate);
        void PrintAnimals();
        void AddAnimal(char *name, int id, int ownerId, int days);
        int &modify(char *name, int id, int owner_id);
        void RemoveOwner(int ownerId);
};
#endif
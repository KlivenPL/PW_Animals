#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include "Animal.h"
class AnimalList {
    private:
        Animal *head = nullptr;

        void PrintAnimals(Animal *node);
        Animal *FindAnimalById(Animal *node, int id);
        int Count(Animal *node, int prevCount = 0);
        Animal *GetAnimalAtIndex(int i);
        int GetIndexOf(Animal *animal);
        void Insert(Animal *animal, int index);
        int FindIndexForNewAnimal(Animal *newAnimal);
        void RemoveAnimal(Animal *animal);

    public:
        AnimalList();
        ~AnimalList();

        void PrintAnimals();
        void AddAnimal(char *name, int id, int ownerId, int days);
        int &modify(char *name, int id, int owner_id);
        void RemoveOwner(int ownerId);
};
#endif
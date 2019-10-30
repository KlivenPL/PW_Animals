#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include "Animal.h"
class AnimalList {
    public:
        Animal *head = nullptr;

        AnimalList();
        ~AnimalList();

        void PrintAnimals(Animal *node);
        void PrintAnimals();
        Animal *FindAnimalById(Animal *node, int id);
        int Count(Animal *node, int prevCount = 0);
        Animal *GetAnimalAtIndex(int i);
        int GetIndexOf(Animal *animal);
        void Insert(Animal *animal, int index);
        int FindIndexForNewAnimal(Animal *newAnimal);
        void RemoveAnimal(Animal *animal);
        int &modify(char *name, int id, int owner_id);
        void RemoveOwner(int ownerId);
        void AddAnimal(char *name, int id, int ownerId, int days);
};
#endif
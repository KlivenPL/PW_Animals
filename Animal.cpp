//
// Created by oskar on 16.10.2019.
//

#include "Animal.h"
#include <iostream>
#include <cstring>
using namespace std;
Animal *head = nullptr;

Animal *CreateAnimal (char *name, int id, int ownerId, int days){
    auto *animal = new Animal();
    animal->name = new char[strlen(name) + 1]();
    strcpy(animal->name, name);
    animal->id = id;
    animal->owner_id = ownerId;
    animal->days = days;
    animal->next = nullptr;

    return animal;
}

void PrintAnimals(Animal *node){
    if (node != nullptr){
        cout << "Animal: " << node->name << ", id: " << node->id << ", owner id: " << node->owner_id << ", days: " << node->days << endl;
        PrintAnimals(node->next);
    }
}

void PrintAnimals(){
    PrintAnimals(head);
    cout << endl;
}

Animal *FindAnimalById(Animal *node, int id){
    if (node == nullptr)
        return nullptr;
    if (node->id == id)
        return node;
    return FindAnimalById(node->next, id);
}

int Count(Animal *node, int prevCount = 0){
    if (node == nullptr)
        return prevCount;
    prevCount++;
    return Count(node->next, prevCount);
}

Animal *GetAnimalAtIndex(int i){
    Animal *animal = head;
    for (int j = 0; j < i; ++j) {
        if (animal == nullptr)
            throw invalid_argument("Animal of this index does not exists");
        animal = animal->next;
    }
    return animal;
}

int GetIndexOf(Animal *animal){
    Animal *node = head;
    int index = 0;
    for (int i = 0; node != nullptr; ++i) {
        if (node == animal)
            return index;
        node = node->next;
        index++;
    }
    throw invalid_argument("This Animal is not in the list");
}

void Insert(Animal *animal, int index){
    int count = Count(head);
    if (index == 0){
        // we push to the front
        animal->next = head;
        head = animal;
        return;
    }
    if (index == count){
        // we add to the end
        Animal *tail = GetAnimalAtIndex(index);
        tail->next = animal;
        animal->next = nullptr;
        return;
    }
    if (index < count) {
        Animal *prev = GetAnimalAtIndex(index - 1);
        Animal *current = GetAnimalAtIndex(index);
        animal->next = current;
        prev->next = animal;
        return;
    }
    throw invalid_argument ("Index must be smaller (or equal) than List count");
}

int FindIndexForNewAnimal(Animal *newAnimal){
    int index = 0;
    Animal *node = head;
    for (int i = 0; node; ++i) {
        if (newAnimal->owner_id <= node->owner_id)
            return index;
        node = node->next;
        index++;
    }
    return index;
}

void FreeAnimalMemory(Animal *animal){
    delete animal->name;
    delete animal;
}

void RemoveAnimal(Animal *animal){
    if (animal == head){
        head = animal->next;
        FreeAnimalMemory(animal);
        return;
    }
    Animal *prev = GetAnimalAtIndex(GetIndexOf(animal) - 1);
    prev->next = animal->next;
    FreeAnimalMemory(animal);
}

void RemoveOwner(int ownerId){
    int count = Count(head);
    for (int i = count - 1; i >= 0; i--) {
        Animal *animal = GetAnimalAtIndex(i);
        if (animal->owner_id == ownerId)
            RemoveAnimal(animal);
    }
}

void AddAnimal(char *name, int id, int ownerId, int days){
    Animal *animal = FindAnimalById(head, id);
    if (animal == nullptr){
        animal = CreateAnimal(name, id, ownerId, days);
        int newIndex = FindIndexForNewAnimal(animal);
        Insert(animal, newIndex);
    } else {
        delete animal->name;
        animal->name = new char[strlen(name)]();
        strcpy(animal->name, name);
    }
}
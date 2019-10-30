#include <iostream>
#include <cstring>
#include "../include/AnimalList.h"
using namespace std;


AnimalList::AnimalList(){
    this->head=nullptr;
}

AnimalList::~AnimalList(){
    int count = Count(head);
    for (int i = count - 1; i >= 0; i--) {
        Animal *animal = GetAnimalAtIndex(i);
        RemoveAnimal(animal);
    }
}

void AnimalList::PrintAnimals(Animal *node){
    if (node != nullptr){
        cout << "Animal: " << node->name << ", id: " << node->id << ", owner id: " << node->owner_id << ", days: " << node->days << endl;
        PrintAnimals(node->next);
    }
}

void AnimalList::PrintAnimals(){
    PrintAnimals(head);
    cout << endl;
}
Animal *AnimalList::FindAnimalById(Animal *node, int id){
    if (node == nullptr)
        return nullptr;
    if (node->id == id)
        return node;
    return FindAnimalById(node->next, id);
}

int AnimalList::Count(Animal *node, int prevCount){
    if (node == nullptr)
        return prevCount;
    prevCount++;
    return Count(node->next, prevCount);
}

Animal *AnimalList::GetAnimalAtIndex(int i){
    Animal *animal = head;
    for (int j = 0; j < i; ++j) {
        if (animal == nullptr)
            throw invalid_argument("Animal of this index does not exists");
        animal = animal->next;
    }
    return animal;
}

int AnimalList::GetIndexOf(Animal *animal){
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

void AnimalList::Insert(Animal *animal, int index){
    int count = Count(head);
    if (index == 0){
        // we push to the front
        animal->next = head;
        head = animal;
        return;
    }
    if (index == count){
        // we add to the end
        Animal *tail = GetAnimalAtIndex(index - 1);
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

int AnimalList::FindIndexForNewAnimal(Animal *newAnimal){
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

void AnimalList::RemoveAnimal(Animal *animal){
    if (animal == head){
        head = animal->next;
        delete animal;
        return;
    }
    Animal *prev = GetAnimalAtIndex(GetIndexOf(animal) - 1);
    prev->next = animal->next;
    delete animal;
}

int &AnimalList::modify(char *name, int id, int owner_id){
    Animal *animal = FindAnimalById(head, id);

    if (animal){
        if (strcmp(animal->name, name) != 0){
            animal->UpdateName(name);
        }

        if (animal->owner_id != owner_id){
            Animal *newAnimal = new Animal(name, id, owner_id, animal->days);
            RemoveAnimal(animal);
            int newIndex = FindIndexForNewAnimal(newAnimal);
            Insert(newAnimal, newIndex);
            return newAnimal->days;
        }

        return animal->days;
    } else {
        animal = new Animal(name, id, owner_id, 1);
        int newIndex = FindIndexForNewAnimal(animal);
        Insert(animal, newIndex);
        return animal->days;
    }
}

void AnimalList::RemoveOwner(int ownerId){
    int count = Count(head);
    for (int i = count - 1; i >= 0; i--) {
        Animal *animal = GetAnimalAtIndex(i);
        if (animal->owner_id == ownerId)
            RemoveAnimal(animal);
    }
}

void AnimalList::AddAnimal(char *name, int id, int ownerId, int days){
    Animal *animal = FindAnimalById(head, id);
    if (animal == nullptr){
        animal = new Animal(name, id, ownerId, days);
        int newIndex = FindIndexForNewAnimal(animal);
        Insert(animal, newIndex);
    } else {
        animal->UpdateName(name);
    }
}
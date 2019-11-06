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
AnimalList &AnimalList::operator= (const AnimalList &animalList){
    cout << "Kopiuje liste operatorem"  << endl;
    this->~AnimalList();
    this->head = nullptr;
    AnimalList *newList = new AnimalList(animalList);
    return *newList;
}

AnimalList::AnimalList(const AnimalList &animalList){
    cout << "Kopiuje liste" << endl;
    this->head = new Animal(*animalList.head);
    Animal *nodeExisting = animalList.head;
    Animal *nodeNew = head;
    for (int i = 0; nodeExisting->Next(); i++) {
        nodeNew->Next() = new Animal(*nodeExisting->Next());
        nodeExisting = nodeExisting->Next();
        nodeNew = nodeNew->Next();
    }
    
}

void AnimalList::PrintAnimals(Animal *node){
    if (node != nullptr){
        node->PrintAnimal();
        PrintAnimals(node->Next());
    }
}

void AnimalList::PrintAnimals(){
    PrintAnimals(head);
    cout << endl;
}
Animal *AnimalList::FindAnimalById(Animal *node, int id){
    if (node == nullptr)
        return nullptr;
    if (node->Id() == id)
        return node;
    return FindAnimalById(node->Next(), id);
}

int AnimalList::Count(Animal *node, int prevCount){
    if (node == nullptr)
        return prevCount;
    prevCount++;
    return Count(node->Next(), prevCount);
}

Animal *AnimalList::GetAnimalAtIndex(int i){
    Animal *animal = head;
    for (int j = 0; j < i; ++j) {
        if (animal == nullptr)
            throw invalid_argument("Animal of this index does not exists");
        animal = animal->Next();
    }
    return animal;
}

int AnimalList::GetIndexOf(Animal *animal){
    Animal *node = head;
    int index = 0;
    for (int i = 0; node != nullptr; ++i) {
        if (node == animal)
            return index;
        node = node->Next();
        index++;
    }
    throw invalid_argument("This Animal is not in the list");
}

void AnimalList::Insert(Animal *animal, int index){
    int count = Count(head);
    if (index == 0){
        // we push to the front
        animal->Next() = head;
        head = animal;
        return;
    }
    if (index == count){
        // we add to the end
        Animal *tail = GetAnimalAtIndex(index - 1);
        tail->Next() = animal;
        animal->Next() = nullptr;
        return;
    }
    if (index < count) {
        Animal *prev = GetAnimalAtIndex(index - 1);
        Animal *current = GetAnimalAtIndex(index);
        animal->Next() = current;
        prev->Next() = animal;
        return;
    }
    throw invalid_argument ("Index must be smaller (or equal) than List count");
}

int AnimalList::FindIndexForNewAnimal(Animal *newAnimal){
    int index = 0;
    Animal *node = head;
    for (int i = 0; node; ++i) {
        if (newAnimal->Owner_id() <= node->Owner_id())
            return index;
        node = node->Next();
        index++;
    }
    return index;
}

void AnimalList::RemoveAnimal(Animal *animal){
    if (animal == head){
        head = animal->Next();
        delete animal;
        return;
    }
    Animal *prev = GetAnimalAtIndex(GetIndexOf(animal) - 1);
    prev->Next() = animal->Next();
    delete animal;
}

int &AnimalList::modify(char *name, int id, int owner_id){
    Animal *animal = FindAnimalById(head, id);

    if (animal){
        if (strcmp(animal->Name(), name) != 0){
            animal->UpdateName(name);
        }

        if (animal->Owner_id() != owner_id){
            Animal *newAnimal = new Animal(name, id, owner_id, animal->Days());
            RemoveAnimal(animal);
            int newIndex = FindIndexForNewAnimal(newAnimal);
            Insert(newAnimal, newIndex);
            return newAnimal->Days();
        }

        return animal->Days();
    } else {
        animal = new Animal(name, id, owner_id, 1);
        int newIndex = FindIndexForNewAnimal(animal);
        Insert(animal, newIndex);
        return animal->Days();
    }
}

void AnimalList::RemoveOwner(int ownerId){
    int count = Count(head);
    for (int i = count - 1; i >= 0; i--) {
        Animal *animal = GetAnimalAtIndex(i);
        if (animal->Owner_id() == ownerId)
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
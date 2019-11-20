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

AnimalList AnimalList::operator - (const AnimalList &list2const) const {
    AnimalList *list = new AnimalList(*this);
    Animal *node1 = list->head;
    Animal *node2 = list2const.head;
    AnimalList list2 = (AnimalList) list2const;

    int count1 = list->Count(node1);
    int count2 = ((AnimalList) list2).Count(node2);
    
    for (int i = count1 - 1; i >= 0; i--){
        Animal *list1Anim = list->GetAnimalAtIndex(i);
        for (int j = count2 - 1; j >= 0; j--){
            Animal *list2Anim = list2.GetAnimalAtIndex(j);
            if (list1Anim->Id() == list2Anim->Id()){
                list->RemoveAnimal(list1Anim);
            }
        }
    }
    return *list;
}

AnimalList operator + (const AnimalList &list1const, const AnimalList &list2const) {
    AnimalList list1 = (AnimalList) list1const;
    AnimalList list2 = (AnimalList) list2const;

    AnimalList *newList = new AnimalList(list1);

    int count2 = list2.Count(list2.head);
    
    for (int i = 0; i < count2 ; i++){
        Animal *anim2 = list2.GetAnimalAtIndex(i);
        auto sameIdAnimal = list1.FindFirstThat([&anim2] (Animal tmpAnim) -> bool { return (tmpAnim.Id() == anim2->Id());});
        if (sameIdAnimal){
            // trzeba znalezc instancje tego zwierza w nowej liscie.
            auto sameIdAnimalNewList = newList->FindFirstThat([&anim2] (Animal tmpAnim) -> bool { return (tmpAnim.Id() == anim2->Id());});
            sameIdAnimalNewList->Owner_id() = anim2->Owner_id();
            if (strcmp(sameIdAnimal->Name(), anim2->Name())){
                // bledne dane - usuwamy zwierzaka
                newList->RemoveAnimal(sameIdAnimalNewList);
            }
        } else {
            // nie ma animala z takim id w list1
            newList->AddAnimal(anim2->Name(), anim2->Id(), anim2->Owner_id(), anim2->Days());
        }
    }
    // tanie (w napisaniu) sortowanie 
    AnimalList *finalList = new AnimalList();
    int newListCount = newList->Count(newList->head);
    for (int i = 0; i < newListCount; i++){
        Animal *anim = newList->GetAnimalAtIndex(i);
        finalList->AddAnimal(anim->Name(), anim->Id(), anim->Owner_id(), anim->Days());
    }
    delete newList;
    return *finalList;
}

Animal *AnimalList::FindFirstThat(std::function<bool(Animal &animal)> predicate){
    int count = Count(head);
    for (int i = 0; i < count; i++){
        Animal *tmpAnim = GetAnimalAtIndex(i);
        if (predicate(*tmpAnim))
            return tmpAnim;
    }
    return nullptr;
    
}

AnimalList::AnimalList(const AnimalList &animalList){
    if (this->head == animalList.head)
        return;
//    cout << "Kopiuje liste" << endl;
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
#include <iostream>
#include "../include/Animal.h"
#include "../include/AnimalList.h"
using namespace std;

int main() {
    AnimalList *list1 = new AnimalList();
    list1->modify("Nowa z Modify", 55, 11)=3333;
    list1->PrintAnimals();
    list1->AddAnimal("Renia2", 60, 3, 1);
    list1->AddAnimal("Anna1", 1, 1, 1);
    list1->AddAnimal("Anna2", 2, 1, 1);
    list1->AddAnimal("Anna3", 3, 1, 1);
    list1->AddAnimal("Anna4", 4, 1, 1);
    list1->AddAnimal("Anna5", 5, 1, 1);
    list1->AddAnimal("Anna6", 6, 1, 1);
    list1->PrintAnimals();
    list1->AddAnimal("ZmianaNAawy", 4, 1, 1);
    list1->AddAnimal("Renia1", 50, 3, 1);
    list1->AddAnimal("Berta1", 51, 2, 1);
    list1->AddAnimal("Berta2", 61, 2, 1);
    list1->PrintAnimals();
    list1->RemoveOwner(2);
    list1->AddAnimal("Berta70", 51, 3, 1);
    list1->AddAnimal("Berta69000", 52, 2, 1);
    list1->RemoveOwner(1);
    list1->PrintAnimals();
    list1->modify("Berta2137", 51, 7) = 55;
    list1->modify("Anna3", 3, 69) = 33;
    list1->modify("Nowy", 77, 0) = 21;
    list1->modify("Anna3", 3, 69) = list1->modify("Nowy zmiana nazwy", 77, 99) + 5;
    list1->PrintAnimals();
    delete list1;

    AnimalList list2;
    list2.modify("Nowa z Modify", 55, 11)=3333;
    list2.PrintAnimals();
    list2.AddAnimal("Renia2", 60, 3, 1);
    list2.AddAnimal("Anna1", 1, 1, 1);
    list2.AddAnimal("Anna2", 2, 1, 1);
    list2.AddAnimal("Anna3", 3, 1, 1);
    list2.AddAnimal("Anna4", 4, 1, 1);
    list2.AddAnimal("Anna5", 5, 1, 1);
    list2.AddAnimal("Anna6", 6, 1, 1);
    list2.PrintAnimals();
    list2.AddAnimal("ZmianaNAawy", 4, 1, 1);
    list2.AddAnimal("Renia1", 50, 3, 1);
    list2.AddAnimal("Berta1", 51, 2, 1);
    list2.AddAnimal("Berta2", 61, 2, 1);
    list2.PrintAnimals();
    list2.RemoveOwner(2);
    list2.AddAnimal("Berta70", 51, 3, 1);
    list2.AddAnimal("Berta69000", 52, 2, 1);
    list2.RemoveOwner(1);
    list2.PrintAnimals();
    list2.modify("Berta2137", 51, 7) = 55;
    list2.modify("Anna3", 3, 69) = 33;
    list2.modify("Nowy", 77, 0) = 21;
    list2.modify("Anna3", 3, 69) = list2.modify("Nowy zmiana nazwy", 77, 99) + 5;
    list2.PrintAnimals();
    return 0;
}
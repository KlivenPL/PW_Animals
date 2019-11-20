#include <iostream>
#include "../include/Animal.h"
#include "../include/AnimalList.h"
using namespace std;

int main() {
    AnimalList *list1 = new AnimalList();
    list1->AddAnimal("losowy1", 10, 20, 30);
    list1->AddAnimal("list1 anim1", 1, 1, 1);
    list1->AddAnimal("a ten jest", 99, 30, 1);
    list1->AddAnimal("tego nie ma 1", 6, 44, 1);
    list1->AddAnimal("dublikat", 69, 911, 1);

    AnimalList *list2 = new AnimalList();
    list2->AddAnimal("losowy2", 30, 30, 40);
    list2->AddAnimal("list2 anim1", 4, 54, 1);
    list2->AddAnimal("a ten jest", 99, 365, 1);
    list2->AddAnimal("tego nie ma 2", 6, 10, 1);
    list2->AddAnimal("dublikat", 69, 2137, 1);

    AnimalList remList = *list1 - *list2;
    cout << endl << endl << "remList:" << endl;
    remList.PrintAnimals();

    AnimalList addList = *list1 + *list2;
    cout << endl << endl << "addListPrint:" << endl;

    delete list1;
    delete list2;
    addList.PrintAnimals();
    return 0;
}
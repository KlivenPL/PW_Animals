#include <iostream>
#include "Animal.h"
using namespace std;

int main() {
    AddAnimal("Renia2", 60, 3, 1);
    AddAnimal("Anna1", 1, 1, 1);
    AddAnimal("Anna2", 2, 1, 1);
    AddAnimal("Anna3", 3, 1, 1);
    AddAnimal("Anna4", 4, 1, 1);
    AddAnimal("Anna5", 5, 1, 1);
    AddAnimal("Anna6", 6, 1, 1);
    AddAnimal("ZmianaNAawy", 4, 1, 1);
    AddAnimal("Renia1", 50, 3, 1);
    AddAnimal("Berta1", 51, 2, 1);
    AddAnimal("Berta2", 61, 2, 1);
    PrintAnimals();
    RemoveOwner(2);
    AddAnimal("Berta70", 51, 3, 1);
    AddAnimal("Berta69000", 52, 2, 1);
    PrintAnimals();
    return 0;
}
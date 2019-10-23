//
// Created by oskar on 16.10.2019.
//

#ifndef TESTOWY_ANIMAL_H
#define TESTOWY_ANIMAL_H
#include <iostream>
using namespace std;

struct Animal {
    char *name;
    int id;
    int owner_id;
    int days;
    Animal *next;
};

void PrintAnimals();
void AddAnimal(char *name, int id, int ownerId, int days);
void RemoveOwner(int ownerId);
int &modify(char *name, int id, int owner_id = 1);
#endif //TESTOWY_ANIMAL_H

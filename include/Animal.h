//
// Created by oskar on 16.10.2019.
//

#ifndef TESTOWY_ANIMAL_H
#define TESTOWY_ANIMAL_H
#include <iostream>
using namespace std;

class Animal {
    public:
        char *name;
        int id;
        int owner_id;
        int days;
        Animal *next;

        Animal(char *name, int id, int ownerId, int days);
        ~Animal();

        void UpdateName(char *name);
        void RemoveOwner(int ownerId);
};

#endif //TESTOWY_ANIMAL_H

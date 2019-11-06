#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
    private:
        char *name;
        int id;
        int owner_id;
        int days;
        Animal *next;

    public:
        Animal(char *name, int id, int ownerId, int days);
        ~Animal();

        void UpdateName(char *name);
        void PrintAnimal();

        char *&Name();
        int &Id();
        int &Owner_id();
        int &Days();
        Animal *&Next();
};

#endif

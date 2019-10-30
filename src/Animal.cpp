#include "../include/Animal.h"
#include <iostream>
#include <cstring>

using namespace std;

Animal::Animal (char *name, int id, int ownerId, int days){
    this->name = nullptr;
    UpdateName(name);
    this->id = id;
    this->owner_id = ownerId;
    this->days = days;
    this->next = nullptr;

    cout << "New animal created: ";
    PrintAnimal();
}

Animal::~Animal(){
    cout << "Animal deleted: ";
    PrintAnimal();
    if (this->name)
        delete[] this->name;
}

void Animal::UpdateName(char *name){
    if (this->name)
        delete[] this->name;
    this->name = new char[strlen(name) + 1]();
    strcpy(this->name, name);
}

void Animal::PrintAnimal(){
    cout << "Animal: " << this->name << ", id: " << this->id << ", owner id: " << this->owner_id << ", days: " << this->days << endl;
}

char *&Animal::Name(){
    return this->name;
}

int &Animal::Id(){
    return this->id;
}

int &Animal::Owner_id(){
    return this->owner_id;
}

int &Animal::Days(){
    return this->days;
}

Animal *&Animal::Next(){
    return this->next;
}

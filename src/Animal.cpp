//
// Created by oskar on 16.10.2019.
//

#include "../include/Animal.h"
#include <iostream>
#include <cstring>

using namespace std;

void Animal::UpdateName(char *name){
    if (this->name)
        delete this->name;
    this->name = new char[strlen(name) + 1]();
    strcpy(this->name, name);
}

Animal::Animal (char *name, int id, int ownerId, int days){
    this->name = nullptr;
    UpdateName(name);
    this->id = id;
    this->owner_id = ownerId;
    this->days = days;
    this->next = nullptr;
}

Animal::~Animal(){
    if (this->name)
        delete[] this->name;
}

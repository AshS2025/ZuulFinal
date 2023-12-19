#include <iostream>
#include <cstring>
#include <vector>

#include "Item.h"

using namespace std;

//constructor
Item::Item(char* newDescription){
strcpy(description, newDescription);

}
//Item name/desciprtion
char* Item::getDescription(){
    return description;
}

Item::~Item(){} //destructor
//are the destructors even used??

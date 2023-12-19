
#include <iostream>
#include <cstring>
#include <vector>

#include "Item.h"
#include "Room.h"

using namespace std;



//room descriptions
Room::Room(char* newDescription){
strcpy(description, newDescription);

}

//Item functions
Item Room::getItem(char* itemTitle){
vector <Item> :: iterator it;
for(it = Items.begin(); it != Items.end(); it++){
if(strcmp(it->getDescription(), itemTitle) == 0){
return (*it);
    }
}
return 0; 
    
}

void Room::setItem(Item newItem){ //adding new item
Items.push_back(newItem);
}


void Room::removeItem(char* itemTitle){ //removing item
vector <Item> :: iterator it2;
for(it2 = Items.begin(); it2 != Items.end();it2++){
if(strcmp( it2->getDescription(), itemTitle) == 0){
Items.erase(it2);
break;
    }
}
} // NEED HELP

void Room :: printItems(){ //printing out the inventory
    vector <Item> :: iterator it3;
    for(it3= Items.begin(); it3 != Items.end(); it3++){
    cout << it3->getDescription() << ",";
  }
  cout << endl;
}


void Room::ExitsAndItems(){ //prints out info in current room
    cout << "Exits: " << endl;
  for(map<char*, Room*>::iterator it = exits.begin(); it != exits.end(); it++){
    cout << " " << it->first;
  }
  cout << endl;
  cout << "Items in this room: " << endl;
  printItems();
}

void Room::setExit(char* newDirection,Room* neighbor){
  exits[newDirection] = neighbor;
  } // NEED HELP


Room* Room::getExit(char* newDirection){
map <char*, Room*>:: iterator ptr;
for (ptr = (exits).begin(); ptr != exits.end(); ptr++)  {
if (strcmp(ptr->first, newDirection)==0) {
return ptr->second;
    }
}
    
return 0;
}

//getting room description
char* Room :: getRoomDescription(){
    return description;
}
 

//Room Header
#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <vector>
#include <map>

#include "Item.h"

using namespace std;

//Room Class
class Room {
private:
char description[100];

map<char*, Room*> exits;
vector <Item> Items;
    
    
public:
  Room(char* newDescription); // constructor
  ~Room(); //destructor
    
//Exit stuff
  Room* getExit(char* newDirection); //getting exits
  void setExit(char* newDirection, Room* neighbor); //used setting exits during initialization
  void ExitsAndItems(); //printing out room info
    
//  Item functiosn
Item* getItem (char* itemTitle);
void removeItem (char* itemTitle);
void printItems();     
void setItem (Item newItem);
  
    
//returning room name/description
char* getRoomDescription();
};

#endif

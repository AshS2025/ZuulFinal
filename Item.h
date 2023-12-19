#ifndef ITEM_H
#define ITEM_H

#include <cstring>

using namespace std;

//item class
class Item {
private:
char description[100]; 
    
public:
  Item(char* newDescription); //cosntructor
  ~Item(); //destructor
  char* getDescription(); //item description
  //a lot of the item functualityis in the room files
};



#endif

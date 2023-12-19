/*

 Ashvika Singhal
 Zuul: the newest, boringest, text-based adventure game
 11/28/23
 
 Note: thanks to Jaz for helping me debug my program

 Steal all the items and get to the train station


Have to type in command and then item/direction
Examples:
MOVE South
GET Gargoyle
DROP Gucci
 
 */

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

// initializing functions
void help();
void get(Room* &currentRoom, vector<Item> &inventory);
void drop(Room* &currentRoom, vector<Item> &inventory);
void move(Room* &currentRoom);
bool checkWin(Room* &currentRoom, vector<Item> &inventory, Room* Station);
void printInventory(vector<Item> &inventory);

int main() {
    // initializing variables
    vector<Room*> Rooms;
    vector<Room*>::iterator ptr;
    vector<Item> inventory;
    bool running= true;
    char userInput[100];

    //Adventure
    cout << "Welcome to Zuul!" << endl;
    cout << "Zuul has topped boredom charts around the country" << endl;
    cout << "In this 'adventure' game, you are a high profile burglar, stealing Zuulville's most prized posessions" << endl;
    cout << "your goal is to steal all the items and make it back to the train station" << endl;
    cout << "this is the greatest heist of the century and is certainly the greatest thing you will ever achieve. Good luck." << endl;
    cout << " " << endl;

    // all possible directions
    char* North = (char*)("North");
    char* East = (char*)("East");
    char* South = (char*)("South");
    char* West = (char*)("West");

    // Room set up
    map<char*, Room*> initialMap;

    char gateDescription[100] = "You are at the entrance to this miserable city..";
    Room* Gate = new Room(gateDescription);

    char shopDescription[100] = "is it even worth stealing from this tacky souvenir shop?";
    Room* Shop = new Room(shopDescription);

    char stationDescription[100] = "train station is the only way out of the city";
    Room* Station = new Room(stationDescription);

    char hotelDescription[100] = "this hotel seems like a good place to hide everything";
    Room* Hotel = new Room(hotelDescription);

    char marketDescription[100] = "supermarket has some good groceries and ooh what else";
    Room* Market = new Room(marketDescription);

    char mallDescription[100] = "okkk a designer mall this should have some good stuff";
    Room* Mall = new Room(mallDescription);

    char parkingDescription[100] = "what an ominous parking garage";
    Room* Parking = new Room(parkingDescription);

    char clubDescription[100] = "this night club is literally the only good part of this town";
    Room* Club = new Room(clubDescription);

    char restaurantDescription[100] = "the food at this restaurant is surprisingly good";
    Room* Restaurant = new Room(restaurantDescription);

    char plazaDescription[100] = "stealing something from the plaza will be quite the feat";
    Room* Plaza = new Room(plazaDescription);

    char bankDescription[100] = "i've always wanted to lead a bank heist...";
    Room* Bank = new Room(bankDescription);

    char salonDescription[100] = "so this is the famed salon of Zuulville";
    Room* Salon = new Room(salonDescription);

    char castleDescription[100] = "aha at last, the royal castle";
    Room* Castle = new Room(castleDescription);

    char arboretumDescription[100] = "the arboretum is the only place in Zuulville with trees";
    Room* Arboretum = new Room(arboretumDescription);

    char dungeonDescription[200] = "these suckers in the dungeon..I'd never be stupid enough to get caught";
    Room* Dungeon = new Room(dungeonDescription);

//Exit set ups

  Gate->setExit(West, Shop);
  Gate->setExit(East, Station);
  Gate->setExit(North, Mall);

  Shop->setExit(East, Gate);
  Shop->setExit(North, Market);

  Station->setExit(West, Gate);
  Station->setExit(East, Hotel);
  Station->setExit(North, Parking);

  Hotel->setExit(East, Station);
  Hotel->setExit(North, Club);

  Market->setExit(South, Shop);
  Market->setExit(North, Restaurant);

  Mall->setExit(South, Gate);
  Mall->setExit(East, Parking);
  Mall->setExit(North, Plaza);

  Parking->setExit(South, Station);
  Parking->setExit(East, Club);
  Parking->setExit(West, Mall);
  Parking->setExit(North, Bank);

  Club->setExit(South, Hotel);
  Club->setExit(West, Parking);

  Restaurant->setExit(South, Market);
  Restaurant->setExit(East, Plaza);
  Restaurant->setExit(North, Salon);

  Plaza->setExit(East, Bank);
  Plaza->setExit(West, Restaurant);
  Plaza->setExit(South, Mall);
  Plaza->setExit(North, Castle);

  Bank->setExit(East, Plaza);
  Bank->setExit(South, Parking);

  Salon->setExit(South, Restaurant);
  Salon->setExit(East, Castle);

  Castle->setExit(South, Plaza);
  Castle->setExit(North, Dungeon);
 Castle->setExit(East, Arboretum);
 Castle->setExit(West, Salon);

  Arboretum->setExit(West, Castle);

  Dungeon->setExit(South, Castle);
    
    
    //Items
 /*
 Items:
Gargoyle (Plaza)
Gucci Bag (Mall)
Roll of Cash (Bank)
Crown (Castle)
ID (Nightclub)
 */

    char gargoyle[100] = "Gargoyle";
    Item* Gargoyle = new Item(gargoyle);
    Plaza->setItem(*Gargoyle);
    
    char guccibag[100] = "GucciBag";
    Item* GucciBag = new Item(guccibag);
    Mall ->setItem(*GucciBag);
    
    char rollcash[100] = "Cash";
    Item* RollCash = new Item(rollcash);
    Bank ->setItem(*RollCash);
    
    char crown[100] = "Crown";
    Item* Crown = new Item(crown);
    Castle->setItem(*Crown);
    
    char id[100] = "ID";
    Item* ID = new Item(id);
    Club->setItem(*ID);

    
  //gate = start
  Room* currentRoom = Gate;

    //Prints out some info
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems();
    cout << endl;
    cout << "Available Commands: HELP, MOVE, GET, DROP, QUIT, and INVENTORY. " << endl;
    cout << " " << endl;
    cout << "Enter a command: " << endl;

    // game functionality
    while (running==true) {
        //reads in user command
        cin >> userInput;
        
        //run help method if input is HELP
        if (strcmp(userInput, "HELP") == 0) {
            help();
        }
        //move rooms and then check for win
        else if (strcmp(userInput, "MOVE") == 0) {
            move(currentRoom);
            if (checkWin(currentRoom, inventory, Station) == true) {
                cout << "CONGRATS!!! you have successfully execuyted the grandest heist of the century. true legend. mad respect." << endl;
                running = false;
                exit(0);
            }
        }

        else if (strcmp(userInput, "GET") == 0) {
            get(currentRoom, inventory);
             if (checkWin(currentRoom, inventory, Station) == true) {
                cout << "Congrats on the grandest heist of the century" << endl;
                running = false;
                exit(0);
            }
        }

        else if (strcmp(userInput, "DROP") == 0) {
            drop(currentRoom, inventory);
        }

        else if (strcmp(userInput, "QUIT") == 0) {
            cout << "Thanks for playing." << endl;
            running= false;
            exit(0);
        }

        else if (strcmp(userInput, "INVENTORY") == 0) {
            printInventory(inventory);
        }
    }
    
    return 0;
}

//help function
void help() {
    cout << "Your commands are HELP, MOVE, GET, DROP, and INVENTORY." << endl;
    cout << "You need to steal all the items and make it back to the train station." << endl;
    cout << " " << endl;

}

//move function
void move(Room* &currentRoom) {
    char move[100];
    
    //current room info
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems(); 
    
    cout << "Where do you want to move" << endl;
    cout << "Type in MOVE ___ (North, South, East, or West)" << endl;
    cin >> move;
    
    //resetting the room your in
    Room* nextRoom = currentRoom->getExit(move);
    currentRoom = nextRoom;
    cout << currentRoom->getRoomDescription() << endl;
    currentRoom->ExitsAndItems(); 
}

//picking up items from rooms and adding to inventory vector
void get(Room* &currentRoom, vector<Item> &inventory) {
    char item[100];
    cout << "Items in the room: " << endl;
    currentRoom->printItems();
    cout << "What do you want to steal?" << endl;
  
    cin >> item;
    
    //picks the item up
    Item RoomItem = currentRoom->getItem(item);
    inventory.push_back(RoomItem);
    currentRoom->removeItem(item);
    cout << item << " has been added to your inventory" << endl;
}

// drop items 
//although idk when youd ever want to do this in my game...
void drop(Room* &currentRoom, vector<Item> &inventory) {
    vector<Item>::iterator ptr4;
    char dropitem[100];
    cout << "Here are the items in your inventory: " << endl;
    printInventory(inventory);
    cout << "Which item do you want to drop?" << endl;
    cin >> dropitem;
    
    //Levi helped me with this
    for(ptr4 = inventory.begin(); ptr4 != inventory.end(); ptr4++){
       if(strcmp(ptr4->getDescription(), dropitem) == 0){
           char tempDescrip[100] = " ";
           
           Item tempItem (tempDescrip);
           tempItem = (*ptr4);
          inventory.erase(ptr4);
          currentRoom->setItem(tempItem);
          cout << dropitem << " has been removed from your inventory" << endl;
          break;
       }
        }
}

// prints out whole inventory
void printInventory(vector<Item> &inventory) {
    vector<Item>::iterator it;
    for(it = inventory.begin(); it != inventory.end(); it++){
        cout << it->getDescription() << ",";;
}
}

//Checks to see if you've collected all the items and you're in the dormitory (WinID is 8, not 0)
bool checkWin(Room* &currentRoom, vector<Item> &inventory, Room* Station){
    if (currentRoom == Station){
        if(inventory.size()==5) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

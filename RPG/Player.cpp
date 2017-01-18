/*********************************************************************
 ** Program Filename: Player.cpp
 ** Author: John Carrabino
 ** Date: 8/7/2016
 ** Description:This is the player class implementation file
 ** Input: n/a
 ** Output: This program outputs phrases relating to the players current
 * location as well as the player menus and any dialogue sequence 
 * that occurs when a derived space class special function is 
 * activated.
 *********************************************************************/
#include "Player.hpp"
#include "Space.hpp"
#include "Room.hpp"
#include "Chamber.hpp"
#include "Secret.hpp"

/* Constructor */
Player::Player() {
    realmCount = nextSlot = findCount = 0;
    for (int i = 0; i < 4; i++) {
        inventory[i] = EMPTY;
    }
    available[0] = GEM;
    available[1] = AMULET;
    available[2] = ORB;
    available[3] = TOME;
}

/* Destructor */
Player::~Player() {
    delete map;
}

/*********************************************************************
 ** Function: moveForward()
 ** Description: This function adds a 'Space' to the end of the linked
 * map structure for the player to explore.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: A new node is created and added to the front
 * of the structure.
 *********************************************************************/
int Player::moveForward() {
    if (realmCount == 1) {
        int test;
        test = map->mForward();
        return test;
    } else {
        findCount = 0;
        map->forward();
        return 1;
    }
}

/*********************************************************************
 ** Function: moveBackward()
 ** Description: This function puts the player in the previous 'Space'
 * they were in. It then deletes the space in front of it.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The old node at the back of the structure is 
 * properly removed.
 *********************************************************************/
int Player::moveBackward() {
    if (realmCount == 1) {
        map->mBack();
        return 1;
    } else {
        int test;
        findCount = 0;
        test = map->backward();
        return test;
    }
}

/*********************************************************************
 ** Function: moveLeft()
 ** Description: This function adds a 'Space' to the left of the linked
 * map structure for the player to explore.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: A new node is created and added to the front
 * of the structure.
 *********************************************************************/
void Player::moveLeft() {
    if (realmCount == 1) {
        map->mLeft();
    } else {
        findCount = 0;
        map->left();
    }
}

/*********************************************************************
 ** Function: moveRight()
 ** Description: This function adds a 'Space' to the right of the linked
 * map structure for the player to explore.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: A new node is created and added to the front
 * of the structure.
 *********************************************************************/
void Player::moveRight() {
    if (realmCount == 1) {
        map->mRight();
    } else {
        findCount = 0;
        map->right();
    }
}

/*********************************************************************
 ** Function: taskMenu()
 ** Description: This function displays all 5 tasks available to
 * the player for each of their turns.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate int is returned to the playerTurn()
 * function.
 *********************************************************************/
int Player::taskMenu() {
    cout << "What would you like to do?" << endl;
    cout << "1 - Explore" << endl;
    cout << "2 - Search for Items" << endl;
    cout << "3 - View Inventory" << endl;
    cout << "4 - View Goal" << endl;
    cout << "5 - Quit" << endl;
    cout << "Choice: ";
    int choice = 0, count = 0;
    cin >> choice;
    cin.sync();
    while (!cin || choice < 1 || choice > 5) {
        cin.sync();
        if (count == 0)
            cout << "Please enter a number from 1 to 5: " << endl;
        count++;
        cin.clear();
        cin.ignore(80, '\n');
        cin >> choice;
    }
    return choice;
}

/*********************************************************************
 ** Function: moveMenu()
 ** Description: This function displays all 4 movement options
 * available to the player for each of their turns.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate int is returned to the playerTurn()
 * function.
 *********************************************************************/
int Player::moveMenu() {
    cout << endl << endl;
    cout << "Where would you like to go?" << endl;
    cout << "1 - Move Forwards" << endl;
    cout << "2 - Move Backwards" << endl;
    cout << "3 - Move to the Left" << endl;
    cout << "4 - Move to the Right" << endl;
    cout << "Choice: ";
    int choice = 0, count = 0;
    cin >> choice;
    cin.sync();
    while (!cin || choice < 1 || choice > 4) {
        cin.sync();
        if (count == 0)
            cout << "Please enter a number from 1 to 4: " << endl;
        count++;
        cin.clear();
        cin.ignore(80, '\n');
        cin >> choice;
    }
    cout << endl;
    return choice;
}

/*********************************************************************
 ** Function: stepsTaken()
 ** Description: This function returns the players total steps as an 
 * int value.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate int is returned 
 *********************************************************************/
int Player::stepsTaken() {
    int x = map->getSteps();
    return x - 1;
}

/*********************************************************************
 ** Function: playerTurn()
 ** Description: This function calls the taskMenu() function and
 * performs the appropriate action based on the players decision.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate action is performed based on
 * the players choice.
 *********************************************************************/
int Player::playerTurn() {
    std::cout << std::endl;
    int choice = taskMenu();
    int move = 0;
    if (choice == 1) {
        move = moveMenu();
        if (move == 1) {
            choice = this->moveForward();
            return choice;
        }
        if (move == 2) {
            choice = this->moveBackward();
            return choice;
        }
        if (move == 3) {
            this->moveLeft();
            return choice;
        }
        if (move == 4) {
            this->moveRight();
            return choice;
        }
    }
    if (choice == 2) {
        if (realmCount == 2) {
            foundItem();
            return choice;
        } else {
            return -1;
        }
    }
    if (choice == 3) {
        viewInventory();
    }
    if (choice == 4) {
        cout << endl << endl;
        cout << "GOAL: \n"
                "You have woken up in a mysterious town with no recollection \n"
                "of how you got there. Based on a few vague words from a \n"
                "strange old man you are set on a quest to find 4 ancient \n"
                "relics and return them to the Alter of Shadows before \n"
                "you lose your sanity and get trapped in this alternate \n"
                "reality for all of eternity..." << endl;
    }
    if (choice == 5)
        return choice;

    return choice;
}

/*********************************************************************
 ** Function: viewInventory()
 ** Description: This function displays all 4 items in the players
 * current inventory by iterating through the itemName function.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The function prints the name of the item if it
 * exists if not it will print "EMPTY SLOT"
 *********************************************************************/
void Player::viewInventory() {
    cout << endl << endl;
    cout << "Your inventory contains the following Items:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << " - ";
        itemName(i);
    }
    return;
}

/*********************************************************************
 ** Function: itemName()
 ** Description: This function takes an int from an iterator and 
 * returns a string with the name of each item in the players
 * current inventory.
 ** Parameters: it takes an int form an iterator.
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate string is returned to the 
 * viewInventory() function.
 *********************************************************************/
void Player::itemName(int itm) {
    if (inventory[itm] == EMPTY) {
        cout << "Empty Slot" << endl;
    }
    if (inventory[itm] == GEM) {
        cout << "Radiant Gem" << endl;
    }
    if (inventory[itm] == AMULET) {
        cout << "Nazar Amulet" << endl;
    }
    if (inventory[itm] == ORB) {
        cout << "Dark Energy Orb" << endl;
    }
    if (inventory[itm] == TOME) {
        cout << "Tome of Shadows" << endl;
    }
}

// test driver function for forward, right, and left step counts
//void Player::getCounts(){
//    map->getCount();
//    return;
//}

/*********************************************************************
 ** Function: statLevel()
 ** Description: This function initializes a the next level in the game.
 * carrying over any step counts or resetting them when necessary.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate level is initialized after each
 * call by incrementing the realmCount variable.
 *********************************************************************/
void Player::startLevel() {
    int x;
    Space *temp;
    if (realmCount == 0) {
        map = new Room;
        realmCount++;
        return;
    }
    if (realmCount == 1) {
        temp = map;
        map = new Chamber(0);
        delete temp;
        realmCount++;

        return;
    }
    if (realmCount == 2) {
        temp = map;
        x = map->getSteps();
        x = x - 1;
        map = new Secret(x);
        delete temp;
        realmCount++;
        return;
    }
}

/*********************************************************************
 ** Function: isSpecial()
 ** Description: This function calls on the special function of the
 * player's current map object and returns the int flag from that 
 * function.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: It returns the appropriate int flag from the map
 *********************************************************************/
int Player::isSpecial() {
    int x = map->special();
    return x;
}

/*********************************************************************
 ** Function: itemSearch()
 ** Description: This function displays uses a random number generator
 * in order to determine which item type will be created in each new
 * space the player enters.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate int is returned to the foundItem()
 * function.
 *********************************************************************/
int Player::itemSearch() {
    int x = rand() % 100 + 1;
    if (realmCount == 2 && findCount != 4) {
        if (1 <= x && x < 20)
            return 0;
        if (20 <= x && x < 40)
            return 1;
        if (40 <= x && x < 60)
            return 2;
        if (60 <= x && x < 80)
            return 3;
        if (80 <= x && x <= 100)
            return 4;
    }

    return 0;
}

/*********************************************************************
 ** Function: foundItem()
 ** Description: This function take the int returned from the itemSearch
 * function and uses that number to determine if an item was found.
 * if an item is found then the appropriate item message is returned to
 * main. If an item is found that item is added to the next available 
 * player inventory spot.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: The appropriate string is returned if an item
 * is found and the item is added to the players inventory.
 *********************************************************************/
void Player::foundItem() {
    int x = itemSearch();
    if (x == 0) {
        cout << endl << "There doesn't seem to be anyone or \n"
                "anything for miles...";
        this->findCount++;
        return;
    }
    if (x == 1) {

        if (available[0] == GEM) {
            if (this->findCount == 0) {
                cout << endl <<
                        "You notice a twinkle out of the corner of your eye. \n"
                        "You move aside some twigs to find a Radiant Gem! \n"
                        "The Radiant Gem has been added to your inventory...";
                this->findCount++;
                available[0] = EMPTY;
                inventory[nextSlot] = GEM;
                nextSlot++;
                return;
            } else {
                cout << endl << "There doesn't seem to be anyone or \n"
                        "anything for miles...";
                this->findCount++;
                return;
            }
        } else {
            cout << endl << "There doesn't seem to be anything \n"
                    "useful here...";
            this->findCount++;
            return;
        }
    }
    if (x == 2) {

        if (available[1] == AMULET) {
            if (this->findCount == 0) {
                cout << endl <<
                        "You stumble over a root on the ground and fall over. \n"
                        "As you regain your bearing you notice a metal chain \n"
                        "poking out from under a rock. You pick up the rock \n"
                        "to discover the Nazar Amulet! The Nazar Amulet has \n"
                        "been added to your inventory...";
                this->findCount++;
                available[1] = EMPTY;
                inventory[nextSlot] = AMULET;
                nextSlot++;
                return;
            } else {
                cout << endl << "There doesn't seem to be anyone or \n"
                        "anything for miles...";
                this->findCount++;
                return;
            }
        } else {
            cout << endl << "There doesn't seem to be anything \n"
                    "useful here...";
            this->findCount++;
            return;
        }
    }
    if (x == 3) {

        if (available[2] == ORB) {
            if (this->findCount == 0) {
                cout << endl <<
                        "You feel the hairs on the back of your neck stand on \n"
                        "end. This feeling intensifies as you approach the \n"
                        "withered bush to your left. You reach inside the \n"
                        "bush and pull out a mysterious orb emanating a dark \n"
                        "aura of sorts. The Dark Energy Orb has been added to \n"
                        "your inventory!";
                this->findCount++;
                available[2] = EMPTY;
                inventory[nextSlot] = ORB;
                nextSlot++;
                return;
            } else {
                cout << endl << "There doesn't seem to be anyone or \n"
                        "anything for miles...";
                this->findCount++;
                return;
            }
        } else {
            cout << endl << "There doesn't seem to be anything \n"
                    "useful here...";
            this->findCount++;
            return;
        }
    }
    if (x == 4) {

        if (available[3] == TOME) {
            if (this->findCount == 0) {
                cout << endl <<
                        "You feel drawn to a small abandoned hut off the trail.\n"
                        "As you enter the hut there is nothing inside but a book \n"
                        "lying in the middle of the otherwise barren floor. The \n"
                        "book is titled The Tome of Shadows. As you return to \n"
                        "the trail you look back to check if there is anything \n"
                        "else of use in the hut, but it seems to have vanished...";
                this->findCount++;
                available[3] = EMPTY;
                inventory[nextSlot] = TOME;
                nextSlot++;
                return;
            } else {
                cout << endl << "There doesn't seem to be anyone or \n"
                        "anything for miles...";
                this->findCount++;
                return;
            }
        } else {
            cout << endl << "There doesn't seem to be anything \n"
                    "useful here...";
            this->findCount++;
            return;
        }
    }
}

/*********************************************************************
 ** Function: iFoundAll()
 ** Description: This function loops through the players inventory
 * and will notify the map object if all 4 items are found by setting
 * its foundAll bool variable to true, this causes the final level 
 * to become available.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: If all items are found the maps foundAll variable
 * is set to true.
 *********************************************************************/
void Player::iFoundAll() {
    int gFound, oFound, aFound, tFound;
    gFound = oFound = aFound = tFound = 0;
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == GEM) {
            gFound++;
        }
        if (inventory[i] == ORB) {
            oFound++;
        }
        if (inventory[i] == AMULET) {
            aFound++;
        }
        if (inventory[i] == TOME) {
            tFound++;
        }
    }

    if (gFound == true) {
        if (aFound == true)
            if (oFound == true)
                if (gFound == true)
                    if (tFound == true) {
                        map->complete(true);
                        return;
                    }
    } else
        return;
}

/*********************************************************************
 ** Function: didLose()
 ** Description: This function returns true if the player takes over 
 * 20 steps in the woods level.
 ** Parameters: n/a
 ** Pre-Conditions: An object must already exist.
 ** Post-Conditions: returns true if map stepCount is over 20, otherwise
 * it returns false.
 *********************************************************************/
bool Player::didLose() {
    if (map->getSteps() > 15) {
        return true;
    } else
        return false;
}
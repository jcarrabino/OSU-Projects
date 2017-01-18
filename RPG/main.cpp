/*********************************************************************
** Program Filename: main.cpp
** Author: John Carrabino
** Date: 8/7/2016
** Description: This assignment require us to use the concepts of 
 * class inheritance, polymorphism, and pointers in order to create a 
 * text based game. When the program starts the user is prompted to 
 * start a new game, exit the game, or read a description about the
 * game. The game starts off with a dialogue sequence then the player
 * gets to explore a mysterious town. After finding a mysterious figure
 * the Room.cpp special function triggers a dialogue sequence, after
 * which the player is transported to the next level. The player then 
 * has to explore the woods and search for items. If they do not find
 * the necessary 4 items before taking 20 steps they lose the game.
 * If they find all 4 items in time then they get to go to the final 
 * level where they are tasked with putting the items on an alter.
 * after finding the alter the player wins the game. 
** Input: The user is initially prompted to input an integer from the
 * menu to choose to start a game, exit the game, or learn about the
 * game. For each turn the player is given 5 options to choose from 
 * and is prompted to enter the corresponding integer.
** Output: This program outputs phrases relating to the players current
 * location as well as several dialogue sequences during transitional
 * states.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Space.hpp"
#include "Room.hpp"
#include "Chamber.hpp"
#include "Secret.hpp"
#include "Player.hpp"

using std::cout;
using std::cin;
using std::endl;


/* function prototypes */
int gameMenu();
void beginningDialogue(int);
void winDialogue(int);
void loseDialogue(int);
void townDialogue(int);
void woodsDialogue(int);
void shadowDialogue(int);
void transition1(int);
void transition2(int);

int main(int argc, char** argv) {
    srand(time(NULL));
    /*Initializes player object which is defined
     * at the beginning of each new game. */
    Player *test; 
    /*keeps track of various counts in the game */
    int game, choice, i, prevStep;
    i = 0;

    /* do-while loop that contains all of the main menu options and 
     in-game operations */
    do {
        game = gameMenu(); /* prompts user to start or exit a new game */
        switch (game) {
            case 1:
                /* Initializes new player/gameworld */
                test = new Player;
                test->startLevel();
                for (int x = 0; x < 4; x++) {
                    cout << endl;
                    beginningDialogue(x);
                    cin.clear();
                    cin.sync();
                    cout << endl << endl << "Press ENTER to continue ";
                    cout << endl;
                    cin.get();
                    if (x == 0) {
                        cin.ignore(100, '\n');
                    }
                }
                do { /* do-while loop for level one */
                    choice = test->playerTurn();
                    if (choice == 5) {
                        break;
                    }
                    if (choice == 1) {
                        cout << endl << endl;
                        if (prevStep != test->stepsTaken()) {
                            townDialogue(i);
                            i++;
                            if (i >= 8)
                                i = 0;
                        }
                        if (test->isSpecial() == 1) {
                            cout << endl << endl <<
                                    "You hear someone nearby...";
                        }
                        if (test->isSpecial() == 2) {
                            cout << endl << endl <<
                                    "You are approached by the mysterious \n"
                                    "old figure...";
                        }
                    }
                    if (choice == 0) {
                        cout << "This appears to be a dead end...";

                    }
                    if (choice == -1) {
                        cout << endl;
                        cout << "This seems to be a town of some sort \n"
                                "I can't just go around stealing things!";
                    }
                    cout << endl << endl << "Step Count: " <<
                            test->stepsTaken() << endl;
                    prevStep = test->stepsTaken();
                    cin.clear();
                    cin.sync();
                    cout << endl << "Press ENTER to continue ";
                    cin.ignore(100, '\n');
                    cin.get();
                } while (test->isSpecial() != 2 && choice != 5);

                if (choice != 5) {
                    for (int x = 0; x < 9; x++) {
                        cout << endl;
                        cout << "OLD MAN: " << endl;
                        transition1(x);
                        cin.clear();
                        cin.sync();
                        cout << endl << endl << "Press ENTER to continue ";
                        cout << endl;
                        cin.sync();
                        cin.get();
                    }
                    /* Initializes next level */
                    test->startLevel();
                    test->moveForward();
                    i = 0;
                    /* do-while loop for level two */
                    do {
                        choice = test->playerTurn();
                        if (choice == 5) {
                            break;
                        }
                        if (choice == 1) {
                            cout << endl << endl;
                            if (prevStep != test->stepsTaken()) {
                                woodsDialogue(i);
                                i++;
                                if (i >= 8)
                                    i = 0;
                            }
                        }
                        test->iFoundAll();
                        if (test->isSpecial() == 2) {
                            cout << endl << endl <<
                                    "After placing the fourth and final"
                                    " item in your inventory \n"
                                    "time itself appeared to stop. Your"
                                    " inventory bag begins \n"
                                    "emitting a strange glow. Before you"
                                    " have time to react \n"
                                    "the ground beneath your feet disappears"
                                    " and you fall \n"
                                    "into a deep black void...";
                        }
                        if (choice == 0) {
                            cout << "There's no heading back from here...";

                        }
                        cout << endl << endl << "Step Count: "
                                << test->stepsTaken() << endl;
                        prevStep = test->stepsTaken();
                        cin.clear();
                        cin.sync();
                        cout << endl << "Press ENTER to continue ";
                        cin.ignore(100, '\n');
                        cin.get();
                    } while (test->isSpecial() != 2 && choice != 5
                            && !(test->didLose()));
                }

                if (choice != 5 && !(test->didLose())) {
                    for (int x = 0; x < 3; x++) {
                        cout << endl;
                        transition2(x);
                        cin.clear();
                        cin.sync();
                        cout << endl << endl << "Press ENTER to continue ";
                        cout << endl;
                        cin.sync();
                        cin.get();
                    }
                    /* Initializes next level */
                    test->startLevel();
                    test->moveForward();
                    
                    /* do-while loop for level three*/
                    do {
                        choice = test->playerTurn();
                        if (choice == 5) {
                            break;
                        }
                        if (choice == 1) {
                            cout << endl << endl;
                            if (prevStep != test->stepsTaken()) {
                                shadowDialogue(i);
                                i++;
                                if (i >= 8)
                                    i = 0;
                            }
                            if (test->isSpecial() == 1) {
                                cout << endl << endl <<
                                        "There's a mysterious green glow "
                                        "emanating from \n"
                                        "some unknown source directly ahead "
                                        "of you...";
                            }
                            if (test->isSpecial() == 2) {
                                cout << endl << endl <<
                                        "You approach an alter surrounded "
                                        "with a green \n"
                                        "flame-like aura. The items in your"
                                        " inventory \n"
                                        "become imbued with a similar aura...";
                            }
                        }
                        if (choice == 0) {
                            cout << "There's no heading back from here...";

                        }
                        if (choice == -1) {
                            cout << endl;
                            cout << "It is far too dark to search for any \n"
                                    "items here. Wherever here may be...";
                        }
                        cout << endl << endl << "Step Count: " <<
                                test->stepsTaken() << endl;
                        prevStep = test->stepsTaken();
                        cin.clear();
                        cin.sync();
                        cout << endl << "Press ENTER to continue ";
                        cin.ignore(100, '\n');
                        cin.get();
                    } while (test->isSpecial() != 2 && choice != 5);
                }
                
                /* Win and lose conditions for game end */
                if (choice != 5) {
                    cout << endl << endl;
                    if (!(test->didLose())) {
                        for (int x = 0; x < 9; x++) {
                            cout << endl;
                            winDialogue(x);
                            cin.clear();
                            cin.sync();
                            cout << endl << endl <<
                                    "Press ENTER to continue ";
                            cout << endl;
                            cin.sync();
                            cin.get();
                        }
                        cout << endl << "GAME OVER" << endl << endl;
                        cin.clear();
                        cin.sync();
                        cout << "Press ENTER to return to the Menu ";
                        cout << endl;
                        cin.get();
                        cout << endl;
                    } else {
                        for (int x = 0; x < 8; x++) {
                            cout << endl;
                            loseDialogue(x);
                            cin.clear();
                            cin.sync();
                            cout << endl << endl <<
                                    "Press ENTER to continue ";
                            cout << endl;
                            cin.sync();
                            cin.get();
                        }
                        cout << endl << "GAME OVER" << endl << endl;
                        cin.clear();
                        cin.sync();
                        cout << "Press ENTER to return to the Menu ";
                        cout << endl;
                        cin.get();
                        cout << endl;
                    } 
                }
                
                /* Screen after quitting a game */
                if (choice == 5) {
                    cout << endl << "GAME OVER" << endl << endl;
                    cin.clear();
                    cin.sync();
                    cout << "Press ENTER to return to the Menu ";
                    cin.ignore(100, '\n');
                    cin.get();
                    cout << endl << endl;
                }
                /* deallocates memory for Player object */
                delete test;
                break;
            case 2: /* Description of the game */
                cout << "The Calling is a text-based adventure game \n"
                        "that takes you on a mysterious journey in \n"
                        "order to free yourself from your unearthly \n"
                        "tormentors and return to your beloved home."
                        << endl << endl;
                cin.clear();
                cin.sync();
                cout << endl << "Press ENTER to continue ";
                cin.ignore(100, '\n');
                cin.get();
                cout << endl;
                break;
            case 3:
                /* Exits the game loop */
                cout << endl;
                break;
            default:
                /* Default case, just in case ;) */
                cout << "It appears something went wrong..." << endl;
                break;
        }
    } while (game != 3);
    
    return 0;
}

/*********************************************************************
** Function: gameMenu()
** Description: Displays a list of game options to choose from
 * for the user.
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns appropriate int to main
*********************************************************************/
int gameMenu() {
    cout << "Welcome to The Calling" << endl << endl;

    cout << "Please select one of the following options" << endl;
    cout << "1 - Start Game" << endl;
    cout << "2 - About Game" << endl;
    cout << "3 - Exit Game" << endl;
    cout << "Choice: ";
    int choice = 0, count = 0;
    cin >> choice;
    cin.sync();
    while (!cin || choice < 1 || choice > 3) {
        cin.sync();
        if (count == 0)
            cout << "Please enter a number from 1 to 3: " << endl;
        count++;
        cin.clear();
        cin.ignore(80, '\n');
        cin >> choice;
    }
    cout << endl;
    return choice;
}

/*********************************************************************
** Function: beginningDialogue()
** Description: Contains all of the dialogue displayed at the start
 * of a new game.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void beginningDialogue(int i) {
    std::string s1, s2, s3, s4;
    s1 = "You wake up in the middle of a town you’ve \n"
            "never been before…";
    s2 = "You have no recollection of how you got there, \n"
            "but you are just happy to be awake. For the \n"
            "past month your dreams have been filled with \n"
            "images of unimaginable atrocities and horrors \n"
            "that words could not possibly describe…";
    s3 = "Your latest dream was slightly more vivid than \n"
            "usual and you try to recall some more details, \n"
            "but all you can remember are vague memories of \n"
            "shrouded figures praising some ancient forgotten \n"
            "deity who has been caste beneath the veil of our \n"
            "reality, lurking in the shadows for countless \n"
            "millennia…";
    s4 = "Maybe you should explore a bit to find out where \n"
            "you are…";
    std::string stringArray[] = {s1, s2, s3, s4};
    cout << stringArray[i] << endl;
    return;

}

/*********************************************************************
** Function: winDialogue()
** Description: Contains all of the dialogue displayed when the
 * player wins the game.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void winDialogue(int i) {
    std::string s1, s2, s3, s4, s5, s6, s7, s8, s9;
    s1 = "Once you reach the Alter of Existence all \n"
            "of the items in your inventory fly out of \n"
            "your bag and situate themselves on top of. \n"
            "the alter. The green aura intensifies until.. \n"
            "                  BOOM!!!                   \n"
            "A giant pillar of green flame is emitted \n"
            "from the alter and shoots up as far as \n"
            "your eyes can see!!!";
    s2 = "After spending a couple minutes in awe \n"
            "at the magnifisence of the alter you \n"
            "realize that the once opaque darkness \n"
            "around you has vanished, although you \n"
            "wish it hadn't...";
    s3 = "You see a strange figue approaching you \n"
            "from out of the shadows...";
    s4 = "What's this?! Its the old man from before?!";
    s5 = "OLD MAN: \n"
            "I didn't think you'd actually have it in \n"
            "you! To think after all these year the \n"
            "the Ancient One will be free at last and \n"
            "it is all thanks to your valiant efforts!";
    s6 = "OLD MAN: \n"
            "Oh, do not worry, you will be rewarded \n"
            "for your efforts here today.";
    s7 = "OLD MAN: \n"
            "I don't know if you've noticed, but here \n"
            "in the Vale of Shadows time is at a stand \n"
            "still. It is here where you will spend \n"
            "all of eternity to reflect on what you've \n"
            "done...";
    s8 = "OLD MAN: \n"
            "Do you see that pillar there? That is the \n"
            "Ancient One's energy leaking over into our \n"
            "physical realm. I hope you will rest easy \n"
            "knowing that once this pillar is extinguished \n"
            "it means that the Ancient One has been fully \n"
            "resurrected in your world, and you will be \n"
            "trapped here in pure darkness for all of \n"
            "eternity! Farewell now, Hehehehehe!!!";
    s9 = "The old man vanishes before your eyes. \n"
            "You are at a loss for words...";
    std::string stringArray[] = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
    cout << stringArray[i];
    return;
}

/*********************************************************************
** Function: loseDialogue()
** Description: Contains all of the dialogue displayed when the 
 * player loses a game.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void loseDialogue(int i) {
    std::string s1, s2, s3, s4, s5, s6, s7, s8;
    s1 = "You are unable to move any further, as it being \n"
            "held hostage by some unseen force...";
    s2 = "Everything slowly fades to black until you fall \n"
            "unconscious. The last thing you remember is gazing \n"
            "up at the ominous looking branches and being relieved \n"
            "that this might be an end to your now living hell...";
    s3 = "You are unsure of how much time has passed, but you \n"
            "finally wake up...";
    s4 = "However, this time you wake up in your own bed...";
    s5 = "Was everything you experienced just another nightmare? \n"
            "How is that possible, everything seemed so real...";
    s6 = "You lay awake in bed for several hours contemplating \n"
            "the events that just unfolded and debating what actually \n"
            "happened...";
    s7 = "As you finally come to your senses you wonder what would \n"
            "have transpired had you completed the quest given to you \n"
            "by that mysterious old man, and realize that he may not \n"
            "have been trying to help you after all...";
    s8 = "Your nightmares continue to get worse... You are \n"
            "eventually driven to madness, spending the rest of \n"
            "miserable days searching for answers to questions that \n"
            "cannot be answered...";
    std::string stringArray[] = {s1, s2, s3, s4, s5, s6, s7, s8};
    cout << stringArray[i];
    return;
}

/*********************************************************************
** Function: townDialogue()
** Description: Contains all of the dialogue displayed as the
 * player explores the town level.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void townDialogue(int i) {

    std::string s1, s2, s3, s4, s5, s6, s7, s8;
    s1 = "...Wh-what? Where am I?";
    s2 = "Hello? Is there anybody out there?! \n"
            "Hmm... The last thing I remember was \n"
            "falling asleep in my bed. How did \n"
            "I wind up here?";
    s3 = "Alright, don't panic, just think...\n"
            "I mean this architecture seems rather \n"
            "archaic, yet vaguely familiar... \n"
            "Almost as if I saw it in a dream...";
    s4 = "I think I heard someone call out my \n"
            "name. No, it was probably just my \n"
            "imagination...";
    s5 = "Something seems off about this place. \n"
            "The air is very stale, and where are \n"
            "all the people?!";
    s6 = "My word, I must have had a bit too \n"
            "much to drink last night... Although, \n"
            "now that I think of it, I cannot \n"
            "recall drinking at all...";
    s7 = "I hope I find someone soon, this place \n"
            "is starting to give me the creeps...";
    s8 = "Wait until my friends hear about this...";
    std::string stringArray[] = {s1, s2, s3, s4, s5, s6, s7, s8};
    cout << stringArray[i];
    return;

}

/*********************************************************************
** Function: woodsDialogue()
** Description: Contains all of the dialogue displayed as the
 * player explores the woods level.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void woodsDialogue(int i) {
    std::string s1, s2, s3, s4, s5, s6, s7, s8;
    s1 = "What kind of forest is this? The \n"
            "trees are so gnarled and grotesque!";
    s2 = "What on earth have I gotten myself into!";
    s3 = "So according to that old man there are \n"
            "some useful items in these woods. I \n"
            "wonder why he never ventured here to \n"
            "find them himself...";
    s4 = "The fog here is so thick, I can hardly \n"
            "see anything! Oh, what I would do for a \n"
            "cold pint right now...";
    s5 = "W-What was that?! Oh, I think my mind \n"
            "may be starting to play tricks on me...\n"
            "Hopefully this whole ordeal is someone's \n"
            "cruel joke, but I am starting to have \n"
            "my doubts...";
    s6 = "The air here is so thick I can hardly breathe!";
    s7 = "Its funny, I've been wandering for what \n"
            "seems like ages and I haven't become \n"
            "tired or thirsty at all. How strange...";
    s8 = "AAAAAAARRRGGGGHH!!! Where are these stupid \n"
            "relics!!! I just want to get out of here! \n"
            "That old man better not be trying to play \n"
            "me for a fool!";
    std::string stringArray[] = {s1, s2, s3, s4, s5, s6, s7, s8};
    cout << stringArray[i];
    return;

}

/*********************************************************************
** Function: shadowDialogue()
** Description: Contains all of the dialogue displayed as the
 * player explores the shadow level.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void shadowDialogue(int i) {
    std::string s1, s2, s3, s4, s5, s6, s7, s8;
    s1 = "Alright, something is definitely not \n"
            "right... Have I died, is this dreaded \n"
            "place my own personal hell?! It is just \n"
            "so dark here, wherever here is....";
    s2 = "Alright, just find the alter, nothing \n"
            "else matters! The old man said that if I \n"
            "placed the relics on the alter then I \n"
            "would be free of this wretched place!";
    s3 = "I've been wandering in this darkness \n"
            "for so long... I am starting to lose \n"
            "my senses as well as my mind...";
    s4 = "Wait, that almost sounded like laughter \n"
            "off in the distance... No, no, it can't \n"
            "be. No one could experience joy in such \n"
            "a place...";
    s5 = "Dear God, it's me, I am not sure if this \n"
            "was part of your grand plan for little \n"
            "old me, but please God, just make it stop!";
    s6 = "Where is that other-worldly laughter coming \n"
            "from?! Maybe its best not to find out...";
    s7 = "Where could this alter be?! I feel as though \n"
            "I have been down here for ages... The old man \n"
            "could really have given me better directions \n"
            "than just 'Find the Alter of Shadows,' pfft...";
    s8 = "I would wish this place on no man...";
    std::string stringArray[] = {s1, s2, s3, s4, s5, s6, s7, s8};
    cout << stringArray[i];
    return;
}

/*********************************************************************
** Function: transition1()
** Description: Contains all of the dialogue displayed as the
 * player transitions between the town level and the woods level.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void transition1(int i) {
    std::string s1, s2, s3, s4, s5, s6, s7, s8, s9;
    s1 = "Oh, its you! We have been trying to summon you \n"
            "here for quite some time now! I know you must \n"
            "have a lot of questions, but those are going to \n"
            "have to wait as we have more pressing matters to \n"
            "attend to...";
    s2 = "There are many things in this world that must remain \n"
            "hidden from public knowledge. Dark and mysterious \n"
            "secrets that could cause society as we know it to \n"
            "crumble. We are the guardians of those secrets, and \n"
            "you have been summoned by us to prevent the unspeakable \n"
            "horrors that are about to unfold… We believe that you've \n"
            "witnessed a few of these horrors in your dreams as of late...";
    s3 = "The Ancient One has been speaking to you, we’ve been sensing \n"
            "it for months now, that is why we summoned you here. We think \n"
            "he is trying to use your mind as a conduit to escape his \n"
            "eternal prison of shadows and return to the physical world. \n"
            "This simply cannot happen.";
    s4 = "The Ancient One was banished from our realm long before \n"
            "written records were kept. It has gone by many names over \n"
            "the centuries, but some of the most ancient records refer \n"
            "to it as Cthulu the undying. It is from the shadows he is \n"
            "able to contact us in our dreams and instill true fear in \n"
            "the hearts of men. ";
    s5 = "This is why we summoned you here, it appears the Ancient One has \n"
            "taken an interest in your mind. The only way to prevent his \n"
            "eventual return is to travel through the Abyssal Woods in \n"
            "search of four ancient artifacts. They are known as the \n"
            "Radiant Gem,the Nazar Amulet, the Dark Energy Orb, and \n"
            "the Tome of Shadows.";
    s6 = "By holding all four of these artifacts at once the user \n"
            "will be instantly transported to the Vale of Shadows, which \n"
            "is where the Alter of Existence is located.";
    s7 = "All you have to do is place all four of the artifacts on the \n"
            "alter before its too late.";
    s8 = "Oh, and one more thing! The Abyssal Woods and the Vale of \n"
            "Shadows are no places for men to wander. Many men have lost \n"
            "their minds while searching for these objects and have never \n"
            "been seen again. I would say that you can take no more than \n"
            "20 steps once there before you too will meet the same fate...";
    s9 = "You are now being transported to the entrance of the Abyssal \n"
            "Woods. Good luck on your journey lone wanderer you're going \n"
            "to need it... ";
    std::string sArray[] = {s1, s2, s3, s4, s5, s6, s7, s8, s9};
    cout << sArray[i];
    return;
}

/*********************************************************************
** Function: transition2()
** Description: Contains all of the dialogue displayed as the
 * player transitions between the woods level and the shadow level.
** Parameters: takes an int received from an iterator to output 
 * a different string for each call
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void transition2(int i) {
    std::string s1, s2, s3;
    s1 = "As you fall through the almost palpable darkness you lose \n"
            "all track of time. After several hours you begin doze off \n"
            "after acepting your fate of almost certain death...";
    s2 = "You wake up and no longer feel as though you are falling. \n"
            "In fact, you are unable to feel, hear, or see much of \n"
            "anything...";
    s3 = "You set out on your mission to find the Alter of Existence \n"
            "with the seemingly vain hopes of returning home...";
    std::string sArray[] = {s1, s2, s3};
    cout << sArray[i];
    return;
}




/*
    Space *room = new Room;
    int steps;
    
    do{
    room->forward();
    cout << room->getPhrase() << endl;
    cout << "Step Count: " << room->getSteps() << endl;
    room->getCount();
    cout << endl;
    room->forward(); 
    cout << room->getPhrase() << endl;
    cout << "Step Count: " << room->getSteps() << endl;
    room->getCount();
    cout << endl;
    room->left();
    cout << room->getPhrase() << endl;
    cout << "Step Count: " << room->getSteps() << endl;
    room->getCount();
    cout << endl;
    room->right();
    cout << room->getPhrase() << endl;
    cout << "Step Count: " << room->getSteps() << endl;
    room->getCount();
    cout << endl;
    room->special();
    cout << endl;
    }while(room->getSteps() < 3);
    
    steps = room->getSteps();
    Space *woods = new Chamber(steps);
    
    do{
    woods->forward();
    cout << woods->getPhrase() << endl;
    cout << "Step Count: " << woods->getSteps() << endl;
    woods->getCount();
    cout << endl;
    woods->forward(); 
    cout << woods->getPhrase() << endl;
    cout << "Step Count: " << woods->getSteps() << endl;
    woods->getCount();
    cout << endl;
    woods->right();
    cout << woods->getPhrase() << endl;
    cout << "Step Count: " << woods->getSteps() << endl;
    woods->getCount();
    cout << endl;
    woods->right();
    cout << woods->getPhrase() << endl;
    cout << "Step Count: " << woods->getSteps() << endl;
    woods->getCount();
    cout << endl;
    woods->special();
    cout << endl;
    }while(woods->getSteps() < 6);
    
    steps = woods->getSteps();
    Space *shadows = new Secret(steps);
    
    do{
    shadows->forward();
    cout << shadows->getPhrase() << endl;
    cout << "Step Count: " << shadows->getSteps() << endl;
    shadows->getCount();
    cout << endl;
    shadows->forward(); 
    cout << shadows->getPhrase() << endl;
    cout << "Step Count: " << shadows->getSteps() << endl;
    shadows->getCount();
    cout << endl;
    shadows->left();
    cout << shadows->getPhrase() << endl;
    cout << "Step Count: " << shadows->getSteps() << endl;
    shadows->getCount();
    cout << endl;
    shadows->right();
    cout << shadows->getPhrase() << endl;
    cout << "Step Count: " << shadows->getSteps() << endl;
    shadows->getCount();
    cout << endl;
    shadows->special();
    }while(shadows->getSteps() < 9);
    
    delete room;
    delete woods;
    delete shadows;
 */
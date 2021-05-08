/* Program to learn structures and create vending machines 
This will also be used to use the vending machines as well
Written by: Stas, Aug 21/22 2020 */ 

/* File name: Vending Machine, main.cpp
Author: Stanislav Svichkar
Personal Project
Description:
Last Changed Feb 17, 2021*/  // Finished remove machine, starting edit

#include <iostream>
#include <string>
#include "VendUser.hpp"

/*
// Structue for a vending machine 
struct myVend{
    std::string name = "blank";                                       // name of the location 
    int bot_coke = 0, bot_ale = 0, bot_sprite = 0;                    // bottles of drinks (coca cola, ginger ale, sprite)
    int re_coke = 0, re_ale = 0, re_sprite = 0;                       // restock value for drinks
    int choco_bar = 0, gummy_bag = 0, chips = 0, fruit_bag = 0;       // food items 
    int re_choc = 0, re_gumy = 0, re_chip = 0, re_fruit = 0;          // restock value for food 
    double usable_bal = 0, gain_val = 0, ini_val = 0;                 // usable balance, how much money earned, initial value
    double price = 2.25; 
    std::string tag;                                                  // classification tag
    int macNum = 0;                                                   // For use in array only
    int macMax = 0;
    myVend *f_ptr = NULL;
    myVend *b_ptr = NULL;
    int mactyp;
    std::string type;
    //myVend *link;
};
typedef myVend* VendPtr;
//making modification for remote push testing
void school_vend(VendPtr& tempPtr);                             // create a vending machine for use in a school
void office_vend(VendPtr& tempPtr);                             // create a vending machine for use in a work office
//void admin_control(struct myVend macArray, int admin_choice); // Entering Admin Control 
//void admin_control(struct myVend macArray[100]);
void admin_control(VendPtr& head);                              // Administrative Controls and logistic menu
void manageMac(VendPtr& head);                                  // Managing the vending machines including creation and removing
void addMac(VendPtr& head);                                     // Menu for adding a new machine
void editMac(VendPtr& head);                                    // Menu for editing machines 
void removeMac(VendPtr& head);                                  // Menu for removing one or more machines 
void newOffice(VendPtr& iter);                                  // Creates a new vending machine for the office
void newSchool(VendPtr& head);                                  // Creates a new vending machine for a school 
void processName(VendPtr& temp, int loc);                       // Menu used for adding a location name 
void user_control(VendPtr& head);                               // Entering User Input Mode
void initializescale();                                         // Limits the decimal values
// void initilizesystem();                                      // I think this has been long gone   // place holder for creating 
void screenclear();                                             // clear screen for easier UI
void simulatedelay();                                           // allow user to see response before clearing screen
//int  check_static(int test);                                  // forgotten debug function  // 
void naughtyUser();                                             // Prevents / ignores invalid inputs to ignore errors
bool myDebug(VendPtr& head,VendPtr& itr);                       // My debugging menu (to remove after done)
void uselessfun1();                                             // For CLI Menu organization , wide bar
void uselessfun1(int num);                                      // Adds new lines equal to num amount
void uselessfun2();                                             // For CLI menu organization, adds bars in front of menu
void uselessfun3(std::string sen);                              // Creates bars around a string 
void enterDebug(VendPtr& ptr);                                  // Enters manual control / debugging of machines 
void manualOveride(VendPtr& ptr,VendPtr& head);                 // Manually creates machines and stuff inside of debug purchases
//void testArray(VendPtr& head);                                // obsolete testing function  // 
int arrParse(VendPtr& head);                                    // parses through the array of machines (original function) [obsolete]
int arrParse(VendPtr& head, int leng, int maxarr);              // parses through the array of functions to some amount (for listing)
bool toDel();                                                   // Confirms if you want to delete the machine 
void delArr(VendPtr& here,VendPtr& iter);                       // [obsolete?] 
void delArr(VendPtr& head, int sel, int leng);                  // deletes the machine in the array based on the selected machine 
void query();                                                   // prompt to wait for user input 
void moveArr(VendPtr& head, int leng, int dirr);                // moves array to next set of machines for managing
void recount(VendPtr& head);                                    // recounts all machines to fix the count
void editMenu(VendPtr& head);                                   // Enters the menu to edit machines
bool editMac(VendPtr& head,VendPtr& here, int pic);             // edits the machines for how many of each item is stocked
void modDrink(VendPtr& here);                                   // modifies how many drinks are in the machine
void modSnack(VendPtr& here);                                   // mdoifies how many snacks are in the machine
void invalidInp();                                              // States an invalid input 
bool checkName(VendPtr& here,VendPtr& iter,int where);          // checks if the name has been used before
void refill(VendPtr& iter, int sel);                            // refill prompt for all or one machine 
void refillMac(VendPtr& head);                                  // refill menu
void doRefill(VendPtr& iter);                                   // performs the refilling

int main(int argc, char *argv[]){
    screenclear();
    //int macMax = 100;
    myVend macArray;
    //struct myVend macArray[macMax];  /// this caused problems, when using array which is like double pointer
    //struct myVend macArray;
    //VendPtr ptr = new myVend;
    //struct myVend macArray;
    VendPtr head = &macArray;
    bool exte = true;
    //int macsize;  
    //head = macArray;
    //VendPtr last;
    //last = head;
    //ptr = macArray;
    //int firstInput;
    //std::cout << "Weclome to the Vending Machine Control Hub\n";
    //TODO:: add in counter
    //std::cout << "What would you like to do?\n";
    //std::cout << "1. Manage Machines\n2.Exit" << std::endl;
    //std::cin >> firstInput;
    /////////////// testing some stuff/////////////////
    /*int tester;
    while(tester != 3){
        std::cout << "Do you want to go into one or two or exit?\n";
        std::cin >> tester;
        switch (tester){
        case 1:
            std::cout << "I mean fewer links of text is cheating\n";
            break;
        case 2: 
            std::cout << "But I guesss that's the name of the game\n";
            break;
        default:
            std::cout << "That didnt' work as intended\n";      
            break;
        }
        std::cin.clear();
        std::cin.ignore(128,'\n');
    }*
    while(exte==true){
        std::cout << "Checking something";
        simulatedelay();
        while(exte==true){
            //myDebug(head,last);
            exte = myDebug(head,head);
            if (exte == false)
                break;
            //VendPtr iter = head;
            //admin_control(last);
            admin_control(head);
            screenclear();
            std::cout << "You shouldn't be here\n";
            simulatedelay();
        }
        std::cout << "Where are you going";
        simulatedelay();  
    }
    std::cout << "You shouldn't have gotten here";
    //std::cout << ptr->macNum;
    //return 0;
}
//////////////////// Start of functions ////////////////////
bool myDebug(VendPtr& head, VendPtr& itr){
    int picker;
    int catme;
    do {
        catme = 0;
        screenclear();
        uselessfun1();
        uselessfun2();
        std::cout << "Welcome to the debug screen\n";
        uselessfun2();
        std::cout << "Which pointer do you want to access?\n"; 
        uselessfun1();
        std::cout << "1. Head \n2. Iter \n3. Manual Mode \n4. Review Mode \n5. Quit \n6. Exit Program" << std::endl;
        uselessfun1();
        std::cin >> picker;
        switch (picker){
        case 1:
            enterDebug(head);
            break;
        case 2:
            enterDebug(itr);
            break;
        case 3: 
            char choice;
            std::cout << "Doing this will wipe your array, are you sure? Y / N \n";
            while(!(catme == 'y') || !(catme == 'n')){
                std::cin >> catme;
                if(catme == 'y'){
                    while(catme != 2){
                        manualOveride(itr,head); 
                        std::cin >> catme;
                    }                    
                }
            }
            break;
        case 4:
            do{
                VendPtr here = head;
                while(catme != 5){
                    std::cout << "\n\n\n\n\n\n";
                    uselessfun1(); uselessfun2();
                    std::cout << "There are supposedly " << head->macMax << " machines in service\n";
                    uselessfun2();
                    std::cout << "We are on machine #" << here->macNum <<". It is called " << here->name;
                    uselessfun2();
                    std::cout << "\nTheir tag is " << here->tag << ". You added " << here->bot_coke << " pop cans, " << here->choco_bar << " chocolate, and  " << here->fruit_bag << " fruit bags.\n";
                    uselessfun2();
                    std::cout << "Do you want to go to the next or previous?\n";
                    uselessfun2();
                    std::cin >> catme;
                    if (catme == 1){
                        if(here->f_ptr != NULL)
                            here = here->f_ptr;
                        else {
                            uselessfun1();
                            uselessfun2();
                            std::cout << "\nThere's no more machines in this direction\n";
                        }
                    }
                    else if(catme ==2){
                        if(here->b_ptr != NULL)
                            here = here->b_ptr;
                        else
                            std::cout << "\nThere are no more machines in this direction\n";
                    }
                }
            }while(catme != 5);
        case 5:
            break;
        case 6:
            break;    
        default:
            std::cout << "That ain't it chief";
            naughtyUser();
            simulatedelay();
            break;
        }
    } while (!(picker == 5) && !(picker == 6));
    std::cout <<"I do get out\n";
    if (picker == 6)
        return false;
    else
        return true;
}
void manualOveride(VendPtr& ptr,VendPtr& head){
    int mypick;
    VendPtr temp = new myVend;
    //do {
    int value;
    std::string aname;
    std::cout << "What do you want to call it?\n";
    //std::cin >> aname;
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, aname);
    temp->name = aname;
    std::cout << "\nHow much pop do you want to add?\n";
    std::cin >> value;
    temp->bot_coke = value;
    std::cout << "\nHow much candy?\n";
    std::cin >> value;
    temp->choco_bar = value;
    std::cout << "\nHow much fruit?\n";
    std::cin >> value;
    temp->fruit_bag = value;
    screenclear();
    uselessfun1();
    std::cout << "The machine you have made is called: " << temp->name << ". You added " << temp->bot_coke << " pop cans, " << temp->choco_bar << " chocolate, and  " << temp->fruit_bag << " fruit bags.\n";
    //std::cout << head->f_ptr;
    if(head->macMax == 0){
        //head->name = temp->name;
        //head->bot_coke = temp->bot_coke;
        //head->choco_bar = temp->choco_bar;
        //head->fruit_bag = temp->fruit_bag;
        head = temp;
        head->macNum = 1;
        ptr = head;
    }
    else{
        ptr->f_ptr = temp;
        temp->b_ptr = ptr;
        temp->macNum = head->macMax+1;
        ptr = temp;
    }
    head->macMax++;
    //std::cout << head->macMax;

    //}while(mypick != 5);
}
void enterDebug(VendPtr& ptr){      // will not be made optimized because it's just meant for ease
    int picker;
    do {
        screenclear();
        uselessfun1();
        uselessfun2();
        std::cout << "What are we debugging?\n";
        uselessfun2();
        std::cout << "1. # of machines\n"; uselessfun2(); std::cout << "2. Balance\n"; uselessfun2(); std::cout << "3. Items\n"; uselessfun2(); std::cout << "4. Exit\n";
        uselessfun1();
        std::cin >> picker;
        switch (picker){
        case 1:
            std::cout << ptr->macMax;
            simulatedelay();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            std::cout << "That ain't it chief";
            break;
        }
    }while (picker != 4);

}
void admin_control(VendPtr& head){
    int admin_input = 0;; 
    int arrayLength = head->macMax;
    //static struct myVend macArray[100];
    //int num_of_mac = 0;
    screenclear();
    uselessfun1(); uselessfun2();
    std::cout << "Welcome to the Vending Machine Control Hub\n"; uselessfun2();
    std::cout << "There are " << arrayLength << " machines in service\n"; uselessfun2();
    //std::cout << "There are " << num_of_mac << " machines in service\n";
    do {
        //uselessfun1();
        arrayLength = head->macMax;
        std::cout << "What would you like to do?\n"; uselessfun1();
        std::cout << "1. Manage Machines\n2. # of Machines?\n3. Refill Machines\n5. Exit\n";
        query();
        std:: cin >> admin_input;
        switch(admin_input){
            case 1: // Management screen: Create, Remove, Edit
                manageMac(head);
                break;
            case 2: { // Repeats amount of machines PS. need curly braces because of weird goto protocol
                screenclear(); 
                std::string arlen = "There are " + std::to_string(arrayLength) + " machines in service.\n";
                uselessfun3(arlen);
                break;
            }  // I forget why I did it this way, trying new stuff out
            case 3:
                refillMac(head);
                break;
            case 5:
                std::cout << "Leaving the Control Hub\n";
                break;
            default:
                uselessfun1();
                std::cout << "That was not a valid input. Please try again.\n";
                naughtyUser();
                screenclear();
                break;

        }
        //head->macNum = arrayLength+1;
        //check_static(num_of_mac);
    } while (admin_input != 5);
    //admin_input = 0;

}
void manageMac(VendPtr& head){
    int decision = 0; 
    screenclear();
    do{
        uselessfun1();
        uselessfun2();
        std::cout << "Entering Vending Machine Management Systems\n";
        uselessfun2();
        std::cout << "What do you want to do:\n";
        uselessfun1();
        std::cout << "1. Create New Machine\n2. Edit Machines\n3. Remove Machines\n4. Cancel\n";
        query();
        std::cin >> decision;
        std::cout << "\n";
        switch (decision){
        case 1:
            addMac(head);
            break;
        case 2:
            editMenu(head);
            break;
        case 3:
            removeMac(head);
            break;
        case 4:
            break;
        default:
            screenclear();
            invalidInp();
            naughtyUser();
            break;
        }
        //std::cout <<"oh no\n";
    }while(decision != 4);
    screenclear();
    uselessfun1();
}
void addMac(VendPtr& head){
    screenclear();
    int test;
    bool exitcond = false;
    bool testy;
    VendPtr iter= head;

    do{
        //iter = head;
        while(iter->f_ptr != NULL)
            iter = iter->f_ptr;
        if (head->macMax == 1)
            head = iter;
        int pickLoc = 0;   
        char morecpic = 'k'; 
        uselessfun1();
        uselessfun2();
        std::cout << "Is this for a school or an office?\n";
        uselessfun1();
        std::cout << "1. Office\n2. School\n3. Cancel\n";
        uselessfun1();
        query();
        std::cin >> pickLoc;
        if (pickLoc == 1 || pickLoc == 2)
            head->macMax++;
        screenclear();
        switch (pickLoc){
        case 1:
            newOffice(iter);
            break;
        case 2: 
            newSchool(iter);
            break;
        case 3:
            exitcond = true;
            break;
        default:
            screenclear();
            invalidInp();
            naughtyUser();
            break;
        }
        testy = checkName(head,iter,0);
        if (pickLoc == 1 || pickLoc == 2){
            std::cout << "Do you want to add another machine? Y / N" << std::endl;
            while(true){
                std::cin >> morecpic;
                if(morecpic == 'n' || morecpic == 'N'){
                    exitcond = true;
                    break;
                }
                else if ( morecpic == 'y' || morecpic == 'Y')
                    break;
                else{
                    naughtyUser();
                    invalidInp();
                    std::cout << "Do you want to add another machine? Y / N" << std::endl;
                }
            }
        }
        /*std::cout <<"\nThere are" <<head->macMax;/*
        if(/*(head->name == "blank") && (head->macMax == 1)){
            head = iter;
            std::cout << "\n" <<head->macMax << " should be " << iter->macMax;
            std::cout << "\nLet's compare " << iter->macNum; 
        }*
        naughtyUser();
        screenclear();
        //testArray(head);
    } while ((exitcond == false));
}
void removeMac(VendPtr& head){
    uselessfun1();
    uselessfun2();
    bool del = false;
    int pic = 0, leng, maxarr, useArr;
    maxarr = head->macMax;
    std::cout << "Opening Machine Removal Features\n";
    VendPtr here = head;
    do {
        if(head->macMax < 10)
            leng = 3;
        else
            leng = 5;
        maxarr = head->macMax;
        useArr = arrParse(here,leng,maxarr);
        //std::cout << useArr;
        std::cin >> pic;
        switch (pic) {
        case 0:
            break;
        case 1:
            del = toDel();
            if (del == true)
                delArr(here,pic,leng);
            break;
        case 2:
            if (useArr < 2)
                invalidInp();
            else {
                del = toDel();
                if (del == true)
                    delArr(here,pic,leng);
            }
            break;
        case 3:
            if (useArr < 3)
                invalidInp();
            else {
                del = toDel();
                if (del == true)
                    delArr(here,pic,leng);
            }
            break;
        case 4:
            if (head->macMax < 10)
                invalidInp();
            else if (useArr < 4)
                invalidInp();
            else{
                del = toDel();
                if (del == true)
                    delArr(here,pic,leng);
            }
            break;
        case 5:
            if (head->macMax < 10)
                invalidInp();
            else if (useArr < 5)
                invalidInp();
            else{
                del = toDel();
                if (del == true)
                    delArr(here,pic,leng);
            }
            break;
        case 6:
            moveArr(here,leng,1);
            break;
        case 7:
            moveArr(here,leng,0);
            break;
        case 9: 
            std::cout << "Leaving.";
            break;
        default:
            invalidInp();
            break;
        }
        recount(head);
        screenclear();
    }while(pic != 9);
}
void editMenu(VendPtr& head){
    screenclear();
    std::cout << "Which machine do you want to edit?\n";
    VendPtr here = head;
    int pic = 0, leng, maxarr, useArr;
    maxarr = head->macMax;
    do {
        if(head->macMax < 10)
            leng = 3;
        else
            leng = 5;
        maxarr = head->macMax;
        useArr = arrParse(here,leng,maxarr);
        std::cin >> pic;
        switch (pic) {
        //case 0:
        //    break;
        case 1:
            editMac(head, here,pic);
            break;
        case 2:
            if (useArr < 2)
                invalidInp();
            else
                editMac(head, here,pic);
            break;
        case 3:
            if (useArr < 3)
                invalidInp();
            else
                editMac(head, here,pic);
            break;
        case 4:
            if (head->macMax < 10)
                invalidInp();
            else if (useArr < 4)
                invalidInp();
            else
                editMac(head,here,pic);
            break;
        case 5:
            if (head->macMax < 10)
                invalidInp();
            else if (useArr < 5)
                invalidInp();
            else
                editMac(head,here,pic);
            break;
        case 6:
            moveArr(here,leng,1);
            break;
        case 7:
            moveArr(here,leng,0);
            break;
        case 9: 
            std::cout << "Leaving.";
            simulatedelay();
            screenclear();
            break;
        default:
            invalidInp();
            break;
        }
    }while(pic != 9);
}
bool editMac(VendPtr& head, VendPtr& here, int pic){
    int ii = 1;
    bool rep = false;
    VendPtr iter = here;
    while(ii != pic){
        iter = iter->f_ptr;
        ii++;
    }
    screenclear();
    uselessfun1();
    uselessfun2();
    std::cout << "What do you want to modify for " << iter->name << "?\n";
    uselessfun1();
    std::cout << "1. Snacks\n2. Drink\n3. Name\n5. Cancel\n";
    uselessfun1();
    uselessfun2();
    query();
    std::cin >> ii;
    switch (ii)
    {
    case 1:
        modSnack(iter);
        break;
    case 2: 
        modDrink(iter);
        break;
    case 3:
        while(rep == false){
            processName(iter,iter->mactyp);
            rep = checkName(head,iter,1);
        }
        break;
    case 4: 
        refillMac(iter);
    case 5: 
        break;
    default:
        invalidInp();
        break;
    }
}
void modSnack(VendPtr& here){
    char cnfm; // confirm 
    bool sel = false;
    do {
        uselessfun1();
        uselessfun2();
        std::cout << "Please enter an amount for chocolate bars: ";
        std::cin >> here->re_choc;
        uselessfun2();
        std::cout << "Please enter an amount for fruit bags : ";
        std::cin >> here->re_fruit;
        uselessfun2();
        std::cout << "Please enter an amount for gummy bags: ";
        std::cin >> here->re_gumy;
        uselessfun1();
        std::cout << "Refill stock now? Y/N\n";
        do {
            std::cin >> cnfm;
            screenclear();
            if (cnfm == 'Y' || cnfm == 'y'){
                std::cout << "Restocking";
                here->choco_bar = here->re_choc;
                here->gummy_bag = here->re_gumy;
                here->fruit_bag = here->re_fruit;
            }
            else if (cnfm == 'N' || cnfm == 'n')
                std::cout << "Maintaining current stock. Exiting.";
            else 
                invalidInp();
        }while (!(cnfm == 'Y') && !(cnfm == 'y') && !(cnfm == 'N') && !(cnfm == 'n'));
        std::cout << "\nAre you satifised with your decision?\n";
        do {
            std::cin >> cnfm;
            if (cnfm == 'Y' || cnfm == 'y')
                sel = true;
            else if (cnfm == 'N' || cnfm == 'n')
                sel = false;
            else 
                invalidInp();
        } while (!(cnfm == 'Y') && !(cnfm == 'y') && !(cnfm == 'N') && !(cnfm == 'n'));
        screenclear();
    }while (sel == false);
}
void modDrink(VendPtr& here){
    char cnfm; // confirm 
    bool sel = false;
    do {
        uselessfun1();  
        uselessfun2();
        std::cout << "Please enter an amount for Cola: ";
        std::cin >> here->re_coke;
        uselessfun2();
        std::cout << "Please enter an amount for ginger ale: ";
        std::cin >> here->re_ale;
        uselessfun2();
        std::cout << "Please enter an amount for Sprite: ";
        std::cin >> here->re_sprite;
        uselessfun1();
        std::cout << "Refill stock now? Y/N\n";
        do{
            std::cin >> cnfm;
            if (cnfm == 'Y' || cnfm == 'y'){
                std::cout << "Restocking";
                here->bot_coke = here->re_coke;
                here->bot_ale = here->re_ale;
                here->bot_sprite = here->re_sprite;
            }
            else if (cnfm == 'N' || cnfm == 'n')
                std::cout << "Maintaining current stock. Exiting.";
            else 
                invalidInp();
        }while (!(cnfm == 'Y') && !(cnfm == 'y') && !(cnfm == 'N') && !(cnfm == 'n'));
        std::cout << "Are you satifised with your decision?\n";
        do {
            std::cin >> cnfm;
            if (cnfm == 'Y' || cnfm == 'y')
                sel = true;
            else if (cnfm == 'N' || cnfm == 'n')
                sel = false;
            else 
                invalidInp();
        } while (!(cnfm == 'Y') && !(cnfm == 'y') && !(cnfm == 'N') && !(cnfm == 'n'));
        screenclear();
    }while (sel == false);
}
int arrParse(VendPtr& head,int leng, int maxarr){//},int typ){
    VendPtr here = head;
    int sel = 0, ii = 1;
    std::string tmparr[maxarr];
    screenclear();
    uselessfun1();
    uselessfun2();
    //if (typ == 1)
        std::cout << "What machine do you want to deal with?\n";
    //else 
    //    std::cout << "Where are you based?\n";
    for(int jj = 0; jj < leng; jj++){
        uselessfun2();
        //std::cout << "Machine #" <<here->macNum << " " << here->name << " (" << here->tag << ")\n";
        std::cout << ii << ". " << here->name << " (" << here->tag << ")\n";
        if (here->f_ptr == NULL){
            jj = leng;
            break;
        }
        else if (jj < leng - 1){
            here = here->f_ptr;
            ii++;
        }
    }
    if(here->f_ptr != NULL){
        uselessfun2();
        std::cout << "6. Move to next " << leng << "\n";
    }
    if(head->b_ptr != NULL) {
        uselessfun2();
        std::cout << "7. Move to previous " << leng << "\n";
    }
    uselessfun2();
    /*if (typ == 1)
        std::cout << "9. Cancel\n";
    else 
        std::cout << "9. Walk away from the machine.\n";*
    std::cout << "9. Cancel\n";
    query();
    return ii;
}
void newOffice(VendPtr& iter){
    VendPtr tempPtr = new myVend;
    processName(tempPtr,1);
    office_vend(tempPtr);
    tempPtr->macNum = iter->macNum+1;
    if (iter->macMax == 1){
        iter = tempPtr;
        iter->macMax = 1;
    }
    else{
        iter->f_ptr = tempPtr;
        tempPtr->b_ptr = iter;
        iter = tempPtr;
    }
}
void newSchool(VendPtr& iter){
    VendPtr tempPtr = new myVend;
    processName(tempPtr,2);
    school_vend(tempPtr);
    tempPtr->macNum = iter->macNum+1;
    if (iter->macMax == 1){
        iter = tempPtr;
        iter->macMax = 1;
    }
    else{
        iter->f_ptr = tempPtr;
        tempPtr->b_ptr = iter;
        iter = tempPtr;
    }
}
void processName(VendPtr& tempP, int loc){
    char user_in;
    int counter;
    std::string temptag;
    std::string tempname;
    do{ 
        counter = 0;
        tempname.clear();
        temptag.clear();
        char confirm = 'k';
        int ii =0;
        if (loc == 1){
            std::cout << "\nWhat is the name of your company?\n";
            tempP->type = "Office";
            tempP->mactyp = 1;
        }
        else if (loc == 2){
            std::cout << "\nWhat is the name of your school? \n";
            tempP->type = "School";
            tempP->mactyp = 2;
        }
        //std::cin.ignore();
        do{
            std::getline(std::cin, tempname);
        }while(tempname.empty());
        while (ii < tempname.length() && tempname.length() != 0){ // loops through the provided name
            if (ii == 0){
                while (tempname[ii] == ' '){ // removes extra spaces in front
                    tempname.erase(ii,1);
                }
                tempname[ii] = toupper(tempname[ii]); // upper case the first word
                temptag += tempname[ii];
            }
            else if (((tempname[ii] == ' ' && tempname[ii+1] == ' '))){
                while (tempname[ii+1] == ' ')
                    tempname.erase(ii+1,1);
            }
            else if ((tempname[ii-1] == ' ') && !((tempname[ii] == 'o' || tempname[ii] == 'O') && (tempname[ii+1] == 'f' || (tempname[ii+1] == 'F')))){
                tempname[ii] = toupper(tempname[ii]);
                temptag += tempname[ii];
            } // upper case the first letter of a word excluding "of"
            else if (((tempname[ii] == ' ' && ii == tempname.length()))){
                tempname.erase(ii,1);
                ii--;
            }
            else
                tempname[ii] = tolower(tempname[ii]); // lower case the rest
            ii++;
        }
        while(confirm != 'y' || confirm != 'Y'){
            if (counter == 0 || counter == 5){
                    std::cout << "Is " << tempname << " the name you wanted?\nY / N\n";
                    //std::cout <<  temptag << '\n';
                    counter = 1;
            }
            std::cin >> confirm;
            if(confirm == 'n' || confirm == 'N' || confirm == 'y' || confirm == 'Y')
                break;
            else{
                naughtyUser();
                invalidInp(); 
                std::cout << "Is " << tempname << " the name you wanted?\nY / N\n";
                counter++;
            }       
        }
        naughtyUser();
        user_in = confirm;
    }while (!(user_in == 'Y') && !(user_in == 'y'));
    tempP->name = tempname;
    tempP->tag  = temptag;
}
void office_vend(VendPtr& tempPtr){
    //std::cout << "Why do you crash";
    // preset drinks
    tempPtr->re_coke    = 12;
    tempPtr->re_ale     = 12;
    tempPtr->bot_coke   = tempPtr->re_coke;
    tempPtr->bot_ale    = tempPtr->re_ale;
    // preset food 
    tempPtr->re_choc    = 12;
    tempPtr->re_gumy    = 12;
    tempPtr->re_chip    = 12;
    tempPtr->choco_bar  = tempPtr->re_choc;
    tempPtr->gummy_bag  = tempPtr->re_gumy;
    tempPtr->chips      = tempPtr->re_chip;
    // preset money
    tempPtr->ini_val    = 12;
    tempPtr->usable_bal = tempPtr->ini_val;
    tempPtr->gain_val   = 0;
    //std::cout << "over here";
}
void school_vend(VendPtr& tempPtr){
    // drinks
    tempPtr->re_coke    = 6;
    tempPtr->re_ale     = 6;
    tempPtr->re_sprite  = 6;
    tempPtr->bot_coke   = tempPtr->re_coke;
    tempPtr->bot_ale    = tempPtr->re_ale;
    tempPtr->bot_sprite = tempPtr->re_sprite;
    // food
    tempPtr->re_choc    = 12;
    tempPtr->re_gumy    =  6;
    tempPtr->re_fruit   = 12;
    tempPtr->choco_bar  = tempPtr->re_choc;
    tempPtr->gummy_bag  = tempPtr->re_gumy;
    tempPtr->fruit_bag  = tempPtr->re_fruit;
    // money
    tempPtr->ini_val    = 8;
    tempPtr->usable_bal = tempPtr->ini_val;
    tempPtr->gain_val   = 0;
}
void uselessfun1(){
    std::cout << "////////////////////////////////////////////////////////////////////\n";
}
void uselessfun1(int num){
    //for (int ii = 0; ii < num; ii++){
        std::cout << "////////////////////////////////////////////////////////////////////\n";
    //}
    for (int ii = 0; ii < num; ii++)
        std::cout << "\n";
}
void uselessfun2(){
    std::cout << "//     ";
}
void uselessfun3(std::string sen){
    uselessfun1();
    std::cout << sen; 
    uselessfun1();
}
/* useless test function now
int check_static(int test){
    std::cout << "The number is " << test << ".\nDoes this impact number?\n";
    test++;
    std::cout << "The number is now " << test << ".\n";
    return test;
}*
//////////////////// my debugger ////////////////////
// std::cout << "I am in []" << std::endl; simulatedelay();
void initializescale(){             // Sets the cout of dollars to 2 decimal points. 
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}
void screenclear(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void simulatedelay(){
    std::cin.ignore();
    std::cin.clear();
    std::cout << "\nPress enter key to continue..." << std::endl;
    std::cin.get();
}
void naughtyUser(){     // ignores extra words/spaces or invalid inputs 
    std::cin.clear();
    //std::cin.ignore(256,'\n');
    std::cin.get();
}
void query(){
    std::cout << "Please enter your decision: \n";
    uselessfun1(4);
}
void query1(){
    std::cout << "Press #9 to cancel, otherwise\n";
    std::cout << "Please enter your decision\n";
    std::cout << "And insert your coins: \n";
}
/*void testArray(VendPtr& head){
    uselessfun1();
    VendPtr here = head;
    while (here != NULL){
        std::cout << here->macMax << " " << here->macNum << " " << here->name << " " << 
        here->tag << " " << here->bot_ale << "\n";
        here = here->f_ptr;
    }
    simulatedelay();
}*
bool toDel(){
    char ans;
    std::cout << "Confirm your selection: Y / N\n";
    std::cin >> ans;
    while (!((ans == 'Y')||(ans == 'y')||(ans=='N')||(ans=='n'))){ // I'll try out this type of condition later
        std::cout << "Invalid Input" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> ans;
    }
    if (ans == 'Y' || ans == 'y')
        return true;
    else
        return false;
}
void delArr(VendPtr& iter){
    VendPtr todel = iter;
    iter = iter->b_ptr;
    if(todel->f_ptr != NULL)
        iter->f_ptr = todel->f_ptr;
    else
        iter->f_ptr = NULL;
    todel = NULL;
}
void delArr(VendPtr& here, int pic,int leng){
    int ii = 1;
    while(ii != pic){
        here = here->f_ptr;
        ii++;
    }
    /////////////////////////////////////
    VendPtr back = here, fwd = here;
    if ((here->b_ptr != NULL) && (here->f_ptr != NULL)){ // best case ; not at end or start
        back = here->b_ptr;
        fwd  =  here->f_ptr;
        back->f_ptr =  fwd;
        fwd->b_ptr  = back;
    }
    else if (here->b_ptr == NULL){
        fwd = here->f_ptr;
        fwd->b_ptr = here->b_ptr;
    }
    else if (here->f_ptr == NULL){
        back = here->b_ptr;
        back->f_ptr = here->f_ptr;
    }
    else { // delete everything(?)

    }
    //////////////////////////////
    if (pic == 1 && here->f_ptr != NULL){
        VendPtr del = here;
        here = here->f_ptr;
        del = NULL;
    }
    else if (pic == 1 && here->f_ptr == NULL){
        VendPtr del = here;
        moveArr(here,leng,0);
        del = NULL;
    }
    else if (pic != 1 && here->b_ptr != NULL){
        VendPtr del = here;
        here = here->b_ptr;
        del = NULL;
    }
    else if (pic != 1 && here->b_ptr == NULL){
        VendPtr del = here;
        here = here->f_ptr;
        del = NULL;
    }
    else
        here = NULL;
}
void moveArr(VendPtr& here, int leng, int dirr){
    if (dirr == 0){
        for(int ii = 0; ii < leng; ii++){
            if(here->b_ptr != NULL)
                here = here->b_ptr;
        }
    }
    else{
        for(int ii = 0; ii < leng; ii++){
            if(here->f_ptr != NULL)
                here = here->f_ptr;
        }
    }
}
void recount(VendPtr& head){
    VendPtr here = head;
    int ii = 0;
    while(here != NULL){
        here = here->f_ptr;
        ii++;
    }
    head->macMax = ii;
}
void invalidInp(){
    screenclear();
    std::cout << "That was not a valid Input. Please try again\n";
}
bool checkName(VendPtr& head, VendPtr& iter,int whr){
    VendPtr here = head;
    while(here->f_ptr != NULL ){//|| here->name != iter->name){
        //std::cout << here->macNum << ". " << here->name << "\n";
        //std::cout << iter->macNum << ". " << iter->name << "\n";
        if ((here->name == iter->name && (here->macNum != iter->macNum))){
            screenclear();
            uselessfun1();
            std::cout << "That location has already been added\n";
            uselessfun1();
            if (whr == 0){
                delArr(iter);
                recount(head);
            }
            //break;
            return false;
        }
        else
            here = here->f_ptr;
    }
    return true;
}
void refillMac(VendPtr& head){
    char ref; // refill check
    char fur; // further inquiry 
    if (head->macMax == 0){
        screenclear();
        uselessfun1();
        std::cout << "No machines to refill!\n";
        return;
    }
    do {
        VendPtr iter = head;    
        screenclear();
        uselessfun1();
        uselessfun2();
        std::cout << "Entering Refill Menu\n";
        uselessfun1();
        uselessfun2();
        std::cout << "Do you want to refill all machines? Y / N \n";
        uselessfun1();
        std::cin >> ref;
        screenclear();
        switch (ref){
            case 'Y': case 'y':
                std::cout << "Refilling\n";
                uselessfun1();
                refill(iter,0);
                break;
            case 'N': case 'n':
                uselessfun1();
                uselessfun2();
                std::cout << "Do you want to refill office or school separetly? Y / N\n";
                uselessfun1();
                std::cin >> fur;
                if (fur == 'y' || fur == 'Y')
                    refill(iter,1);
                else if (fur == 'N' || fur == 'n')
                    std::cout << "You can refill individual machines in the edit menu\n";
                break;
            default:
                invalidInp();
                break;
    }
    }while(!((ref == 'Y')||(ref == 'y')||(ref=='N')||(ref=='n')));
}
void refill(VendPtr& iter,int sel){
    ///////////////////////////// Refill All /////////////////////////////
    //VendPtr here = iter;
    if (sel == 0){
        std::cout << "...\n";
        while (iter->f_ptr != NULL){
        //while(iter->f_ptr){
        //do{
            //std::cout << "Testing\n";
            doRefill(iter);
            iter = iter->f_ptr;
        }//while(here->f_ptr != NULL);
        //} // annoying requirment to do one more after
        doRefill(iter);
        std::cout <<"Refilling complete.\n";
    }
    ///////////////////////////// Refill Minor /////////////////////////////
    else if (sel == 1){
        std::string cmpword; 
        int pic;
        uselessfun1();
        uselessfun2();
        std::cout << "Do you want to refill:\n1. All Offices\n2. All Schools\n3. Cancel\n";
        uselessfun1();
        std::cin >> pic;
        switch (pic){
        case 1: /////////////// Office Refill //////////////
            std::cout << "Refilling all offices\n";
            while (iter->f_ptr != NULL){
                if(iter->type == "Office"){
                    //std::cout <<"Testing\n";
                    doRefill(iter);
                }
                iter = iter->f_ptr;
            }
            if(iter->type == "Office"){
                    //std::cout <<"Testing\n";
                    doRefill(iter);
            }
            break;
        case 2: /////////////// School Refill //////////////
            std::cout << "Refilling all schools\n";
            while (iter->f_ptr != NULL){
                if(iter->type == "School"){
                    //std::cout <<"Testing\n";
                    doRefill(iter);
                }
                iter = iter->f_ptr;
            } 
            if(iter->type == "Office"){ 
                //std::cout <<"Testing\n";
                doRefill(iter);
            }
            break; 
        case 3:
            std::cout << "You can refill individual machines in the edit menu\n";
            break;
        default:
            invalidInp();
            break;
        }
    }
}
void doRefill(VendPtr& iter){
    iter->bot_coke = iter->re_coke;
    iter->bot_ale = iter->re_ale;
    iter->bot_sprite = iter->re_sprite;
    iter->choco_bar = iter->re_choc;
    iter->gummy_bag = iter->re_gumy;
    iter->chips = iter->re_chip;
    iter->fruit_bag = iter->re_fruit;
    iter->gain_val = iter->usable_bal - iter->ini_val;
    iter->usable_bal = iter->ini_val;
    std::cout << iter->name << " made $" << iter->gain_val << " in profit.\n";
}/*
void userMain(VendPtr& head){
    int leng, maxarr,pic;
    if(head->macMax < 10)
            leng = 3;
        else
            leng = 5;
    maxarr = head->macMax;
    uselessfun1();
    uselessfun2();
    std::cout << "Hello.\nI see you're hungry.\nLet's try to satiate you.\n";
    VendPtr here = head;
    do {
        pic = arrParse(here,leng,maxarr,0);
        switch (pic) {
        case 1:
            useMac(here,pic);
            break;
        case 2:
            if (pic < 2)
                invalidInp();
            else
                useMac(here,pic);
            break;
        case 3:
            if (pic < 3)
                invalidInp();
            else
                useMac(here,pic);
            break;
        case 4:
            if (head->macMax < 10)
                invalidInp();
            else if (pic < 4)
                invalidInp();
            else
                useMac(here,pic);
            break;
        case 5:
            if (head->macMax < 10)
                invalidInp();
            else if (pic < 5)
                invalidInp();
            else
                useMac(here,pic);
            break;
        case 6:
            moveArr(here,leng,1);
            break;
        case 7:
            moveArr(here,leng,0);
            break;
        case 9: 
            std::cout << "Leaving.";
            break;
        default:
            invalidInp();
            break;
        }
    }while(pic != 9);
}
void useMac(VendPtr& here, int mac){
    int money, sel, ii = 1;
    bool cancom = false; // cancel or complete
    VendPtr iter = here;
    while(ii != mac){
        iter = iter->f_ptr;
        ii++;
    }
    do{
    screenclear();
    uselessfun1();
    std::cout << "////////////// " << iter->name << " //////////////\n";
    uselessfun1();
    std::cout << "////////////// Sugar treats //////////////\n";
    std::cout << "1. Chocolate Bars. Qty: " << iter->choco_bar << " || 2. Gummy Candy Bag. Qty: " << iter->gummy_bag << "\n";
    std::cout << "////////////// " << iter->price << " || " << iter->price << " //////////////\n";
    uselessfun1();
    std::cout << "////////////// Bagged treats //////////////\n";
    std::cout << "3. Chip bags. Qty: " << iter->chips << " || 4. Fruit bags. Qty: " << iter->fruit_bag << "\n";
    std::cout << "////////////// " << iter->price << " || " << iter->price << " //////////////\n";
    uselessfun1();
    std::cout << "////////////// Drinks and Pop //////////////\n";
    std::cout << "5. Coca Cola. Qty: " << iter->bot_coke << " || 6. Ginger Ale. Qty: " << iter->bot_ale << " || 7. Sprite. Qty: " << iter->bot_sprite << "\n";
    std::cout << "////////////// " << iter->price << " || " << iter->price << " || " << iter->price << " //////////////\n";
    uselessfun1();
    query1();
    std::cin >> sel;
    if (sel > 0 && sel < 9)
        money = insertMoney();
    }while (cancom == true);
    
}
int insertMoney(){
    int pic;
    int quart = 0, dime = 0,nick = 0;
    do {
        std::cout << "1. Quarters: " << quart;
        std::cout << "\n2. Dimes: " << dime;
        std::cout << "\n3. Nickels: " << nick;
        std::cout << "4. Done\n";
        std::cin >> pic;
    }while (pic != 4);
}*/

int main (int args, char *argv[]){
    VendUser Vending;
    //VendUser Vending("school", "Burnett Secondary");
    
}
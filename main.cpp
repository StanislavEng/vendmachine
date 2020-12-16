/* Program to learn structures and create vending machines 
This will also be used to use the vending machines as well
Written by: Stas, Aug 21/22 2020 */ 

/* File name: Vending Machine, main.cpp
Author: Stanislav Svichkar
Personal Project
Description:
Last Changed Dec 8, 2020*/  // quick edit to double check some stuff  

#include <iostream>
#include <string>

//using namespace std;

// Structue for a vending machine 
struct myVend{
    std::string name;                                         // name of the location 
    int bot_coke, bot_ale, bot_sprite;                        // bottles of drinks (coca cola, ginger ale, sprite)
    int re_coke, re_ale, re_sprite;                           // restock value for drinks
    int choco_bar, gummy_bag, chips, fruit_bag;               // food items 
    int re_choc, re_gumy, re_chip, re_fruit;                  // restock value for food 
    double usable_bal, gain_val, ini_val;                     // usable balance, how much money earned, initial value
    std::string tag;                                          // classification tag
    int macNum = 0;                                           // For use in array only
    myVend *f_ptr;
    myVend *b_ptr;
    //myVend *link;
};
typedef myVend* VendPtr;

void school_vend(VendPtr& tempPtr);                   // create a vending machine for use in a school
void office_vend(VendPtr& tempPtr);                     // create a vending machine for use in a work office
//void admin_control(struct myVend macArray, int admin_choice); // Entering Admin Control 
//void admin_control(struct myVend macArray[100]);
void admin_control(VendPtr& iter);
void manageMac(VendPtr& iter);
void addMac(VendPtr& iter);
void editMac(VendPtr& iter);
void removeMac(VendPtr& iter);
void newOffice(VendPtr& iter);
void newSchool(VendPtr& head);
void processName(VendPtr& temp, int loc);
void user_control(struct myVend& machine);                    // Entering User Input Mode
void initializescale();                                       // Limits the decimal values
void initilizesystem();                                       // place holder for creating 
void screenclear();                                           // clear screen for easier UI
void simulatedelay();                                         // allow user to see response before clearing screen
int  check_static(int test);
void naughtyUser();
void myDebug(VendPtr& head,VendPtr& itr);
void uselessfun1();
void uselessfun2();
void enterDebug(VendPtr& ptr);

int main(int argc, char *argv[]){
    screenclear();
    int macMax = 100;
    //struct myVend macArray[macMax];
    //struct myVend macArray;
    //VendPtr ptr = new myVend;
    //struct myVend macArray;
    VendPtr head = new myVend;
    //int macsize;  
    //head = macArray;
    VendPtr last;
    last = head;
    //ptr = macArray;
    //int firstInput;
    //std::cout << "Weclome to the Vending Machine Control Hub\n";
    //TODO:: add in counter
    //std::cout << "What would you like to do?\n";
    //std::cout << "1. Manage Machines\n2.Exit" << std::endl;
    //std::cin >> firstInput;
    while(1){
        std::cout << "Checking something";
        simulatedelay();
        while(1){
            //myDebug(head,last);
            admin_control(last);
            screenclear();
            std::cout << "You shouldn't be here\n";
            simulatedelay();
        }
        std::cout << "Where are you going";
        simulatedelay();
    }
    std::cout << "You shouldn't have gotten here";
    simulatedelay();
    //std::cout << ptr->macNum;
    //return 0;
}
/*void initilizesystem(VendPtr& head, VendPtr& iter){

}*/
//////////////////// Start of functions ////////////////////
void myDebug(VendPtr& head, VendPtr& itr){
    int picker;
    do {
        screenclear();
        uselessfun1();
        uselessfun2();
        std::cout << "Welcome to the debug screen\n";
        uselessfun2();
        std::cout << "Which pointer do you want to access?\n"; uselessfun2(); std::cout << "1. Head or 2. Iter? 3. Quit" << std::endl;
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
            break;
        default:
            std::cout << "That ain't it chief";
            naughtyUser();
            simulatedelay();
            break;
        }
    } while (picker != 3);
}
void enterDebug(VendPtr& ptr){
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
            std::cout << ptr->macNum;
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
            naughtyUser();
            simulatedelay();
            break;
        }
    }while (picker != 4);

}
void admin_control(VendPtr& iter){
    int admin_input = 0;; 
    int arrayLength = iter->macNum;
    //static struct myVend macArray[100];
    //int num_of_mac = 0;
    screenclear();
    uselessfun1(); uselessfun2();
    std::cout << "Welcome to the Vending Machine Control Hub\n"; uselessfun2();
    std::cout << "There are " << arrayLength << " machines in service\n"; uselessfun2();
    //std::cout << "There are " << num_of_mac << " machines in service\n";
    do {
        //uselessfun1();
        std::cout << "What would you like to do?\n"; uselessfun1();
        std::cout << "1. Manage Machines\n2. # of Machines?\n3. Exit\n";
        std::cout << "Please enter your choice: "<< std::endl;
        std:: cin >> admin_input;
        switch(admin_input){
            case 1: // Management screen: Create, Remove, Edit
                manageMac(iter);
                break;
            case 2: // 
                std::cout << "There are " << arrayLength << " machines in service\n";
                break;
            case 3:
                std::cout << "Leaving the Control Hub\n";
                break;
            default:
                screenclear();
                uselessfun1();
                std::cout << "That was not a valid input. Please try again.\n";
                naughtyUser();
                break;

        }
        //head->macNum = arrayLength+1;
        //check_static(num_of_mac);
    } while (admin_input != 3);
    //admin_input = 0;

}
void manageMac(VendPtr& iter){
    int decision = 0; 
    screenclear();
    do{
        uselessfun1();
        std::cout << "Do you want to:\n1. Create New Machine\n2. Edit Machines\n3. Remove Machines\n4. Cancel\n";
        std::cout << "Please enter your choice: ";
        std::cin >> decision;
        std::cout << "\n";
        switch (decision){
        case 1:
            addMac(iter);
            break;
        case 2:
            //editMac(head);
            break;
        case 3:
            //removeMac(head);
            break;
        case 4:
            break;
        default:
            screenclear();
            std::cout << "That was not a valid input. Please try again.\n";
            naughtyUser();
            break;
        }
        std::cout <<"oh no";
    }while(decision != 4);
}
void addMac(VendPtr& iter){
    screenclear();
    int test;
    bool exitcond = false;
    do{
        int pickLoc = 0;   
        char morecpic = 'k'; 
        std::cout << pickLoc;
        std::cout << "Is this for a school or an office?\n";
        std::cout << "1. Office\n2. School\n3. Cancel\n";
        std::cout << "Enter your decision: " << std::endl;
        //std::cin.ignore();
        //std::cin >> std::ws;
        std::cin >> pickLoc;
        std::cout << "How far are we getting?";
        switch (pickLoc){
        case 1:
            //std::cin >> test;
            //std::cout << "We got here\n";
            newOffice(iter);
            //std::cout << "We got there\n";
            break;
        case 2: 
            newSchool(iter);
            break;
        case 3:
            exitcond = true;
            break;
        default:
            screenclear();
            std::cin >> test;
            std::cout << "That was not a valid input. Please try again.\n";
            naughtyUser();
            break;
        }
        //std::cin.clear();
        //std::cout << "just in case " << std::endl;
        //std::cin >> test;
        if (pickLoc == 1 || pickLoc == 2){
            std::cout << "Do you want to add another machine? Y / N" << std::endl;
            while(true){
                std::cin >> morecpic;
                if(morecpic == 'n' || morecpic == 'N' || morecpic == 'y' || morecpic == 'Y')
                    break;
                else
                    std::cout << "That was not a valid input. Please try again:\n"; 
            }

        }

        std::cout << pickLoc << "Is not right";// << std::endl;
        //naughtyUser();
    } while ((exitcond == false));
}
void newOffice(VendPtr& iter){
    screenclear();
    //int test = 1;
    VendPtr tempPtr;
    //processName(tempPtr,test);
    processName(tempPtr,1);
    //screenclear();
    std::cout << "Are we here?\n";
    //simulatedelay();
    //office_vend(tempPtr);
    iter->f_ptr = tempPtr;
    tempPtr->b_ptr = iter;
    iter->macNum++;
    iter = tempPtr;
}
void newSchool(VendPtr& iter){
    screenclear();
    VendPtr tempPtr;
    processName(tempPtr,2);
    screenclear();
    school_vend(tempPtr);
    
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
        if (loc == 1)
            std::cout << "\nWhat is the name of your company?\n";
        else if (loc == 2)
            std::cout << "What is the name of your school?\n";
        std::cin.ignore();
        std::getline(std::cin, tempname);
        while (ii <= tempname.length() && tempname.length() != 0){ // loops through the provided name
            if (ii == 0){
                while (tempname[ii] == ' '){ // removes extra spaces in front
                    tempname.erase(ii,1);
                }
                tempname[ii] = toupper(tempname[ii]); // upper case the first word
                temptag += tempname[ii];
                ii++;
            }
            else if ((tempname[ii] == ' ' && tempname[ii+1] == ' ')){
                while (tempname[ii+1] == ' ')
                    tempname.erase(ii+1,1);
            }
            else if ((tempname[ii-1] == ' ') && !((tempname[ii] == 'o' || tempname[ii] == 'O') && (tempname[ii+1] == 'f' || (tempname[ii+1] == 'F')))){
                tempname[ii] = toupper(tempname[ii]);
                temptag += tempname[ii];
            } // upper case the first letter of a word excluding "of"
            else 
                tempname[ii] = tolower(tempname[ii]); // lower case the rest
            ii++;
        }
        while(confirm != 'y'){
            if (counter == 0 || counter == 5){
                    std::cout << "Is " << tempname << " the name you wanted? Y / N\n";
                    //std::cout <<  temptag << '\n';
                    counter = 1;
            }
            std::cin >> confirm;
            if(confirm == 'n' || confirm == 'N' || confirm == 'y' || confirm == 'Y')
                break;
            else{
                std::cout << "That was not a valid input. Please try again:\n"; 
                counter++;
            }       
        }
        user_in = confirm;
    }while (!(user_in == 'Y') && !(user_in == 'y'));
}
void office_vend(VendPtr& tempPtr){
    std::cout << "Why do you crash";
    // preset drinks
    tempPtr->re_coke    = 12;
    tempPtr->re_ale     = 12;
    //tempPtr->bot_coke   = tempPtr->re_coke;
    //tempPtr->bot_ale    = tempPtr->re_ale;
    // preset food 
    tempPtr->re_choc    = 12;
    tempPtr->re_gumy    = 12;
    tempPtr->re_chip    = 12;
    //tempPtr->choco_bar  = tempPtr->re_choc;
    //tempPtr->gummy_bag  = tempPtr->re_gumy;
    //tempPtr->chips      = tempPtr->re_chip;
    // preset money
    tempPtr->ini_val    = 12;
    //tempPtr->usable_bal = tempPtr->ini_val;
    tempPtr->gain_val   = 0;
    std::cout << "over here";
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
    std::cout << "//////////////////////////////////////////////////////////\n";
}
void uselessfun2(){
    std::cout << "//     ";
}
/* useless test function now
int check_static(int test){
    std::cout << "The number is " << test << ".\nDoes this impact number?\n";
    test++;
    std::cout << "The number is now " << test << ".\n";
    return test;
}*/
/////// my debugger ////
// std::cout << "I am in []" << std::endl; simulatedelay();
/*
int main(){
    screenclear();
    int num_of_mac = 0; // for determing how many machines exist
    int mm_input   = 0; // main menu input control
    int admin_input = 0, user_input = 0, choicehere =0;
    int macsel = 0; 
    int ii = 0;
    //string macsel;
    char user_exit = 'N';
    std::string tempname;
    static struct myVend madeMac;
    struct myVend mahrray[100];
    
    do {  // Admin Control Screen
        std::cout << "\nWelcome to the Vending Machine Control Hub\n";
        std::cout << "There are " << num_of_mac << " machines in operation." << endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1. Manage Machines\n2. Use Machines\n3. Exit\n" << endl;

        std::cin >> mm_input;
        screenclear();
        switch(mm_input) {  // 
            case 1: // Admin control : Create New, Remove, Edit, Restock
                do {
                    std::cout << "Hello Admin. What would you like to do?" << endl;
                    std::cout << "1. Create New Machine.\n2. Edit Machine.\n3. Restock Machine.\n4. Remove Machine.\n5. Exit.\n" << endl;

                    std::cin >> admin_input; 
                    screenclear();
                    // admin_control(admin_input);
                    if (admin_input != 5){
                        switch(admin_input){
                            case 1: // Create Machines 
                                madeMac = myVend();
                                while(choicehere != 3 ){
                                    std::cout << "Is this machine for a school or an office environement?" << endl;
                                    std::cout << "1. Office\n2. School\n3. Back\n" << endl;
                                    std::cin >> choicehere;
                                    screenclear();
                                    switch (choicehere){
                                        case 1:                                                                                   
                                            while (user_exit == 'N' || user_exit == 'n') {
                                                madeMac = myVend();
                                                std::cout << "What is the name of the company?" << endl;
                                                std::cin.ignore();
                                                std::getline(std::cin,tempname);
                                                while (ii <= tempname.length()) {
                                                    if (ii == 0) { 
                                                        while (tempname[ii] == ' ') { // removes any spaces put in front of first word
                                                            tempname.erase(ii,1);
                                                        }                                                        
                                                        tempname[ii] = toupper(tempname[ii]); // upper cases first word
                                                        madeMac.tag += tempname[ii]; // adds to tag
                                                        ii++;
                                                    } 
                                                    else if ((tempname[ii] == ' ' && tempname[ii+1] == ' ')) {
                                                        while (tempname[ii+1] == ' ')
                                                            tempname.erase(ii+1,1);
                                                    } // removes EXTRA spaces
                                                    else if ((tempname[ii-1] == ' ') && !((tempname[ii] == 'o' || tempname[ii] == 'O') && (tempname[ii+1] == 'f' || tempname[ii+1] == 'F'))) {
                                                        tempname[ii] = toupper(tempname[ii]);
                                                        madeMac.tag += tempname[ii];
                                                        ii++;
                                                    } // upper cases first letter of other words unless it's "of" which is lowercased
                                                    else 
                                                        tempname[ii] = tolower(tempname[ii]); // lower cases the rest
                                                    ii++;
                                                }
                                                screenclear();
                                                std::cout << "Is " << tempname << " the name you wanted?   Y / N " << endl;
                                                while (true) {  // forces only yes or no replies. if no, resets the whole loop
                                                    std::cin >> user_exit;
                                                    if (user_exit == 'n' || user_exit == 'N' || user_exit == 'y' || user_exit == 'Y')
                                                        break;
                                                    else
                                                        std::cout << "That was not a valid input. Please try again." << endl;
                                                } 
                                                ii = 0;
                                            }
                                            screenclear();
                                            madeMac.name = tempname;
                                            // preset drinks
                                            madeMac.re_coke = 12;
                                            madeMac.re_ale  = 12;
                                            madeMac.bot_coke = madeMac.re_coke;
                                            madeMac.bot_ale  = madeMac.re_ale;
                                            // preset food 
                                            madeMac.re_choc = 12;
                                            madeMac.re_gumy = 12;
                                            madeMac.re_chip = 12;
                                            madeMac.choco_bar = madeMac.re_choc;
                                            madeMac.gummy_bag = madeMac.re_gumy;
                                            madeMac.chips     = madeMac.re_chip;
                                            // preset money
                                            madeMac.ini_val    = 12;
                                            madeMac.usable_bal = madeMac.ini_val;
                                            madeMac.gain_val   = 0;

                                            std::cout << "\nThe name you wrote is " << madeMac.name << ". It has the tag: " << madeMac.tag <<  endl;
                                            std::cout << "The preset drink can quantities are:\nCola: " << madeMac.bot_coke << ", Ginger Ale: " << madeMac.bot_ale << ", Sprite: " \
                                            << madeMac.bot_sprite << "."<< endl;
                                            std::cout << "\nThe present snack quantities are:\nChocolate Bars: " << madeMac.choco_bar << ", Gummy Snacks: " << madeMac.gummy_bag << \
                                            ", Chip bags: " << madeMac.chips << "." << std::endl; 
                                            mahrray[num_of_mac] = madeMac;
                                            num_of_mac++;
                                            break;
                                        case 2:                                                                                  
                                            std::cout << "What is the name of the school?" << std::endl;
                                            std::cin.ignore();
                                            std::getline(std::cin,tempname);
                                            while (user_exit == 'N' || user_exit == 'n') {
                                                madeMac = myVend();
                                                std::cout << "What is the name of the company?" << std::endl;
                                                std::cin.ignore();
                                                std::getline(std::cin,tempname);
                                                while (ii <= tempname.length()) {
                                                    if (ii == 0) {
                                                        while (tempname[ii] == ' ') {
                                                            tempname.erase(ii,1);
                                                        }                                                        
                                                        tempname[ii] = toupper(tempname[ii]);
                                                        madeMac.tag += tempname[ii];
                                                        ii++;
                                                    }
                                                    else if ((tempname[ii] == ' ' && tempname[ii+1] == ' ')) {
                                                        while (tempname[ii+1] == ' ')
                                                            tempname.erase(ii+1,1);
                                                    }
                                                    else if ((tempname[ii-1] == ' ') && !((tempname[ii] == 'o' || tempname[ii] == 'O') && (tempname[ii+1] == 'f' || tempname[ii+1] == 'F'))) {
                                                        tempname[ii] = toupper(tempname[ii]);
                                                        madeMac.tag += tempname[ii];
                                                        ii++;
                                                    }
                                                    else 
                                                        tempname[ii] = tolower(tempname[ii]);
                                                    ii++;
                                                }
                                                screenclear();
                                                std::cout << "Is " << tempname << " the name you wanted?   Y / N " << std::endl;
                                                while (true) {
                                                    std::cin >> user_exit;
                                                    if (user_exit == 'n' || user_exit == 'N' || user_exit == 'y' || user_exit == 'Y')
                                                        break;
                                                    else
                                                        std::cout << "That was not a valid input. Please try again." << std::endl;
                                                } 
                                                ii = 0;
                                            }
                                            screenclear();
                                            madeMac.name = tempname;
                                            // drinks
                                            madeMac.re_coke   = 6;
                                            madeMac.re_ale    = 6;
                                            madeMac.re_sprite = 6;
                                            madeMac.bot_coke   = madeMac.re_coke;
                                            madeMac.bot_ale    = madeMac.re_ale;
                                            madeMac.bot_sprite = madeMac.re_sprite;
                                            // food
                                            madeMac.re_choc  = 12;
                                            madeMac.re_gumy  =  6;
                                            madeMac.re_fruit = 12;
                                            madeMac.choco_bar = madeMac.re_choc;
                                            madeMac.gummy_bag = madeMac.re_gumy;
                                            madeMac.fruit_bag = madeMac.re_fruit;
                                            // money
                                            madeMac.ini_val  = 8;
                                            madeMac.usable_bal = madeMac.ini_val;
                                            madeMac.gain_val = 0;

                                            std::cout << "The name you wrote is " << madeMac.name << ". It has the tag: " << madeMac.tag <<  std::endl;
                                            std::cout << "The preset drink can quantities are:\nCola: " << madeMac.bot_coke << ", Ginger Ale: " << madeMac.bot_ale << ", Sprite: " \
                                            << madeMac.bot_sprite << "."<< std::endl;
                                            std::cout << "The present snack quantities are:\nChocolate Bars: " << madeMac.choco_bar << ", Gummy Snacks: " << madeMac.gummy_bag << \
                                            ", Fruit Bags: " << madeMac.fruit_bag << "." << std::endl; 
                                            mahrray[num_of_mac] = madeMac;
                                            num_of_mac++;
                                            break;
                                        case 3:
                                            break;
                                        default:
                                            std::cout << "That is not a valid entry. Please try again." << std::endl;
                                            break;
                                }
                                break;
                            case 2: // Edit Machines 
                                    while(user_input != 4){
                                        for (int i = 0; i < num_of_mac; i++){
                                            std::cout << i + 1;
                                            std::cout << ". " << mahrray[i].tag << std::endl;
                                        };
                                        if (user_input == 0 || user_input == 3){
                                            std::cout << "Please enter the location name" << std::endl;
                                            std::cin >> macsel;
                                            while (macsel > num_of_mac || macsel == 0){
                                                screenclear();
                                                std::cout << macsel << " is not a valid entry. Please try again." << std::endl;
                                                std::cin >> macsel;
                                            }
                                            madeMac = mahrray[macsel-1];
                                        }
                                        std::cout << "What would you like to change for " << madeMac.name << "?\n1. Drinks.\n2. Food.\n3. Change Machine.\n4. Back." << std::endl;
                                        std::cin >> user_input;
                                        switch (user_input){
                                        case 1: // drink edit
                                            std::cout << "Number of coke cans\n",
                                            std::cin >> madeMac.re_coke; 
                                            std::cout << "\nNumber of ginger ale cans\n";
                                            std::cin >> madeMac.re_ale;
                                            std::cout << "\nNumber of sprite cans\n";
                                            std::cin >> madeMac.re_sprite;
                                            break;
                                        case 2: // food edit
                                            std::cout << "\nNumber of chocolate bars\n";
                                            std::cin >> madeMac.re_choc;
                                            std::cout << "\nNumber of gummy bears\n";
                                            std::cin >> madeMac.re_gumy;
                                            std::cout << "\nNumber of chips\n";
                                            std::cin >> madeMac.re_chip;
                                            std::cout << "\nNumber of fruit bags\n";
                                            std::cin >> madeMac.re_fruit;
                                            break;
                                        case 3:
                                            
                                            break;
                                        case 4:
                                            break;
                                        default:
                                            std::cout << "That is not a valid entry. Please try again." << std::endl;
                                            break;
                                        }
                                    }
                                    user_input = 0;
                                break; 
                            case 3: // Restock Machines 
                                std::cout << "Restocking machine. Deducting costs and resetting wallet." << std::endl;
                                madeMac.bot_coke = madeMac.re_coke;
                                madeMac.bot_ale  = madeMac.re_ale;
                                madeMac.bot_sprite = madeMac.re_sprite;
                                madeMac.choco_bar = madeMac.re_choc;
                                madeMac.chips = madeMac.re_chip;
                                madeMac.gummy_bag = madeMac.re_gumy;
                                madeMac.fruit_bag = madeMac.re_fruit;
                                break;
                            case 4: // Remove Machines
                                break;
                            case 5:
                                break;
                            default:
                                std::cout << "That is not a valid entry. Please try again." << std::endl;
                                break;
                        }
                        simulatedelay();
                        screenclear();
                        admin_input = 0;
                        }
                    }

                }while (admin_input != 5);
                
                mm_input = 0;

            break;
            case 2: // User Control: Insert Coin, Choose Selection, Get Change

            break;
            case 3: // Exit Program. TODO: save output file
                user_exit = 'Y';
            break;
            default:
                std::cout << "That was not a valid choice. Pick again"<< std::endl;
                mm_input = 0;
        }

    }while(user_exit == 'N');
        
    return 0;

}
*/
// Sets the cout of dollars to 2 decimal points. 
void initializescale(){
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}
void screenclear(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
/*
void makeMachine(myVend *macArray){
    // temporary variables
    char user_exit = 'N';
    struct myVend madeMac; 
    string tempname;
    int ii = 0;

    while (user_exit == 'N' || user_exit == 'n') {
        madeMac = myVend();
        cout << "What is the name of the company?" << endl;
        cin.ignore();
        getline(cin,tempname);
        while (ii <= tempname.length()) {
            if (ii == 0) { 
                while (tempname[ii] == ' ') { // removes any spaces put in front of first word
                    tempname.erase(ii,1);
                }                                                        
                tempname[ii] = toupper(tempname[ii]); // upper cases first word
                madeMac.tag += tempname[ii]; // adds to tag
                ii++;
            } 
            else if ((tempname[ii] == ' ' && tempname[ii+1] == ' ')) {
                while (tempname[ii+1] == ' ')
                    tempname.erase(ii+1,1);
            } // removes EXTRA spaces
            else if ((tempname[ii-1] == ' ') && !((tempname[ii] == 'o' || tempname[ii] == 'O') && (tempname[ii+1] == 'f' || tempname[ii+1] == 'F'))) {
                tempname[ii] = toupper(tempname[ii]);
                madeMac.tag += tempname[ii];
                ii++;
            } // upper cases first letter of other words unless it's "of" which is lowercased
            else 
                tempname[ii] = tolower(tempname[ii]); // lower cases the rest
            ii++;
        }
        screenclear();
        cout << "Is " << tempname << " the name you wanted?   Y / N " << endl;
        while (true) {  // forces only yes or no replies. if no, resets the whole loop
            cin >> user_exit;
            if (user_exit == 'n' || user_exit == 'N' || user_exit == 'y' || user_exit == 'Y')
                break;
            else
                cout << "That was not a valid input. Please try again." << endl;
        } 
        ii = 0;
    }
}
void initilizeOffice(myVend *officeMac){
    madeMac.name = tempname;
    // preset drinks
    madeMac.re_coke = 12;
    madeMac.re_ale  = 12;
    madeMac.bot_coke = madeMac.re_coke;
    madeMac.bot_ale  = madeMac.re_ale;
    // preset food 
    madeMac.re_choc = 12;
    madeMac.re_gumy = 12;
    madeMac.re_chip = 12;
    madeMac.choco_bar = madeMac.re_choc;
    madeMac.gummy_bag = madeMac.re_gumy;
    madeMac.chips     = madeMac.re_chip;
    // preset money
    madeMac.ini_val    = 12;
    madeMac.usable_bal = madeMac.ini_val;
    madeMac.gain_val   = 0;
}
void initilizeSchool(myVend *schoolMac){
    madeMac.name = tempname;
    // drinks
    madeMac.re_coke   = 6;
    madeMac.re_ale    = 6;
    madeMac.re_sprite = 6;
    madeMac.bot_coke   = madeMac.re_coke;
    madeMac.bot_ale    = madeMac.re_ale;
    madeMac.bot_sprite = madeMac.re_sprite;
    // food
    madeMac.re_choc  = 12;
    madeMac.re_gumy  =  6;
    madeMac.re_fruit = 12;
    madeMac.choco_bar = madeMac.re_choc;
    madeMac.gummy_bag = madeMac.re_gumy;
    madeMac.fruit_bag = madeMac.re_fruit;
    // money
    madeMac.ini_val  = 8;
    madeMac.usable_bal = madeMac.ini_val;
    madeMac.gain_val = 0;
}
*/
void simulatedelay(){
    std::cin.ignore();
    std::cin.clear();
    std::cout << "\nPress enter key to continue..." << std::endl;
    std::cin.get();
}
void naughtyUser(){
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cin.get();
}
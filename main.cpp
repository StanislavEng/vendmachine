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
struct myVend
{
    std::string name;                                         // name of the location 
    int bot_coke, bot_ale, bot_sprite;                        // bottles of drinks (coca cola, ginger ale, sprite)
    int re_coke, re_ale, re_sprite;                           // restock value for drinks
    int choco_bar, gummy_bag, chips, fruit_bag;               // food items 
    int re_choc, re_gumy, re_chip, re_fruit;                  // restock value for food 
    double usable_bal, gain_val, ini_val;                     // usable balance, how much money earned, initial value
    std::string tag;                                          // classification tag
};

void school_vend(struct myVend the_school);                   // create a vending machine for use in a school
void work_vend(struct myVend the_office);                     // create a vending machine for use in a work office
void admin_control(struct myVend macArray, int admin_choice); // Entering Admin Control 
void user_control(struct myVend& machine);                    // Entering User Input Mode
void initializesystem();                                      // Limits the decimal values
void screenclear();                                           // clear screen for easier UI
void simulatedelay();                                         // allow user to see response before clearing screen

int main(){
    screenclear();

}





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
void initializesystem(){
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
}

/* for when works in main body
void admin_control(struct myVend macArray, int admin_choice){
    static int machine_counter = 0;
    int choicehere = 0;
    
    switch(admin_choice){
        case 1: // Create Machines 
            cout << "Is this machine for a school or an office environement?" << endl;
            cout << "1. Office\n2. School\n3. Back";
            cin >> choicehere;
            switch (choicehere){
                case 1:
                    work_vend(macArray);
                break;
                case 2:
                    school_vend(macArray);
                break;
                case 3:
                break;
            }

        break;
        case 2: // Edit Machines 
        
        break; 
        case 3: // Restock Machines 
        
        break;
        case 4: // Remove Machines

        break;
    }
 

}
*/

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
    std::cout << "\nPress enter key to continue..." << std::endl;
    std::cin.get();
}
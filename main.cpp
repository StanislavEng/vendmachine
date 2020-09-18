/* Program to learn structures and create vending machines 
This will also be used to use the vending machines as well
Written by: Stas, Aug 21/22 2020 */ 

/* File name: Vending Machine, main.cpp
Author: Stanislav
Personal Project
Description:
Last Changed August 22, 2020*/ 

#include <iostream>
#include <string>

using namespace std;

// Structue for a vending machine 
struct myVend
{
    string name; /// name of the location 
    int bot_coke, bot_ale, bot_sprite; /// bottles of drinks (coca cola, ginger ale, sprite)
    int choco_bar, gummy_bag, chips, fruit_bag; /// food items 
    double usable_bal, gain_val, ini_val; /// usable balance, how much money earned, initial value
};

void school_vend(struct myVend the_school);                   // create a vending machine for use in a school
void work_vend(struct myVend the_office);                     // create a vending machine for use in a work office
void admin_control(struct myVend macArray, int admin_choice); // Entering Admin Control 
void user_control(struct myVend& machine);                    // Entering User Input Mode
void initializesystem();                                      // nothing yet lel
void screenclear();                                           // clear screen for easier UI
void simulatedelay();                                         // allow user to see response before clearing screen


int main(){

    int num_of_mac = 0; // for determing how many machines exist
    int mm_input = 0; // main menu input control
    int admin_input = 0, user_input = 0, choicehere =0; 
    char user_exit = 'N';
    static struct myVend madeMac;
    
    do {  // Admin Control Screen
        cout << "\nWelcome to the Vending Machine Control Hub\n";
        cout << "There are " << num_of_mac << " machines in operation." << endl;
        cout << "What would you like to do?\n";
        cout << "1. Manage Machines\n2. Use Machines\n3. Exit\n" << endl;

        cin >> mm_input;
        screenclear();
        switch(mm_input) {  // 
            case 1: // Admin control : Create New, Remove, Edit, Restock
                do {
                    cout << "Hello Admin. What would you like to do?" << endl;
                    cout << "1. Create New Machine.\n2. Edit Machine.\n3. Restock Machine.\n4. Remove Machine.\n5. Exit.\n" << endl;

                    cin >> admin_input; 
                    screenclear();
                    // admin_control(admin_input);
                    if (admin_input != 5){
                        switch(admin_input){
                            case 1: // Create Machines 
                                while(choicehere != 3 ){
                                    cout << "Is this machine for a school or an office environement?" << endl;
                                    cout << "1. Office\n2. School\n3. Back\n" << endl;
                                    cin >> choicehere;
                                    screenclear();
                                    switch (choicehere){
                                        case 1:
                                            // work_vend(macArray);
                                            cout << "What is the name of the company?" << endl;
                                            cin.ignore();
                                            getline(cin,madeMac.name);
                                            madeMac.bot_coke = 12;
                                            madeMac.bot_ale = 12;
                                            madeMac.choco_bar = 12;
                                            madeMac.gummy_bag = 12;
                                            madeMac.chips = 12;
                                            madeMac.ini_val = 12;
                                            madeMac.usable_bal = madeMac.ini_val;
                                            madeMac.gain_val = 0;
                                            cout << "The preset drink can quantities are:\nCola: " << madeMac.bot_coke << ", Ginger Ale: " << madeMac.bot_ale << ", Sprite: " \
                                            << madeMac.bot_sprite << "."<< endl;
                                            cout << "The present snack quantities are:\nChocolate Bars: " << madeMac.choco_bar << ", Gummy Snacks: " << madeMac.gummy_bag << \
                                            ", Chip bags: " << madeMac.chips << "." << endl; 
                                            break;
                                        case 2:
                                            // school_vend(macArray);
                                            cout << "What is the name of the school?" << endl;
                                            cin.ignore();
                                            getline(cin,madeMac.name);
                                            madeMac.bot_coke = 6;
                                            madeMac.bot_ale = 6;
                                            madeMac.bot_sprite = 6;
                                            madeMac.choco_bar = 12;
                                            madeMac.gummy_bag = 6;
                                            madeMac.fruit_bag = 12;
                                            madeMac.ini_val = 8;
                                            madeMac.usable_bal = madeMac.ini_val;
                                            madeMac.gain_val = 0;
                                            cout << "The preset drink can quantities are:\nCola: " << madeMac.bot_coke << ", Ginger Ale: " << madeMac.bot_ale << ", Sprite: " \
                                            << madeMac.bot_sprite << "."<< endl;
                                            cout << "The present snack quantities are:\nChocolate Bars: " << madeMac.choco_bar << ", Gummy Snacks: " << madeMac.gummy_bag << \
                                            ", Fruit Bags: " << madeMac.fruit_bag << "." << endl; 
                                            break;
                                        case 3:
                                            break;
                                        default:
                                            cout << "That is not a valid entry. Please try again." << endl;
                                            break;

                                }
                                break;
                            case 2: // Edit Machines 
                                break; 
                            case 3: // Restock Machines 
                                break;
                            case 4: // Remove Machines
                                break;
                            case 5:
                                break;
                            default:
                                cout << "That is not a valid entry. Please try again." << endl;
                                break;
                        }
                        // for (int ii = 0; ii < 50; ii++)
                        //     cout << "\n";
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
                cout << "That was not a valid choice. Pick again"<< endl;
                mm_input = 0;
        }

    }while(user_exit == 'N');
        
    return 0;

}

// Sets the cout of dollars to 2 decimal points. 
void initializesystem(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
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
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void simulatedelay(){
    cout << "\nPress any key to continue..." << endl;
    cin.get();
}
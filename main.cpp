/* Program to learn structures and create vending machines 
This will also be used to use the vending machines as well
Written by: Stas, Aug 21/22 2020 */ 

/* File name: Vending Machine, main.cpp
Author: Stanislav Svichkar
Personal Project
Description:
Last Changed Feb 9, 2021*/  // Working on remove machine

#include <iostream>
#include <string>

// Structue for a vending machine 
struct myVend{
    std::string name = "blank";                                       // name of the location 
    int bot_coke = 0, bot_ale = 0, bot_sprite = 0;                    // bottles of drinks (coca cola, ginger ale, sprite)
    int re_coke = 0, re_ale = 0, re_sprite = 0;                       // restock value for drinks
    int choco_bar = 0, gummy_bag = 0, chips = 0, fruit_bag = 0;       // food items 
    int re_choc = 0, re_gumy = 0, re_chip = 0, re_fruit = 0;          // restock value for food 
    double usable_bal = 0, gain_val = 0, ini_val = 0;                 // usable balance, how much money earned, initial value
    std::string tag;                                                  // classification tag
    int macNum = 0;                                                   // For use in array only
    int macMax = 0;
    myVend *f_ptr = NULL;
    myVend *b_ptr = NULL;
    std::string type;
    //myVend *link;
};
typedef myVend* VendPtr;
//making modification for remote push testing
void school_vend(VendPtr& tempPtr);                             // create a vending machine for use in a school
void office_vend(VendPtr& tempPtr);                             // create a vending machine for use in a work office
//void admin_control(struct myVend macArray, int admin_choice); // Entering Admin Control 
//void admin_control(struct myVend macArray[100]);
void admin_control(VendPtr& head);
void manageMac(VendPtr& head);
void addMac(VendPtr& head);
void editMac(VendPtr& head);
void removeMac(VendPtr& head);
void newOffice(VendPtr& iter);
void newSchool(VendPtr& head);
void processName(VendPtr& temp, int loc);
void user_control(VendPtr& head);                    // Entering User Input Mode
void initializescale();                                       // Limits the decimal values
void initilizesystem();                                       // place holder for creating 
void screenclear();                                           // clear screen for easier UI
void simulatedelay();                                         // allow user to see response before clearing screen
int  check_static(int test);
void naughtyUser();
bool myDebug(VendPtr& head,VendPtr& itr);
void uselessfun1();
void uselessfun1(int num);
void uselessfun2();
void uselessfun3(std::string sen);
void enterDebug(VendPtr& ptr);
void manualOveride(VendPtr& ptr,VendPtr& head);
void testArray(VendPtr& head);
void arrParse(VendPtr& head);
void arrParse(VendPtr& head, int leng, int maxarr);
bool toDel();
void delArr(VendPtr& head, int sel);

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
    }*/
    while(exte){
        std::cout << "Checking something";
        simulatedelay();
        while(exte){
            //myDebug(head,last);
            myDebug(head,head);
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
    simulatedelay();
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
        std::cout << "Which pointer do you want to access?\n"; uselessfun2(); std::cout << "1. Head or \n2. Iter? \n3. Manual Mode \n4. Review Mode \n5. Quit \n6. Exit Program" << std::endl;
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
    } while (picker != 5);
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
void enterDebug(VendPtr& ptr){ // will not be made optimized because it's just meant for ease
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
        std::cout << "1. Manage Machines\n2. # of Machines?\n3. Exit\n";
        std::cout << "Please enter your choice: "<< std::endl;
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
            }
            case 3:
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
    } while (admin_input != 3);
    //admin_input = 0;

}
void manageMac(VendPtr& head){
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
            addMac(head);
            break;
        case 2:
            //editMac(head);
            break;
        case 3:
            removeMac(head);
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
void addMac(VendPtr& head){
    screenclear();
    int test;
    bool exitcond = false;
    VendPtr iter = head;

    do{
        while(iter->f_ptr != NULL)
            iter = iter->f_ptr;
        if (head->macMax == 1)
            head = iter;
        int pickLoc = 0;   
        char morecpic = 'k'; 
        std::cout << "\nIs this for a school or an office?\n";
        std::cout << "1. Office\n2. School\n3. Cancel\n";
        uselessfun1();
        std::cout << "Enter your decision: " << std::endl;
        std::cin >> pickLoc;
        if (pickLoc == 1 || pickLoc == 2)
            head->macMax++;
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
            std::cin >> test;
            std::cout << "That was not a valid input. Please try again.\n";
            naughtyUser();
            break;
        }
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
                else
                    std::cout << "That was not a valid input. Please try again:\n";
            }
        }
        std::cout <<"\nThere are" <<head->macMax;/*
        if(/*(head->name == "blank") && (head->macMax == 1)){
            head = iter;
            std::cout << "\n" <<head->macMax << " should be " << iter->macMax;
            std::cout << "\nLet's compare " << iter->macNum; 
        }*/
        naughtyUser();
        //testArray(head);
    } while ((exitcond == false));
}
void removeMac(VendPtr& head){
    uselessfun1();
    uselessfun2();
    bool del, sel = false;
    int pic = 0, leng, maxarr;
    if(head->macMax < 10)
        leng = 3;
    else
        leng = 5;
    maxarr = head->macMax;
    std::cout << "Opening Machine Removal Features\n";
    for (int ii = 0; ii < 1500; ii++){
        if ((ii == 500) || (ii == 1000))
            std::cout << ". . .\n"; 
    }
    std::cout << "Opening\n";
    for (int ii = 0; ii < 300; ii ++){};
    VendPtr here = head;
    do {
        arrParse(here,leng,maxarr);
        std::cin >> pic;
        /*while (std::cin.fail()){ // I'll try out this type of condition later
            std::cout << "Invalid Input" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> pic;
        }*/
        switch (pic) {
        case 0:
            break;
        case 1:
            del = toDel();
            if (del == true){
                delArr(here,pic);
            }
            break;
        case 2:
            del = toDel();
            if (del == true){
                delArr(here,pic);
            }
            break;
        case 3:
            del = toDel();
            if (del == true){
                delArr(here,pic);
            }
            break;
        case 4:
            if (head->macMax < 10)
                std::cout << "Invalid Choice";
            else
                del = toDel();
            if (del == true){
                delArr(here,pic);
            }
            break;
        case 5:
            if (head->macMax < 10)
                std::cout << "Invalid Choice";
            else 
                del = toDel();
            if (del == true){
                delArr(here,pic);
            }
            break;
        case 6:
            //for(int ii = 0; ii < leng; ii++){
              //  if(here->f_ptr != NULL)
                    here = here->f_ptr;
            //}
            break;
        case 7:
            for(int ii = 0; ii < leng; ii++){
                if(here->b_ptr != NULL)
                    here = here->b_ptr;
            }
            break;
        default:
            std::cout << "That was not a valid Input. Please try again\n";
            break;
        }
    }while(sel == false);
}
void arrParse(VendPtr& head,int leng, int maxarr){
    VendPtr here = head;
    int sel = 0;
    std::string tmparr[maxarr];
    uselessfun1();
    uselessfun2();
    std::cout << "What machine do you want to delete?\n";
    for(int ii = 0; ii < leng; ii++){
    //    tmparr[ii] = ;
        VendPtr check = here->f_ptr;
        if(check != NULL){
            uselessfun2();
            std::cout << "Machine #" <<here->macNum << " " << here->name << " (" << here->tag << ")\n";
            if (ii < leng - 1){
                here = here->f_ptr;
            }
        }
    }
    if(here->f_ptr != NULL)
        uselessfun2();
        std::cout << "6. Move to next " << leng << ".\n";
    if(here->b_ptr != NULL)
        uselessfun2();
        std::cout << "7. Move to previous " << leng << ".\n";
    std::cout << "Enter your decision: ";
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
        }
        else if (loc == 2){
            std::cout << "\nWhat is the name of your school? \n";
            tempP->type = "School";
        }
        //std::cin.ignore();
        do{
            std::getline(std::cin, tempname);
        }while(tempname.empty());
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
        while(confirm != 'y' || confirm != 'Y'){
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
    std::cout << "////////////////////////////////////////////////////////////////////\n\n";
}
void uselessfun1(int num){
    for (int ii = 0; ii < num; ii++){
        std::cout << "////////////////////////////////////////////////////////////////////\n";
    }
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
}*/
//////////////////// my debugger ////////////////////
// std::cout << "I am in []" << std::endl; simulatedelay();
void initializescale(){ // Sets the cout of dollars to 2 decimal points. 
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
    //std::cin.ignore(256,'\n');
    std::cin.get();
}
void testArray(VendPtr& head){
    uselessfun1();
    VendPtr here = head;
    while (here != NULL){
        std::cout << here->macMax << " " << here->macNum << " " << here->name << " " << 
        here->tag << " " << here->bot_ale << "\n";
        here = here->f_ptr;
    }
    simulatedelay();
}
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
void delArr(VendPtr& here, int pic){
    //VendPtr iter = here;
    int ii = 1;
    /*if(pic == 1){

    }*/
    while(ii != pic){
        //iter = iter->f_ptr;
        here = here->f_ptr;
        ii++;
    }
    //VendPtr back = iter, fwd = iter;
    VendPtr back = here, fwd = here;
//    if ((iter->b_ptr != NULL)&&(iter->f_ptr != NULL)){
    if ((here->b_ptr != NULL)&&(here->f_ptr != NULL)){ // best case ; not at end or start
        back = back->b_ptr;
        fwd  =  fwd->f_ptr;
        back->f_ptr =  fwd;
        fwd->b_ptr  = back;
        delete here;
    }/*
    if (iter->b_ptr != NULL){
        back = back->b_ptr;
    }
    else{
        //back->b_ptr = NULL;
    }
    if (iter->f_ptr != NULL){
        fwd = fwd->f_ptr;
    }
    else{
        //fwd->f_ptr = NULL;
    }*/
    else if (here->b_ptr == NULL){
        fwd = fwd->f_ptr;
        fwd->b_ptr = here->b_ptr;
        delete here;
    }
    else if (here->f_ptr == NULL){
        back = back->b_ptr;
        back->f_ptr = here->f_ptr;
        delete here;
    }
    else { // delete everything(?)

    }
}
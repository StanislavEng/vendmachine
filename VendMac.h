/* Vending Machine Class header file
This is a vending machine class that I want to use as part of a User side usage program
and hoping to expand it with a Qt GUI that will use the same class
Eventually I will bring this in to replace the vending machine structure I made in my 
administration software 

TODO: 

Created by: Stanislav Svichkar
First creation: May 4, 2021
Last edited on : May 4, 2021
*/

#ifndef VEND_MAC_H
#define VEND_MAC_H

class VendMac // class definition
{ 
public: // stuff I believe should be visible in a machine
    void print_Price(int Option);  // will print price of item
    void addMac();                 // adds a new machine 
    void removeMac();              // removes machine
private: // stuff I believe belongs behind the scenes
    int bot_coke;  // bottles of pop
    int choco_bar; // quantity of junk food 
    int re_coke;   // how many bottles of pop to restock to
    int re_choc;   // how much junk food to restock
    double usable_bal = 0, gain_val = 0, ini_val = 0; // dealing with money
};

#endif /* VEND_MAC_H */
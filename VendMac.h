/* Vending Machine Class header file
This is a *GENERAL* vending machine class that I want to use as part of a User side usage program
and hoping to expand it with a Qt GUI that will use the same class

Eventually I will bring this in to replace the vending machine structure I made in my 
administration software 

After some consideration, this will probably be a parent class and I will create 
the office and school options as children

TODO: 

Created by: Stanislav Svichkar
First creation: May 4, 2021
Last edited on : May 5, 2021
*/

#ifndef VEND_MAC_H
#define VEND_MAC_H

class VendMac // class definition
{ 
public: // stuff I believe should be visible in a machine
    void print_Price(int Option);  // will print price of item
    void addMac();                 // adds a new machine 
    void removeMac();              // removes machine
    double printPrice();           // prints the price of selected item
private: // stuff I believe belongs behind the scenes
    int bot_coke, bot_ale, bot_sprite;                // bottles of pop (Cola, Ginger Ale, Sprite)
    int choco_bar, gummy_bag, chips, fruit_bag;       // quantity of snacks (chocolate bar, gummy bags, chips and fruit bags) 
    int re_coke, re_ale, re_sprite;                   // how many bottles of pop to restock to
    int re_choc, re_gummy, re_chip, re_fruit;         // how much of the snacks to restock
    double usable_bal = 0, gain_val = 0, ini_val = 0; // dealing with money (change in machine, profit, initial amount)
    double calculateLifetimeProfit();                 // Profit of the machine since inception
    double calculateRestockProfit();                  // Profit since last restock
    double setPrice();                                // sets prices of items (initilization?)
};

#endif /* VEND_MAC_H */
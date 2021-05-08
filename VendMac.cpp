/* Vending Machine Class main file
The main cpp file for working with the Vending Machine class 
Will be the source of all the functions that I move over
Having to remember how to create classes outside of the main file

TODO:

Created by: Stanislav Svichkar
First created: May 4, 2021
Last edited on : May 4, 2021
*/

#include "VendMac.h"
#include <iostream>

int main(void){
    return 0;
}

void VendMac::restock(){ // function to restock the machine and will also call profit functions
    // refill pop
    bot_coke   = re_coke;
    bot_ale    = re_ale;
    bot_sprite = re_sprite;
    // refill snacks
    choco_bar = re_choc;
    chips     = re_chip;
    gummy_bag = re_gummy;
    fruit_bag = re_fruit;
    // calculates profit 
    double gains = calculateRestockProfit();
    std::cout << "Since last restock, the machine made $" << gains << " in profit\n";
}

//double VendMac::calculateLifetimeProfit(double profit){
void VendMac::calculateLifetimeProfit(double profit){ // function to calculate profit since machine was implemented
    //double profit = 0;
    gain_val = gain_val + profit;
    //return gain_val;
}
double VendMac::calculateRestockProfit(){ // profit since the machine was last restocked
    double profit = 0;
    profit = (usable_bal-ini_val);
    calculateLifetimeProfit(profit);
    return profit;
}

void VendMac::defineName(){

}

void VendMac::refillMenu(){
    
}
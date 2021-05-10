/* 


Created by: Stanislav Svichkar
Initial Creation: May 7, 2021
Last edited on: May 7, 2021
*/
#include <iostream>
#include "VendUser.hpp"
#include <string.h>
#include <iomanip>

VendUser::VendUser(std::string location, std::string name)
{
    this->name = name;
    items.push_back("Coke");
    prices.push_back(2.25);
    items.push_back("Ginger Ale");
    prices.push_back(2.00);
    items.push_back("Sprite");
    prices.push_back(2.00);
    items.push_back("Mars Bar");
    prices.push_back(2.00);
    items.push_back("Caramilk"); 
    prices.push_back(2.25);
    items.push_back("Snickers");
    prices.push_back(2.00);
    items.push_back("Gummy Bag");
    prices.push_back(2.25);
    items.push_back("Fruit Bag");
    prices.push_back(2.00);
    items.push_back("Gummy Worm");
    prices.push_back(2.25);
    int loopDown = 0;
    for (int i = 0; i < items.size(); i++){
        if (i/10 > 1)
            loopDown = i/10;
        if ((i - 10*loopDown) < 10)
            keycode.push_back("A"+std::to_string(i));
    }
    listMenu();
}

VendUser::VendUser(){
    name = "test";
    items.push_back("Coke");
    items.push_back("Ginger Ale");
    items.push_back("Sprite");
    items.push_back("Mars Bar"); 
    items.push_back("Caramilk"); 
    items.push_back("Snickers");
    items.push_back("Gummy Bag");
    items.push_back("Fruit Bag");
    items.push_back("Gummy Worm");
    listMenu();
}

void VendUser::listMenu(){
    std::setprecision(2);
    std::cout.precision(2);
    std::cout << "////////////////////////////////////////////////////////\n";
    std::cout << "||||||||| " << name << "'s Vending Machine |||||||||||\n"; 
    std::cout << "////////////////////////////////////////////////////////\n";
    for (int i = 0; i < items.size(); i = i+3){
    //for (std::vector<double>::iterator it = prices.begin(); it != prices.end(); ++it){
        std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
        //std::cout << "||||| " << items[i] << " |||| " << items[i+1] << " |||| " << items[i+2] << " ||||||\n";    
        std::cout << "|||||";
        for (int k = 0; k < 3;k++){
            int namelen = (items[i+k].length());
            if(namelen < 12){
                int usable = 12-namelen;
                int front = usable%2;
                int back = usable/2;
                for(int l = 0; l < (front+back);l++) {std::cout << " ";}
                std::cout << items[i+k];
                for(int l = 0; l < (back);l++) {std::cout << " ";}
            }
            std::cout << "|||||";
        }
        std::cout << "\n";
        std::cout << "|||||     " << keycode[i] << "     |||||     " << keycode[i+1] <<"     |||||     " << keycode[i+2] << "     |||||\n";
        std::cout << std::fixed << "|||||    " << prices[i] << "    |||||    " << prices[i+1] << "    |||||    " << prices[i+2] <<  "    |||||\n";
        std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    }
}
void VendUser::refill(){
    
}
void VendUser::calculateProfit(){
    profit = profit + (balance - change);
    std::cout << "$" << profit << " in profit has been made\n";
}

VendUser::~VendUser()
{
}

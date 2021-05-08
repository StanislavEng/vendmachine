/* 


Created by: Stanislav Svichkar
Initial Creation: May 7, 2021
Last edited on: May 7, 2021
*/
#include <iostream>
#include "VendUser.hpp"
#include <string.h>

VendUser::VendUser(std::string location, std::string name)
{
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
    std::cout << "//////////////////////////////////////////////////////|//\n";
    std::cout << "||||||||| " << name << "'s Vending Machine |||||||||||\n"; 
    std::cout << "//////////////////////////////////////////////////////|//\n";
    std::cout << "|||||  Coca Cola  ||||   Ginger Ale  ||||  Sprite  ||||||\n";
    std::cout << "|||||             ||||               ||||          ||||||\n";
    std::cout << "|||||    $2.25    ||||     $2.00     ||||   $2.00  ||||||\n";
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout << "|||||  Mars Bar   ||||    Snickers   |||| Caramilk ||||||\n";
    std::cout << "|||||             ||||               ||||          ||||||\n";
    std::cout << "|||||    $2.00    ||||     $2.00     ||||   $2.25  ||||||\n";
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    std::cout << "|||||  Gummy Bag  ||||   Fruit Bag   ||||Gummy Worm||||||\n";
    std::cout << "|||||             ||||               ||||          ||||||\n";
    std::cout << "|||||    $2.25    ||||     $2.00     ||||   $2.25  ||||||\n";
    std::cout << "/////////////////////////////////////////////////////////\n";
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

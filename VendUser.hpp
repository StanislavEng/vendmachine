/*

*/

#include <iostream>
#include <string.h>
#include <vector>
//#pragma once 

#ifndef VENDUSER_H
#define VENDUSER_H

class VendUser
{
public:
    /// constructors ///
    VendUser(std::string location, std::string name);
    VendUser();
    /// public functions ///
    void listMenu();
    void refill();
    void calculateProfit();
    /// destructor ///
    ~VendUser();
private:
    /* data */
    ///////////////////////////////////
    double balance, profit, change;  // current balance in machine, lifetime profit, change in machine
    ///////////////////////////////////
    int coke, ale, sprite;
    int mars, caramilk, snickers;
    int gummybag, fruitbag, gummywork;
    ///////////////////////////////////
    int coke_ref, ale_ref, sprite_ref;
    int mars_ref, cara_ref, snick_ref;
    int gumy_ref, frut_ref, worms_ref;
    ///////////////////////////////////
    std::vector<std::string> items;
     
    ///////////////////////////////////
    std::string name;    
};

#endif 
#ifndef DICE_H
#define DICE_H

#include <random>

class Dice {
private:
    std::mt19937 rng; 

public:
    Dice();

    int roll();
};

#endif 

#include "SicboTable.h"
#include "SicBoTable.h"
#include<iostream>

Table::Table() {
    dices = std::vector<Dice>(3);
}

void Table::play() {
    int totalScore = 0;

    for (int i = 0; i < 3; ++i) {
        int face = dices[i].roll();
        totalScore += face;
    }

}
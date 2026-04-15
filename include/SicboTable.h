
#ifndef SICBOTABLE_H
#define SICBOTABLE_H

#include <vector>
#include "Dice.h"

class House {
};

class Player {
};

class RoundRecord {
};

class Table {
private:
    std::vector<Dice> dices;

    House house;

    Player player;

    std::vector<RoundRecord> records;

public:
    Table();

    void play();
};

#endif

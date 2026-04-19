#pragma once
#include "Actor.h"

class House : public Actor {
    double dCommissionRate;
    double dMinBet;
    double dMaxBet;

  public:
    House(double, double, double);

    double getCommissionRate() const;
    double getMinBet() const;
    double getMaxBet() const;

    /* QA: what is `clampBet` ? */
    double clampBet(double) const;
};

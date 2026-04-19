#pragma once
#include "ABettingStrategy.h"

class Paroli : public ABettingStrategy {
  private:
    int consecutiveWins;
    int targetWins;

  public:
    Paroli(double, int);

    Bet calNextBet(BetResult const &) override;
    void reset() override;
};

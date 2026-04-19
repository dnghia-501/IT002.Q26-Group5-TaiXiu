#pragma once

#include "ABettingStrategy.h"

class Fibonacci : public ABettingStrategy {
    int currentIndex;
    int getFibonacciMultiplier(int);

  public:
    Fibonacci(double baseBet);

    Bet calNextBet(BetResult const &) override;
    void reset() override;
};

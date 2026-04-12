#ifndef FIBONACCI_STRATEGY_H
#define FIBONACCI_STRATEGY_H

#include "IBettingStrategy.h"

class FibonacciStrategy : public IBettingStrategy
{
private:
    double baseBet;
    int currentIndex;
    /*
    baseBet: Mức cược gốc (Ví dụ: 10k)
    currentIndex: Vị trí hiện tại trong dãy Fibonacci

    /*
    Hàm phụ trợ để tính hệ số nhân Fibonacci tại vị trí n
    */
    int getFibonacciMultiplier(int n);

public:
    /*
    Constructor
    */
    FibonacciStrategy(double baseBet);

    /*
    Ghi đè các hàm từ giao diện IBettingStrategy
    */
    double calculateNextBetAmount(bool lastBetWon) override;
    int determineBetSide() override;
    void resetStrategy() override;
};

#endif
/*
FIBONACCI_STRATEGY_H
*/
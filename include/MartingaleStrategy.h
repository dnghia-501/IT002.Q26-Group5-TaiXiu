#ifndef MARTINGALE_STRATEGY_H
#define MARTINGALE_STRATEGY_H

#include "IBettingStrategy.h"

class MartingaleStrategy : public IBettingStrategy
{
private:
    double baseBet;
    double currentBet;
    /*
    baseBet: Mức cược gốc ban đầu (Ví dụ: 10k)
    currentBet: Mức cược hiện tại
    */

public:
    /*
    Constructor khởi tạo chiến thuật
    */
    MartingaleStrategy(double baseBet);

    /*
    Ghi đè (override) các hàm bắt buộc từ interface
    */
    double calculateNextBetAmount(bool lastBetWon) override;
    int determineBetSide() override;
    void resetStrategy() override;
};

#endif
/*
MARTINGALE_STRATEGY_H
*/
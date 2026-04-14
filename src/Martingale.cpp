#include "../include/Martingale.h"
#include <cstdlib>

using namespace std;

/*
 * @brief
 * @param
 * @return
 * */
Bet Martingale::calNextBet(BetResult const &preResult) {
    if (preResult == BetResult::Win) {
        dCurrentBet = dBaseBet;
    } else {
        dCurrentBet *= 2;
    }

    BetType side{(rand() % 2 == 0) ? BetType::Xiu : BetType::Tai};

    return Bet{side, dCurrentBet};
}

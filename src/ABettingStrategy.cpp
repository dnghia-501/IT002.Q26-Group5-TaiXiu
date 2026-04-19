#include "../include/ABettingStrategy.h"

/**/
Bet::Bet(BetType t, double a) : type(t), dAmount(a) {}

/**/
ABettingStrategy::ABettingStrategy(double baseBet)
    : dBaseBet(baseBet), dCurrentBet(baseBet) {}

/**/
void ABettingStrategy::reset() { dCurrentBet = dBaseBet; }

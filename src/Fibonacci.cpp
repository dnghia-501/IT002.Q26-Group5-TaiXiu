#include "../include/Fibonacci.h"
#include <cstdlib>

/*
 * @brief
 * @param
 * @return
 * */
int Fibonacci::getFibonacciMultiplier(int n) {
    if (n <= 0)
        return 1;
    if (n == 1)
        return 1;

    int a = 1, b = 1, c = 2;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
/*
 * @brief
 * @param
 * @return
 * */
Bet Fibonacci::calNextBet(BetResult const &prevResult) {
    if (prevResult == BetResult::Win) {
        iCurrentIndex -= 2;
        if (iCurrentIndex < 0) {
            iCurrentIndex = 0;
        }
    } else {
        iCurrentIndex++;
    }
    dCurrentBet = dBaseBet * getFibonacciMultiplier(iCurrentIndex);

    BetType side{(rand() % 2 == 0) ? BetType::Xiu : BetType::Tai};

    return Bet{side, dCurrentBet};
}
/*
 * @brief
 * @param
 * @return
 * */
void Fibonacci::reset() {
    dCurrentBet = dBaseBet;
    iCurrentIndex = 0;
}

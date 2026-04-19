#pragma once

enum class BetType { Tai, Xiu };
enum class BetResult { Win, Lose };

struct Bet {
    Bet(BetType, double);

    BetType type;
    double dAmount;
};

struct ABettingStrategy {
    virtual Bet calNextBet(BetResult const &prevResult) = 0;
    virtual ~ABettingStrategy() = default;

    virtual void reset();

  protected:
    double dBaseBet, dCurrentBet;

    /* QA: public or protected ? */
    ABettingStrategy(double);
};

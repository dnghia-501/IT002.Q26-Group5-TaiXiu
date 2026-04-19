#pragma once

struct Actor {
    virtual ~Actor() = default;

    double getBalance() const;
    /* QA: use `const &` to avoid memory leak ? */
    void setBalance(double amount);
    void updateBalance(double amount);

  protected:
    double dBalance;
};

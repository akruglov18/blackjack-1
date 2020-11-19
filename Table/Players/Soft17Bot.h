#ifndef BLACKJACK_SOFT17BOT_H
#define BLACKJACK_SOFT17BOT_H


#include "Player.h"

class Soft17Bot : public Player
{
public:
    PlayerDecisions GetDecision() override;
    int RequestStartingBet(int minBet) override;
    int RequestInsuranceBet(int maxBet) override;
    void PayInsurance(int amount) override;
    void PayMainBet(int amount) override;
    void Update() override;
};


#endif //BLACKJACK_SOFT17BOT_H

#ifndef BLACKJACK_IPLAYER_H
#define BLACKJACK_IPLAYER_H

#include "Card.h"
#include "Hand.h"

enum PlayerDecisions
{
    Hit,
    Stand
};

class IPlayer
{
public:
    void AcceptCard(Card card);
    bool IsBusted();
    virtual PlayerDecisions GetPlayerDecision(Hand dealerHand, std::vector<IPlayer*> playerHands, int playerIndex) = 0;

    Hand GetHand();

protected:
    Hand _hand;
};

#endif //BLACKJACK_IPLAYER_H

#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include "IPlayer.h"
#include "../Cards/CardShoe.h"


class Dealer : public IPlayer
{
public:
    PlayerDecisions GetPlayerDecision(Hand dealerHand, std::vector<IPlayer*> playerHands, int playerIndex) override;
    void PlayRound(const std::vector<IPlayer*>& players, CardShoe &shoe);

private:
    void DealCard(IPlayer* player, Card& card);
    void RevealCard();
    Hand _hand;
};


#endif //BLACKJACK_DEALER_H

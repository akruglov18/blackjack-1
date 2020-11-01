#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H


#include <vector>
#include "Card.h"

class Hand
{
public:
    std::vector<Card> Cards();
    int GetSum();
private:
    std::vector<Card> _cards;
    int GetCardSoftValue(Card& card);
};


#endif //BLACKJACK_HAND_H

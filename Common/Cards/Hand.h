#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H


#include <vector>
#include <string>
#include "Card.h"

class Dealer;

class Hand
{
    friend Dealer;

public:
    const std::vector<Card>& Cards() const;
    int GetSum() const;
    bool IsNatural() const;
    void AddCard(const Card& card);
    void Reveal();
    void Clear();
    std::string ToString() const;
private:
    int GetHiddenSum() const;
    std::vector<Card> _cards;
};


#endif //BLACKJACK_HAND_H

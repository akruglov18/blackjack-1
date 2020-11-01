#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

enum Ranks
{
    A, _2, _3, _4, _5, _6, _7, _8, _9, _10, J, Q, K
};
enum Suits
{
    Spades, Clubs, Diamonds, Hearts
};

class Card
{
public:
    Card(Ranks rank, Suits suit) : Rank(rank), Suit(suit) {};
    Card(const Card& card) : Card(card.Rank, card.Suit) {};

    Card& operator=(Card const& card);

    const Ranks Rank;
    const Suits Suit;
};


#endif //BLACKJACK_CARD_H

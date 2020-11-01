#include "Card.h"

Card& Card::operator=(const Card &card)
{
    return Card(card.Rank, card.Suit);
}

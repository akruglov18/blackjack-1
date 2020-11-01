#include "Hand.h"

std::vector<Card> Hand::Cards()
{
    return _cards;
}

int Hand::GetSum()
{
    int aceCount = 0;
    int result = 0;
    for (auto &card : _cards)
    {
        result += GetCardSoftValue(card);
        if (card.Rank == Ranks::A)
        {
            aceCount++;
        }
    }
    while (result > 21 && aceCount > 0)
    {
        result -= 10;
        aceCount--;
    }
    return result;
}

int Hand::GetCardSoftValue(Card &card)
{
    int result = 0;
    switch (card.Rank)
    {

        case A:
            result = 11;
            break;
        case _2:
            result = 2;
            break;
        case _3:
            result = 3;
            break;
        case _4:
            result = 4;
            break;
        case _5:
            result = 5;
            break;
        case _6:
            result = 6;
            break;
        case _7:
            result = 7;
            break;
        case _8:
            result = 8;
            break;
        case _9:
            result = 9;
            break;
        case _10:
        case J:
        case Q:
        case K:
            result = 10;
            break;
    }
    return result;
}

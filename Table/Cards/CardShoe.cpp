#include "CardShoe.h"
#include <random>
#include <string>
#include <stdexcept>
#include "Card.h"
#include <algorithm>
#include <random>

Card CardShoe::GetCard()
{
    if (_cards.empty() || _cardIndex)
    {
        throw std::length_error("No cards left in card shoe");
    }
    Card card = _cards.at(_cardIndex++);
}

void CardShoe::Form()
{
    for (int rank = Ranks::A; rank <= Ranks::K; rank++)
    {
        for (int suit = Suits::Spades; suit <= Suits::Hearts; suit++)
        {
            for (int deck = 0; deck < DeckCount; deck++)
            {
                //emplace_back creates the object in-place in the vector itself
                //push_back would create a temporary object and then move it into vector
                _cards.emplace_back(static_cast<Ranks>(rank), static_cast<Suits>(suit));
            }
        }
    }
}

void CardShoe::Shuffle()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::shuffle(_cards.begin(), _cards.end(), mt);
}

CardShoe::CardShoe(int deckCount, int shuffleThreshold) : DeckCount(deckCount), ShuffleThreshold(shuffleThreshold)
{
    _remainingCardCount = _deckCardCount * deckCount;
    _cards = std::vector<Card>();

    Form();
    Shuffle();
}


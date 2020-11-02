#include "Dealer.h"
#include <vector>

PlayerDecisions Dealer::GetPlayerDecision(Hand dealerHand, std::vector<IPlayer*> playerHands, int playerIndex)
{
    if (_hand.GetSum() < 17)
    {
        return PlayerDecisions::Hit;
    }
    else
    {
        return PlayerDecisions::Stand;
    }
}

void Dealer::DealCard(IPlayer* player, Card &card)
{
    player->AcceptCard(card);
}

void Dealer::PlayRound(const std::vector<IPlayer*>& players, CardShoe &shoe)
{
    for (IPlayer* player : players)
    {
        //deal 2 cards to each player
        player->AcceptCard(shoe.DrawCard());
        player->AcceptCard(shoe.DrawCard());
    }
    //deal 2 cards to self - 1 faceup, 1 facedown
    DealCard(this, shoe.DrawCard());
    DealCard(this, shoe.DrawCard(true));
    //process each player's turn
    for (int i = 0; i < players.size(); i++)
    {
        IPlayer* player = players[i];
        while (player->GetHand().GetSum() != 21 && !player->IsBusted())
        {
            PlayerDecisions currentDecision = player->GetPlayerDecision(_hand, players, i);
            if (currentDecision == PlayerDecisions::Stand)
            {
                break;
            }
            else if (currentDecision == PlayerDecisions::Hit)
            {
                DealCard(player, shoe.DrawCard());
            }
        }
    }
    //process dealer's turn
    //reveal the facedown card
    RevealCard();
    //take cards until 17
    while (GetHand().GetSum() != 21 && !IsBusted())
    {
        PlayerDecisions currentDecision = GetPlayerDecision(_hand, players, -1);
        if (currentDecision == PlayerDecisions::Stand)
        {
            break;
        }
        else if (currentDecision == PlayerDecisions::Hit)
        {
            DealCard(this, shoe.DrawCard());
        }
    }
}

void Dealer::RevealCard()
{
    for (int i = 0; i < _hand.Cards().size(); i++)
    {
        Card& card = _hand.Cards()[i];
        card.IsHidden = false;
    }
}

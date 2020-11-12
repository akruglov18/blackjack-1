#include <stdexcept>
#include "Player.h"

void Player::ClearBets()
{
    _bet.Reset();
}

Bet &Player::GetBet()
{
    return _bet;
}

void Player::AssignGameState(GameState* state)
{
    _gameState = state;
}

void Player::Play(ICardDealer* cardDealer)
{
    PlayerDecisions decision;
    while (true)
    {
        if (IsBusted() || _hand.GetSum() == 21)
        {
            break;
        }

        decision = GetDecision();
        if (decision == PlayerDecisions::Hit)
        {
            cardDealer->DealFaceupCard(this);
        }
        else if (decision == PlayerDecisions::Stand)
        {
            break;
        }
        else
        {
            throw std::logic_error("decision not supported");
        }
    }
}

void Player::ClearGameState()
{
    _gameState = nullptr;
}

Bank &Player::GetBank()
{
    return _bank;
}

#include "Soft17Bot.h"

PlayerDecisions Soft17Bot::GetDecision()
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

int Soft17Bot::RequestStartingBet(int minBet)
{
    return minBet;
}

int Soft17Bot::RequestInsuranceBet(int maxBet)
{
    return maxBet;
}

void Soft17Bot::PayInsurance(int amount)
{
    _bank.Deposit(amount);
}

void Soft17Bot::PayMainBet(int amount)
{
    _bank.Deposit(amount);
}

void Soft17Bot::Update()
{

}

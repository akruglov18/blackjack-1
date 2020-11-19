#include <iostream>
#include "Table.h"
#include "ConsolePlayer.h"
#include "Soft17Bot.h"

int main()
{
    Table table(10);
    table.AddPlayer(new Soft17Bot());
    table.AddPlayer(new ConsolePlayer());
    table.PlayGame();
    std::cout << "No more players left, finishing game" << std::endl;
    return 0;
}

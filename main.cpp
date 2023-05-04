#include <iostream>
#include "Table.h"

int main()
{
    int NumPlayers = 8;

    auto* table = new Table(NumPlayers);

    table->DealCards();
    table->DealFlop();

    table->ShowAllHands();
    table->ShowFlop();

    return 0;
}

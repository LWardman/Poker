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

    std::cout << "Deck size before reset: " << table->GetDeckSize() << std::endl;

    table->ResetDeck();

    std::cout << "Deck size after reset: " << table->GetDeckSize() << std::endl;

    std::cout << "Player order before moving blind forward : " << std::endl;
    table->PrintPlayerNumbers();
    table->MoveBlindForward();
    std::cout << "Player order after" << std::endl;
    table->PrintPlayerNumbers();

    return 0;
}

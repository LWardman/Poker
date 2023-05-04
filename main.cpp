#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"
#include "Table.h"

int main()
{
    std::vector<std::string> Ranks =
            {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

    std::vector<std::string> Suits =
            {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};

    Deck deck;
    deck.shuffledeck();

    int NumPlayers = 8;

    auto* table = new Table(NumPlayers, deck);

    table->DealCards();

    table->DealFlop();

    table->ShowAllHands();

    table->ShowFlop();

    return 0;
}

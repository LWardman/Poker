#include <iostream>
#include "Deck.h"
#include "Player.h"
#include <vector>

int main()
{
    std::vector<std::string> Ranks =
            {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

    std::vector<std::string> Suits =
            {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};

    Deck deck;
    deck.shuffledeck();

    int NumPlayers = 8;

    std::vector<Player*> players;

    for (int i = 0; i < NumPlayers; i++)
    {
        Player* player = new Player();
        players.push_back(player);
    }

    Player* flop = new Player();

    for (Player* player : players)
    {
        player->addCard(deck.drawCard());
        player->addCard(deck.drawCard());
    }


    for (int i = 0; i < 5; i++)
    {
        flop->addCard(deck.drawCard());
    }

    for (Player* player : players)
    {
        std::cout << "Player hand value: " << std::endl;
        player->PrintHand();
    }

    std::cout << " " << std::endl;

    std::cout << "Flop value: " << std::endl;
    flop->PrintHand();

    return 0;
}

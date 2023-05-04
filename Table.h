//
// Created by Wardy on 04/05/2023.
//

#ifndef CARDS_TABLE_H
#define CARDS_TABLE_H

#include <utility>
#include "Deck.h"

class Table {
public:
    Table(unsigned int NumPlayers)
    {
        for (int i = 0; i < NumPlayers; i++)
        {
            auto* player = new Player();
            players.push_back(player);
        }

        deck.shuffledeck();
    };

    void DealCards()
    {
        for (Player* player : players)
        {
            player->addCard(deck.drawCard());
            player->addCard(deck.drawCard());
        }
    }

    void DealFlop()
    {
        for (int i = 0; i < 5; i++)
        {
            flop->addCard(deck.drawCard());
        }
    }

    void ShowFlop()
    {
        std::cout << "Flop value: " << std::endl;
        flop->PrintHand();
    }

    void ShowAllHands()
    {
        for (Player* player : players)
        {
            std::cout << "Player hand value: " << std::endl;
            player->PrintHand();
        }
    }


private:
    Deck deck;
    std::vector<Player*> players;
    Player* flop = new Player();
};

#endif //CARDS_TABLE_H

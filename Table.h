//
// Created by Wardy on 04/05/2023.
//

#ifndef CARDS_TABLE_H
#define CARDS_TABLE_H

#include <utility>
#include "Deck.h"
#include "Player.h"

class Table {
public:
    explicit Table(unsigned int NumPlayers)
    {
        for (int i = 0; i < NumPlayers; i++)
        {
            players.push_back(std::make_unique<Player>());
        }

        deck.shuffledeck();
    };

    void DealCards()
    {
        for (const std::unique_ptr<Player>& player : players)
        {
            player->addCard(deck.drawCard());
            player->addCard(deck.drawCard());
        }
    }

    void ReturnPlayerCards()
    {
        for (const std::unique_ptr<Player>& player : players)
        {
            deck.AddCard(player->ReturnCard());
            deck.AddCard(player->ReturnCard());
        }
    }

    void DealFlop()
    {
        for (int i = 0; i < 5; i++)
        {
            flop->addCard(deck.drawCard());
        }
    }

    void ReturnFlop()
    {
        for (int i = 0; i < 5; i++)
        {
            deck.AddCard(flop->ReturnCard());
        }
    }

    void ShowFlop()
    {
        std::cout << "Flop value: " << std::endl;
        flop->PrintHand();
    }

    void ShowAllHands()
    {
        for (const std::unique_ptr<Player>& player : players)
        {
            std::cout << "Player hand value: " << std::endl;
            player->PrintHand();
        }
    }

    int GetDeckSize()
    {
        return deck.GetDeckSize();
    }

    void ResetDeck()
    {
        ReturnPlayerCards();
        ReturnFlop();
    }


private:
    Deck deck;
    std::vector<std::unique_ptr<Player>> players;
    Player* flop = new Player();
};

#endif //CARDS_TABLE_H

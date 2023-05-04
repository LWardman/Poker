//
// Created by Wardy on 03/05/2023.
//

#ifndef CARDS_PLAYER_H
#define CARDS_PLAYER_H

#include <vector>
#include "Deck.h"


class Player {
public:
    void addCard(std::unique_ptr<Card> card) {
        hand_.push_back(std::move(card));
    }

    int getHandValue() const
    {
        int value = 0;
        int aces = 0;
        for (const std::unique_ptr<Card>& card : hand_) {
            int cardValue = card->getRank();
            if (cardValue >= 10) {
                cardValue = 10;
            } else if (cardValue == ACE) {
                aces++;
                cardValue = 11;
            }
            value += cardValue;
        }

        while (value > 21 && aces > 0) {
            value -= 10;
            aces--;
        }
        return value;
    }

    void PrintHand() const
    {
        for (const std::unique_ptr<Card>& card : hand_)
        {
            std::cout << Ranks[card->getRank() - 1] << " OF " << Suits[card->getSuit()] << std::endl;
        }

        std::cout << " " << std::endl;
    }

    void DrawXCards(int X, Deck deck)
    {
        for (int i = 0; i < X; i++)
        {
            addCard(deck.drawCard());
        }
    }


private:
    std::vector<std::unique_ptr<Card>> hand_;

    std::vector<std::string> Ranks =
            {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

    std::vector<std::string> Suits =
            {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};
};


#endif //CARDS_PLAYER_H

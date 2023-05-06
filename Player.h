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

    std::unique_ptr<Card> ReturnCard() {
        if (hand_.empty()) {
            return nullptr;
        }
        std::unique_ptr<Card> card = std::move(hand_.back());
        hand_.pop_back();
        return card;
    }

    void PrintHand() const
    {
        for (const std::unique_ptr<Card>& card : hand_)
        {
            std::cout << Ranks[card->getRank() - 1] << " OF " << Suits[card->getSuit()] << std::endl;
        }

        std::cout << " " << std::endl;
    }

private:
    std::vector<std::unique_ptr<Card>> hand_;

    std::vector<std::string> Ranks =
            {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

    std::vector<std::string> Suits =
            {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};
};


#endif //CARDS_PLAYER_H

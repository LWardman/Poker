//
// Created by Wardy on 03/05/2023.
//

#ifndef CARDS_DECK_H
#define CARDS_DECK_H

#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include "Card.h"

class Deck {
public:
    Deck() {
        for (int suit = HEARTS; suit <= SPADES; ++suit) {
            for (int rank = ACE; rank <= KING; ++rank) {
                deck_.push_back(std::make_unique<Card>(static_cast<Rank>(rank), static_cast<Suit>(suit)));
            }
        }
    }

    void shuffledeck() {
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(deck_.begin(), deck_.end(), g);
    }

    std::unique_ptr<Card> drawCard() {
        if (deck_.empty()) {
            return nullptr;
        }
        std::unique_ptr<Card> card = std::move(deck_.back());
        deck_.pop_back();
        return card;
    }

    void AddCard(std::unique_ptr<Card> card) {
        deck_.push_back(std::move(card));
    }

    int GetDeckSize()
    {
        return deck_.size();
    }



private:
    std::vector<std::unique_ptr<Card> > deck_;
};


#endif //CARDS_DECK_H

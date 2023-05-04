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
                cards_.push_back(std::make_unique<Card>(static_cast<Rank>(rank), static_cast<Suit>(suit)));
            }
        }
    }

    void shuffledeck() {
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(cards_.begin(), cards_.end(), g);
    }

    std::unique_ptr<Card> drawCard() {
        if (cards_.empty()) {
            return nullptr;
        }
        std::unique_ptr<Card> card = std::move(cards_.back());
        cards_.pop_back();
        return card;
    }


private:
    std::vector<std::unique_ptr<Card> > cards_;
};


#endif //CARDS_DECK_H

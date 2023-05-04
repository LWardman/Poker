//
// Created by Wardy on 03/05/2023.
//

#ifndef CARDS_CARD_H
#define CARDS_CARD_H

enum Rank {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum Suit {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

class Card {
public:
    Card(Rank rank, Suit suit) : rank_(rank), suit_(suit) {}

    Rank getRank() const { return rank_; }
    Suit getSuit() const { return suit_; }

private:
    Rank rank_;
    Suit suit_;
};


#endif //CARDS_CARD_H

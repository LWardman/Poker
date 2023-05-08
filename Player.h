//
// Created by Wardy on 03/05/2023.
//

#ifndef CARDS_PLAYER_H
#define CARDS_PLAYER_H

#include <vector>
#include "Deck.h"


class Player {
public:

    explicit Player(int PlayerNum) : PlayerNum_(PlayerNum) {}

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
            std::cout << Ranks[card->GetRank() - 1] << " OF " << Suits[card->GetSuit()] << std::endl;
        }

        std::cout << " " << std::endl;
    }

    bool HandEmpty()
    {
        return hand_.empty();
    }

    [[nodiscard]] unsigned int GetPlayerNumber() const
    {
        return PlayerNum_;
    }

    void Check()
    {

    }

    void Call()
    {

    }

    void Raise()
    {

    }

private:
    std::vector<std::unique_ptr<Card>> hand_;

    unsigned int Chips = 100;

    unsigned int PlayerNum_;

    std::vector<std::string> Ranks =
            {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};

    std::vector<std::string> Suits =
            {"HEARTS", "DIAMONDS", "CLUBS", "SPADES"};
};


#endif //CARDS_PLAYER_H

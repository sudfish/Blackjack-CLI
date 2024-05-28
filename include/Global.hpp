#pragma once

#include <string>
#include <vector>


const int NUMBER_OF_DECKS = 1;

const std::vector<std::string> SUITS = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

const std::vector<std::string> RANKS = {
    "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack", "Queen", "King", "Ace"
};

struct Card{
    std::string suit;
    std::string rank; 
    std::string name;

    Card(std::string suit, std::string rank) : suit(suit), rank(rank) {
        this->name = this->rank + " of " + this->suit;
    }
};

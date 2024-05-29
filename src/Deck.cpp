

#include "Deck.hpp"
#include "Global.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

namespace blackjack {
    Deck::Deck(){
        this->Initialize();
        this->Shuffle();
    }

    void Deck::Print(){
        for(const auto &card : this->cards){
            std::cout << "{" << card.name << "}\n";
        }
    }

    void Deck::Shuffle(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(this->cards.begin(), this->cards.end(), std::default_random_engine(seed));
    }

    Card Deck::DrawCard(){
        Card card = Card("NA", "NA");
        if(!this->cards.empty()){
           card = this->cards.front();
           this->cards.erase(this->cards.begin());
        }
        return card;
    }

    void Deck::Initialize(){
        int deck = 0; 
        while(deck != NUMBER_OF_DECKS){
            for(const auto &suit : SUITS){
                for(const auto &rank : RANKS){
                    Card new_card(suit, rank);
                    cards.push_back(new_card);
                }
            }
            deck++;
        }
    }
}

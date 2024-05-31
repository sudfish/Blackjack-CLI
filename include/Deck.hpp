#pragma once

#include "Global.hpp"
#include <vector>

namespace blackjack {

    class Deck {
        public:
            Deck();

            void Print();
            Card DrawCard();
            std::vector<Card> GetCards();

        private:
            std::vector<Card> cards;

            void Initialize();
            void Shuffle();
    };
}

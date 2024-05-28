#pragma once

#include "Global.hpp"

namespace blackjack {

    class Deck {
        public:
            Deck();

            void Print();
            Card Draw();

        private:
            std::vector<Card> cards;

            void Initialize();
            void Shuffle();
    };
}

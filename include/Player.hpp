#pragma once

#include "Global.hpp"
#include <vector>

namespace blackjack {
    class Player{
        public:
            Player();

            std::vector<Card> hand;
            int points = 0;

            void ReceiveCard(Card &card);
            void CalculatePoints();
            bool HasBust();

        private:
    };
}

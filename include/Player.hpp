#pragma once

#include "Global.hpp"
#include <utility>
#include <vector>

namespace blackjack {
    class Player{
        public:
            Player();

            void ReceiveCard(Card &card);
            void CalculatePoints();
            int GetHardPoints();
            int GetSoftPoints();
            std::vector<Card> GetHand();

        private:
            std::vector<Card> hand;
            std::pair<int, int> points = std::make_pair(0, 0);

            int CalculateHardPoints();
            int CalculateSoftPoints();
            void ClearPoints();
    };
}

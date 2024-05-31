
#pragma once

#include "Global.hpp"
#include <string>
#include <utility>
#include <vector>

namespace blackjack {
    class Dealer{
        public:
            Dealer();

            void ReceiveCard(Card &card);
            void CalculatePoints();
            int GetHardPoints();
            int GetSoftPoints();
            std::vector<Card> GetHand();
            std::string GetStringHand();
            bool HasReachedMax();       // Dealer stands on all 17's
            bool HasBust();

        private:
            std::vector<Card> hand;
            std::pair<int, int> points = std::make_pair(0, 0);

            int CalculateHardPoints();
            int CalculateSoftPoints();
            void ClearPoints();
    };
}

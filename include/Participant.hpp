#pragma once

#include "Global.hpp"
#include <utility>
#include <vector>

namespace blackjack {
    class Participant {
        public:
            Participant();

            void ReceiveCard(Card &card);
            void CalculatePoints();
            bool HasBust();

            int GetHardPoints();
            int GetSoftPoints();
            std::vector<Card> GetHand();
            void ClearPoints();

            void ClearHand();

        protected:
            std::vector<Card> hand;
            std::pair<int, int> points = std::make_pair(0, 0);

            int CalculateHardPoints();
            int CalculateSoftPoints();
    };

    class Player : public Participant {
        public:
            Player();
    };

    class Dealer : public Participant {
        public:
            Dealer();

            std::vector<Card> GetFirstCard();
            bool HasReachedMax();   // Standing on all 17's
    };
}

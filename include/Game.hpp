#pragma once

namespace blackjack {
    class Game{
        public:
            Game();
            ~Game();

            void Run();

        private:
            int dealer_hand = 0;
            int player_hand = 0;

            int dealer_cards = 0;
            int player_cards = 0;

            void DealCards();
            void HandlePlayerTurn();
            void HandleDealerTurn();
            void DetermineWinner();
    };
}

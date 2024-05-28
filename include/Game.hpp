#pragma once

#include "Deck.hpp"
namespace blackjack {
    class Game{
        public:
            Game();
            ~Game();

            void Run();

        private:
            Deck deck;

            void DealCards();
            void HandlePlayerTurn();
            void HandleDealerTurn();
            void DetermineWinner();
            void ResetGame();

            int GetRandomCardValue();
    };
}

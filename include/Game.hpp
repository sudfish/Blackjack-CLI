#pragma once

#include "Deck.hpp"
#include "Player.hpp"
namespace blackjack {
    class Game{
        public:
            Game();
            ~Game();

            void Run();

        private:
            Deck deck;

            Player dealer;
            Player player;

            void DealCards();
            void HandlePlayerTurn();
            void HandleDealerTurn();
            void DetermineWinner();
            void ResetGame();

            int GetRandomCardValue();
    };
}

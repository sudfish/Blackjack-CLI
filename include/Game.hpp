#pragma once

#include "Deck.hpp"
#include "Dealer.hpp"
#include "Player.hpp"
#include <vector>
namespace blackjack {
    class Game{
        public:
            Game();
            ~Game();

            void Run();

        private:
            Deck deck;

            Dealer dealer;
            Player player;

            void DealCards();
            void HandlePlayerTurn();
            void HandleDealerTurn();
            void DetermineWinner();
            void ResetGame();

            void DisplayHand(std::vector<Card> hand);
            void DisplayPoints(int soft, int hard);

            int GetRandomCardValue();
    };
}

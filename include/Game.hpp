#pragma once

#include "Deck.hpp"
#include "Participant.hpp"

#include <vector>
namespace blackjack {
    class Game{
        public:
            Game();
            ~Game();

            void Run();

        private:
            bool running = true;

            Deck deck;

            Dealer dealer;
            Player player;

            void Introduction();
            void ClearTerminal();

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

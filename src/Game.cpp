#include "Game.hpp"
#include <iostream>

namespace blackjack {
    Game::Game(){

    }

    Game::~Game(){

    }

    void Game::Run(){
        this->DealCards();
        this->HandlePlayerTurn();
    }

    void Game::DealCards(){
        while(this->player.GetHand().size() != 2){
            Card player_card = this->deck.DrawCard();
            this->player.ReceiveCard(player_card);
            Card dealer_card = this->deck.DrawCard();
            this->dealer.ReceiveCard(dealer_card);
        }
    }

    void Game::HandlePlayerTurn(){
        int choice = 0;
        while(choice != 2){
            std::cout << "\tPlayer Turn\n";
            std::cout << "\t1. Hit\n";
            std::cout << "\t2. Stand\n";
            std::cin >> choice;
        }
    }

    void Game::HandleDealerTurn(){

    }

    void Game::DetermineWinner(){

    }

    void Game::ResetGame(){

    }
}

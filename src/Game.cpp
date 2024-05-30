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
        this->player.CalculatePoints();
    }

    void Game::HandlePlayerTurn(){
        int choice = 0;
        while(choice != 2 && !this->player.HasBust()){
            std::cout << "\t ===== Player Turn ====== \n";
            std::cout << "\t" << this->player.GetStringHand() << "\n";
            if(this->player.GetSoftPoints() != this->player.GetHardPoints()){
                if(this->player.GetSoftPoints() < 22){
                    std::cout << "\tSoft: " << this->player.GetSoftPoints() << "\n";
                }
                if(this->player.GetHardPoints() < 22){
                    std::cout << "\tHard: " << this->player.GetHardPoints() << "\n";
                }
            } else {
                std::cout << "\t Points: " << this->player.GetHardPoints() << "\n";
            }
            std::cout << "\t1. Hit\n";
            std::cout << "\t2. Stand\n";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    {
                        Card card = this->deck.DrawCard();
                        this->player.ReceiveCard(card);
                        this->player.CalculatePoints();
                    }
                    break;
                case 2:
                    break;
                default:
                    break;
            }
        }
    }

    void Game::HandleDealerTurn(){

    }

    void Game::DetermineWinner(){

    }

    void Game::ResetGame(){

    }
}

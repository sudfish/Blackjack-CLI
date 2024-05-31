#include "Game.hpp"
#include <algorithm>
#include <iostream>

namespace blackjack {
    Game::Game(){

    }

    Game::~Game(){

    }

    void Game::Run(){
        this->DealCards();
        this->HandlePlayerTurn();
        this->HandleDealerTurn();
        this->DetermineWinner();
    }

    void Game::DealCards(){
        while(this->player.GetHand().size() != 2){
            Card player_card = this->deck.DrawCard();
            this->player.ReceiveCard(player_card);
            Card dealer_card = this->deck.DrawCard();
            this->dealer.ReceiveCard(dealer_card);
        }
        this->player.CalculatePoints();
        this->dealer.CalculatePoints();
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
        std::cout << "\t===== Dealer Turn =====\n";
        std::cout << "\t" << this->dealer.GetStringHand() << "\n";
        if(this->dealer.GetSoftPoints() != this->dealer.GetHardPoints()){
            if(this->dealer.GetSoftPoints() < 22){
                std::cout << "\tSoft: " << this->dealer.GetSoftPoints() << "\n";
            }
            if(this->dealer.GetHardPoints() < 22){
                std::cout << "\tHard: " << this->dealer.GetHardPoints() << "\n";
            }
        } else {
            std::cout << "\t Points: " << this->dealer.GetHardPoints() << "\n";
        }

        while(!this->dealer.HasReachedMax()){
            std::cout << "\t===== Dealer Turn =====\n";
            std::cout << "\t DEALER GETS ANOTHER CARD\n";
            Card card = this->deck.DrawCard();
            this->dealer.ReceiveCard(card);
            this->dealer.CalculatePoints();
            std::cout << "\t" << this->dealer.GetStringHand() << "\n";
            if(this->dealer.GetSoftPoints() != this->dealer.GetHardPoints()){
                if(this->dealer.GetSoftPoints() < 22){
                    std::cout << "\tSoft: " << this->dealer.GetSoftPoints() << "\n";
                }
                if(this->dealer.GetHardPoints() < 22){
                    std::cout << "\tHard: " << this->dealer.GetHardPoints() << "\n";
                }
            } else {
                std::cout << "\t Points: " << this->dealer.GetHardPoints() << "\n";
            }
        }
    }

    void Game::DetermineWinner(){
        int max_player_points = std::max(this->player.GetSoftPoints(), this->player.GetHardPoints());
        int max_dealer_points = std::max(this->dealer.GetSoftPoints(), this->dealer.GetHardPoints());
        std::cout << "\n\tMax Player Points: " << max_player_points << "\n";
        std::cout << "\n\tMax Dealer Points: " << max_dealer_points << "\n";
        if(this->player.HasBust()){
            std::cout << "\n\tDEALER WINS!\n\n";
        } else if (this->dealer.HasBust()) {
            std::cout << "\n\tPLAYER WINS!\n\n"; 
        } else{
            if(max_player_points > max_dealer_points){
                std::cout << "\n\tPLAYER WINS!\n\n";
            } else if (max_dealer_points > max_player_points){
                std::cout << "\n\tDEALER WINS!\n\n";
            } else {
                std::cout << "\n\tPUSH - NOBODY WINS!\n\n";
            }
        }
    }

    void Game::ResetGame(){

    }
}

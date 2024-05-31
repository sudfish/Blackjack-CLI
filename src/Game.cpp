#include "Game.hpp"
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

namespace blackjack {
    Game::Game(){
        this->ClearTerminal();
        this->Introduction();
    }

    Game::~Game(){}

    void Game::Introduction(){
        std::cout << "\n\n\n"; 
        std::cout << "\t==================================" << std::endl;
        std::cout << "\t         Welcome to Blackjack!    " << std::endl;
        std::cout << "\t==================================" << std::endl;
        std::cout << "\tTest your luck and skill!" << std::endl;
        std::cout << std::endl;
    } 

    void Game::ClearTerminal(){
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    void Game::Run(){
        while (this->running) {
            // if(this->deck.GetCards().size() < 20){
            //     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            //     std::shuffle(this->bin.begin(), this->bin.end(), std::default_random_engine(seed));
            //     this->deck.GetCards().insert(
            //         this->deck.GetCards().end(),
            //         this->bin.begin(),
            //         this->bin.end()
            //     );
            //     this->bin.clear();
            // }
            std::cout << "\n\tDeck Size: ";
            std::cout << this->deck.GetCards().size();
            this->DealCards();
            this->HandlePlayerTurn();
            this->HandleDealerTurn();
            this->DetermineWinner();
            this->ResetGame();
            this->ClearTerminal();
            this->DisplayHand(this->bin);
        }
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

        std::cout << "\n\tCards have been dealt.\n\n";

        std::cout << "\tDealer: \n";
        this->DisplayHand(this->dealer.GetFirstCard());

        std::cout << "\tPlayer: \n";
        this->DisplayHand(this->player.GetHand());
    }

    void Game::HandlePlayerTurn(){
        std::cout << "\n\t===== Player Turn ====== \n";

        this->DisplayHand(this->player.GetHand());
        this->DisplayPoints(this->player.GetSoftPoints(), this->player.GetHardPoints());

        if(this->player.HasBlackJack()){
            std::cout << "\n\t#!#!#! BLACK JACK !#!#!#\n\n";
            return;
        }

        int choice = 0;
        while(choice != 2 && !this->player.HasBust()){

            std::cout << "\t1. Hit\n";
            std::cout << "\t2. Stand\n";
            std::cout << "\n\tChoice: ";
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

            this->DisplayHand(this->player.GetHand());
            this->DisplayPoints(this->player.GetSoftPoints(), this->player.GetHardPoints());
        }
    }

    void Game::HandleDealerTurn(){
        std::cout << "\n\t===== Dealer Turn =====\n";

        this->DisplayHand(this->dealer.GetHand());
        this->DisplayPoints(this->dealer.GetSoftPoints(), this->dealer.GetHardPoints());

        while(!this->dealer.HasReachedMax()){
            std::cout << "\t===== Dealer Turn =====\n";
            std::cout << "\t~~ DEALER GETS ANOTHER CARD ~~\n";
            Card card = this->deck.DrawCard();
            this->dealer.ReceiveCard(card);
            this->dealer.CalculatePoints();
            this->DisplayHand(this->dealer.GetHand());
            this->DisplayPoints(this->dealer.GetSoftPoints(), this->dealer.GetHardPoints());
        }
    }

    void Game::DetermineWinner(){
        if(this->player.HasBust()){
            std::cout << "\n\tPlayer busted. Dealer wins!\n\n";
        } else if (this->dealer.HasBust()) {
            std::cout << "\n\tDealer busted. Player wins!\n\n"; 
        } else{
            int player_hard = this->player.GetHardPoints() > 21 ? 0 : this->player.GetHardPoints();
            int player_soft = this->player.GetSoftPoints() > 21 ? 0 : this->player.GetSoftPoints();
            int max_player_points = std::max(player_soft, player_hard);

            int dealer_hard = this->dealer.GetHardPoints() > 21 ? 0 : this->dealer.GetHardPoints();
            int dealer_soft = this->dealer.GetSoftPoints() > 21 ? 0 : this->dealer.GetSoftPoints();
            int max_dealer_points = std::max(dealer_soft, dealer_hard);

            std::cout << "\tPlayer Points: " << max_player_points << "\n";
            std::cout << "\tDealer Points: " << max_dealer_points << "\n";
            if(max_player_points > max_dealer_points){
                std::cout << "\n\tPlayer wins!\n\n";
            } else if (max_dealer_points > max_player_points){
                std::cout << "\n\tDealer wins!\n\n";
            } else {
                std::cout << "\n\tPush - Nobody wins.\n\n";
            }
        }
    }

    void Game::ResetGame(){
        std::string in;
        std::cout << "\n\tWould you like to play again? (y/n): ";
        std::cin >> in;
        this->running = in == "y" ? true : false;

        this->player.ClearPoints(); 
        std::vector<Card> player_hand = this->player.ClearHand();
        this->dealer.ClearPoints();
        std::vector<Card> dealer_hand = this->dealer.ClearHand();

        this->bin.insert(this->bin.end(), player_hand.begin(), player_hand.end());
        this->bin.insert(this->bin.end(), dealer_hand.begin(), dealer_hand.end());
    }

    void Game::DisplayHand(std::vector<Card> hand){
        std::stringstream ss;
        ss << "\tCards: \n";
        for (size_t i = 0; i < hand.size(); ++i) {
            ss << "\t\t{" << hand[i].name << "}\n";
        }
        ss << "\n";
        std::cout << ss.str();
    }

    void Game::DisplayPoints(int soft, int hard){
        std::stringstream ss;
        ss << "\tPoints: ";
        if(soft != hard){
            if(soft < 22 && hard < 22){
                ss << soft << " OR " << hard;
            } else {
                if(soft < 22) ss << soft;
                if(hard < 22) ss << hard;
            }
        } else ss << hard;
        
        ss << "\n\n";
        std::cout << ss.str();
    }
}

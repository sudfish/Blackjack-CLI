#include "Game.hpp"

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
        
    }

    void Game::HandlePlayerTurn(){

    }

    void Game::HandleDealerTurn(){

    }

    void Game::DetermineWinner(){

    }
}

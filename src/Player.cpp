#include "Player.hpp"

namespace blackjack {
    Player::Player(){}

    void Player::ReceiveCard(Card &card){
        this->hand.push_back(card);
    }

    void CalculatePoints(){
        int total;
    }

    bool Player::HasBust(){
        return points > 21;
    }
}

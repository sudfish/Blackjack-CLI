#include "Player.hpp"
#include "Global.hpp"
#include <sstream>
#include <string>
#include <vector>

namespace blackjack {
    Player::Player(){}

    void Player::ReceiveCard(Card &card){
        this->hand.push_back(card);
    }

    void Player::CalculatePoints(){
        this->points.first = this->CalculateSoftPoints();
        this->points.second = this->CalculateHardPoints();
    }

    int Player::GetHardPoints(){
        return this->points.second;
    }

    int Player::GetSoftPoints(){
        return this->points.first;
    }

    bool Player::HasBust(){
        return this->points.first > 21 && this->points.second > 21;
    }

    std::vector<Card> Player::GetHand(){
        return this->hand;
    }

    std::string Player::GetStringHand(){
        std::stringstream ss;
        for (size_t i = 0; i < this->hand.size(); ++i) {
            ss << hand[i].name;
            if (i != hand.size() - 1) {
                ss << ", ";
            }
        }
        return ss.str();
    }

    int Player::CalculateHardPoints(){
        int hard_points = 0;
        for(const auto& card : this->hand){
            if(card.rank == "Ace") hard_points++;
            else hard_points += RANK_TO_NUMBER.at(card.rank);
        }

        return hard_points;
    }

    int Player::CalculateSoftPoints(){
        int soft_points = 0; int aces = 0;
        for(const auto& card : this->hand){
            if(card.rank == "Ace") {soft_points++; aces++;}
            else soft_points += RANK_TO_NUMBER.at(card.rank);
        }

        if(aces > 0) soft_points += 10;
        return soft_points;
    }
    
    void Player::ClearPoints(){
        this->points.first = 0;
        this->points.second = 0;
    }
}

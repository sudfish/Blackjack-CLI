#include "Participant.hpp"
#include <vector>

namespace blackjack {
    Participant::Participant(){}

    void Participant::ReceiveCard(Card &card){
        this->hand.push_back(card);
    }

    void Participant::CalculatePoints(){
        this->points.first = this->CalculateSoftPoints();
        this->points.second = this->CalculateHardPoints();
    }

    bool Participant::HasBust(){
        return this->points.first > 21 && this->points.second > 21;
    }

    int Participant::GetHardPoints(){
        return this->points.second;
    }

    int Participant::GetSoftPoints(){
        return this->points.first;
    }

    std::vector<Card> Participant::GetHand(){
        return this->hand;
    }

    void Participant::ClearPoints(){
        this->points.first = 0;
        this->points.second = 0;
    }

    std::vector<Card> Participant::ClearHand(){
        std::vector<Card> vec;
        vec = this->hand;
        this->hand.clear();
        return vec;
    }

    int Participant::CalculateHardPoints(){
        int hard_points = 0;
        for(const auto& card : this->hand){
            if(card.rank == "Ace") hard_points++;
            else hard_points += RANK_TO_NUMBER.at(card.rank);
        }

        return hard_points;
    }

    int Participant::CalculateSoftPoints(){
        int soft_points = 0; int aces = 0;
        for(const auto& card : this->hand){
            if(card.rank == "Ace") {soft_points++; aces++;}
            else soft_points += RANK_TO_NUMBER.at(card.rank);
        }

        if(aces > 0) soft_points += 10;
        return soft_points;
    }

    // ===== PLAYER =====

    Player::Player(){}

    bool Player::HasBlackJack(){
        return this->GetSoftPoints() == 21; 
    }

    // ===== DEALER =====

    Dealer::Dealer(){}

    std::vector<Card> Dealer::GetFirstCard(){
        std::vector<Card> vec;
        vec.push_back(this->hand[0]);
        return vec;
    }

    bool Dealer::HasReachedMax(){
        return this->points.first > 17 || this->points.second > 17;
    }
}

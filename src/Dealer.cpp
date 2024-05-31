
#include "Dealer.hpp"
#include "Global.hpp"
#include <sstream>
#include <string>
#include <vector>

namespace blackjack {
    Dealer::Dealer(){}

    void Dealer::ReceiveCard(Card &card){
        this->hand.push_back(card);
    }

    void Dealer::CalculatePoints(){
        this->points.first = this->CalculateSoftPoints();
        this->points.second = this->CalculateHardPoints();
    }

    int Dealer::GetHardPoints(){
        return this->points.second;
    }

    int Dealer::GetSoftPoints(){
        return this->points.first;
    }

    bool Dealer::HasReachedMax(){
        return this->points.first > 17 || this->points.second > 17;
    }

    bool Dealer::HasBust(){
        return this->points.first > 21 && this->points.second > 21;
    }

    std::vector<Card> Dealer::GetHand(){
        return this->hand;
    }


    int Dealer::CalculateHardPoints(){
        int hard_points = 0;
        for(const auto& card : this->hand){
            if(card.rank == "Ace") hard_points++;
            else hard_points += RANK_TO_NUMBER.at(card.rank);
        }

        return hard_points;
    }

    int Dealer::CalculateSoftPoints(){
        int soft_points = 0; int aces = 0;
        for(const auto& card : this->hand){
            if(card.rank == "Ace") {soft_points++; aces++;}
            else soft_points += RANK_TO_NUMBER.at(card.rank);
        }

        if(aces > 0) soft_points += 10;
        return soft_points;
    }
    
    void Dealer::ClearPoints(){
        this->points.first = 0;
        this->points.second = 0;
    }
}

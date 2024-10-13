#include "Card.h"

unsigned short Card::rangs[9] = {6, 7, 8, 9, 10, 11, 12, 13, 14};
std::string Card::suits[4] = {"d", "h", "c", "s"};

Card::Card(){
    rang = 0;
    suit = "";
}

Card::Card(unsigned short _rang, std::string _suit) : rang(_rang), suit(_suit){
}

/* bool Card::operator==(const Card &card){
    return (rang == card.rang and suit == card.suit);
} */

bool Card::operator>(const Card &card){
    if (suit == card.suit){
        return (rang > card.rang);
    }
    else{
        return false;
    }
}

bool Card::operator<(const Card &card){
    if (suit == card.suit){
        return (rang < card.rang);
    }
    else{
        return false;
    };
}

Card::~Card(){
}


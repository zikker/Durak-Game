#include "Card.h"

Card::Card(){
    rang = 0;
    suit = "";
}

Card::Card(unsigned short _rang, std::string _suit) : rang(_rang), suit(_suit){
}

Card::~Card(){
}
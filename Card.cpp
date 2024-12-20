#include "Card.h"

unsigned short Card::rangs[9] = {6, 7, 8, 9, 10, 11, 12, 13, 14};
std::string Card::suits[4] = {"d", "h", "c", "s"};
std::string Card::trump_suit = "";
Card::Card(){
    rang = 0;
    suit = "";
}

Card::Card(unsigned short _rang, std::string _suit) : rang(_rang), suit(_suit){
}

Card::Card(std::string str){
    char tmp = str.back();
    if(tmp == ' '){
        str = str.substr(0, str.length() - 1);
    }
    else if(tmp != 'd' and tmp != 'h' and tmp != 'c' and tmp != 's'){
        throw std::logic_error("Invalid card");
    }
    if(str.length() > 3 or str.length() < 2){
        throw std::logic_error("Invalid card");
    }
    suit = str.back();
    str = str.substr(0, str.length() - 1);

    if(isalpha(str[0])){
        switch (str[0])
        {
        case 'J':
            rang = 11;
            break;
        case 'Q':
            rang = 12;
            break;
        case 'K':
            rang = 13;
            break;
        case 'A':
            rang = 14;   
            break;
        default:
            throw std::logic_error("Invalid card");
            break;
        }
    }
    else{
        int temp = stoi(str);
        if(temp > 10 or tmp < 6){
             throw std::logic_error("Invalid card");
        }
        else{
            rang = temp;
        }
    }
    

}

bool Card::operator>(const Card &card){
    if (suit == card.suit){
        return (rang > card.rang);
    }
    else if (suit == trump_suit){
        if(card.suit != trump_suit){
            return true;
        }
    }
    else{
        return false;
    }
}
/*
bool Card::operator<(const Card &card){
    if (suit == card.suit){
        return (rang < card.rang);
    }
    else{
        return false;
    };
} */

bool Card::operator==(const Card &card){
    return (suit == card.suit and rang == card.rang);
}

void Card::print_card(){
    switch (rang)
        {
        case 11:
            std::cout << "J";
            break;
        case 12:
            std::cout << "Q";
            break;
        case 13:
            std::cout << "K";
            break;
        case 14:
            std::cout << "A";   
            break;
        default:
            std::cout << rang;
            break;
        }
        std::cout << suit << ' ' << std::endl;
}

Card::~Card(){
}


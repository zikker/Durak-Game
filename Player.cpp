#include "Player.h"


Player::Player(Deck &deck){
    for(current_cards = 1; current_cards <= MAX_CARDS; current_cards++){
        cards.push_back(deck.front_card());
    }
}

Card Player::throw_card(string str_cards){
    try
    {
        Card card(str_cards);
        if(find(cards.begin(), cards.end(), card) == end(cards)){
            cout << "Invalid card" << endl;
            return Card();
        }
        else{
            current_cards--;
            return card;
        }
    }
    catch(const std::logic_error &e)
    {
        std::cout << e.what() << '\n';
        return Card();
    }
    

}

void Player::print_cards(){
    for(auto card : cards){
        switch (card.rang)
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
            std::cout << card.rang;
            break;
        }
        std::cout << card.suit << ' '; 
    }
    cout << endl;
}


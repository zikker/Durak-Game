#include "Player.h"

vector<int> Player::valid_rangs = vector<int>();

Player::Player(Deck &deck){
    for(current_cards = 1; current_cards <= MAX_CARDS; current_cards++){
        cards.push_back(deck.front_card());
    }
    last_bitted_card = -1;
}

void Player::throw_card(vector<Card> &cards_to_attack){
    print_cards();
    std::cout << "Enter card to attack (format: 6d). To stop enter 'pass'" << endl;
    string str_cards;
    
    do
    {
        cin >> str_cards;
        try
        {        
            Card card(str_cards);
            auto finded_card = find(cards.begin(), cards.end(), card);
            if(finded_card == end(cards)){
                throw std::logic_error("Invalid card");
            }
            else{
                if(find(valid_rangs.begin(), valid_rangs.end(), card.rang) != end(valid_rangs) or cards_to_attack.size() == 0){
                    cards.erase(finded_card);
                    current_cards--;
                    print_cards();
                }
                else{
                    throw std::logic_error("Invalid card");
                }
                
            }
                valid_rangs.push_back(card.rang);
                cards_to_attack.push_back(card);
        }
        catch(const std::logic_error& e)
        {
            std::cout << e.what() << '\n';
        }
    } 
    while (str_cards != string("pass") and cards_to_attack.size() != 6);
    std::cout << "Your move is end" << endl;
    return;
}

void Player::beat_card(vector<Card> &cards_to_attack){
    string temp_str;
    vector<Card> cards_in_defense;
    int i = 0;
    for(i = last_bitted_card + 1; i < cards_to_attack.size(); i++){
        cout << "your cards: ";
        print_cards();
        Card card_to_beat = cards_to_attack[i];
        cout << "Card you need to beat: ";
        card_to_beat.print_card();
        cout << "Enter your card. (to take card enter 'take')" << endl;
        cin >> temp_str;
        if(temp_str == "take"){
            take_cards(cards_to_attack, cards_in_defense);
            return;
        }
        try
        {
            Card your_card(temp_str);
            auto finded_card = find(cards.begin(), cards.end(), your_card);
            if(finded_card == end(cards)){
                throw std::logic_error("Invalid card");
            }
            else{
                if(!(your_card > card_to_beat)){
                    throw std::logic_error("Invalid card");
                }
                else{
                    cards_in_defense.push_back(your_card);
                    Player::valid_rangs.push_back(your_card.rang);
                    cards.erase(finded_card);
                    current_cards--;
                    last_bitted_card++;
                    print_cards();
                    continue;
                }
            }
        }
        catch(const std::logic_error& e)
        {
            std::cout << e.what() << '\n';
            i--;
        }
    }
}

void Player::take_cards(vector<Card> &cards_to_attack, vector<Card> &cards_in_defense){
    for(auto card : cards_to_attack){
        cards.push_back(card);
    }
    for(auto card : cards_in_defense){
        cards.push_back(card);
    }
    last_bitted_card = -1;
    cards_to_attack.clear();
    cards_in_defense.clear();
    valid_rangs.clear();
    print_cards();

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


#include "Game.h"
Game::Game(int k_players){
    cards_to_attack = {};
    pointer_to_player = 0;
    this->k_players = k_players;
    for(int i = 0; i < k_players; i++){
        Player player(deck);
        players.push_back(player);
    }
    trump = deck.back_card();
    move();

}

bool Game::end_game(){
    return (players.size() == 1);
}

// 0 1 2 3
// 1 2 3 4
void Game::move(){
    cout << "trump card = ";
    trump.print_card();
    Player *activePlayer = &players[pointer_to_player];
    Player *defendingPlayer = &players[(pointer_to_player + 1) % k_players];
    cout << "Move of Player " << pointer_to_player + 1 << endl;
    (*activePlayer).throw_card(cards_to_attack);
    cout << "Defend of Player " << pointer_to_player + 2 << endl;
    (*defendingPlayer).beat_card(cards_to_attack);
    for (int i = (pointer_to_player + 2) % k_players; i != pointer_to_player + 1; i = (i + 1) % k_players){
        cout << "Player " << i + 1 << " fixing with cards" << endl;
        players[i].throw_card(cards_to_attack);
    }
    cout << "Defend of Player " << pointer_to_player + 2 << endl;
    (*defendingPlayer).beat_card(cards_to_attack);
    
    



}

 



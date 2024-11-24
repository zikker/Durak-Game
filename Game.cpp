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

void Game::move(){
    Player activePlayer = players[pointer_to_player];
    cout << "Cards of Player " << pointer_to_player + 1 << endl;
    activePlayer.print_cards();
    cout << "Enter cards to attack (format: 6d6s6h)" << endl;
    string str_cards;
    cin  >> str_cards;
    activePlayer.throw_card(str_cards);



}

 



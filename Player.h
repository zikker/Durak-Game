#include "Deck.h"
using namespace std;
class Player{
public:
    const unsigned MAX_CARDS = 6;
    short current_cards;
    Player(Deck &deck);
    void take_cards();
    void beat_card(Card enemy_card, Card your_card);
    Card throw_card(string str_cards);
    void print_cards();
private:
    vector<Card> cards;
};
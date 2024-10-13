#include "Deck.h"
using namespace std;
class Player{
public:
    const unsigned MAX_CARDS = 6;
    short current_cards;
    Player(Deck deck);
    void take_cards();
    void beat_card(Card enemy_card, Card your_card);
    void throw_card(Card card);
private:
    vector<Card> cards;
};
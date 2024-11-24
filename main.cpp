#include "Game.h"

using namespace std;
int main(){
    while(true){
        try
        {
            string s;
            cin >> s;
            Card card(s);
            cout << card.rang << card.suit << endl;
        }
        catch(const std::logic_error &e)
        {
            std::cout << e.what() << '\n';
        }
    }
}
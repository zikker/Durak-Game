#include <iostream>
#include "Card.h"

using namespace std;
int main(){
    Card A = {1, "A"};
    Card B;
    Card C = {4, "F"};
    cout << A.rang << " " << A.suit << "\t" << B.rang << " " << B.suit << "\n";

}
#include <iostream>
#include "Card.h"

using namespace std;
int main(){
    Card A = {2, "A"};
    Card B(5, "A");
    Card C = {4, "F"};
    cout << (A > B);

}
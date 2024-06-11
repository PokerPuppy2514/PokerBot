//player class, has name and hand(two cards)
using namespace std;
#include <string>

#include "card.h"

class Player{
    public:
        Player();
        //Player(string name, Card card1, Card card2);

        //string printPlayer();

    private:
        string name;
        Card card1;
        Card card2;
};

//default constructor
Player::Player(){
    name = "NULL name";
    card1; //creates empty cards
    card2;
}

// Player::Player(string n, Card c1, Card c2){
//     name = n;
//     card1 = c1;
//     card2 = c2;

// }


// string Player::printPlayer(){
//     return "Player " + name + "has the " + card1.getValue() + " of " + card1.getSuit() + " and the " + card2.getValue() + " of " + card2.getSuit();
//     //return "Player " + name + " has the" + card1.showCard() + " and the " + card2.showCard();
// }

#include <iostream> 
#include<iterator>
#include <vector> 
#include <string>
#include <algorithm>
#include <ctime>     
#include <bits/stdc++.h>

#include "card.h"
#include "player.h"
using namespace std; 

/*
TODO: 
figure out how to remove specific cards and choose cards for player(should be in main method)
MAYBE? figure out how to remove cards through pass by reference(so you can permenantly remove cards and such)
*/


//function prototypes
int randomfunc(int);
vector<Card> createDeck();
vector<Card> shuffle(vector<Card>);
vector<Card> draw(vector<Card>);
string calcPair(Player mainPlayer, vector<Card> &currentDeck);
void  removeSpecificCard(Card, vector<Card>&);

int main(){
    //create and shuffle deck
    vector<Card> deck = shuffle(createDeck());

    //create vector of players
    vector<Player> playerList;

    // //print deck
    // for (auto& card : deck) {
    //    cout << card.showCard() + "\n";
    // }

    // //create null player
    // Player();
    // playerList.push_back(Player());

    playerList.push_back(Player("Beyn", Card("Hearts", "2"), Card("Spades", "7")));

    //remove 2 and seven
    removeSpecificCard(playerList[0].getCard1(), deck);
    removeSpecificCard(playerList[0].getCard2(), deck);



    
    //print playerlist
    for (auto& player : playerList) {
        cout << player.printPlayer() + "\n";
    }
    
    //test for pair(references first element in playerlist)
    cout << calcPair(playerList[0], deck);
    
};

// random generator function seed //randomizes based on time of compilation
int randomfunc(int j) { 
    return rand() % j; 
} 

vector<Card> createDeck(){
    vector<Card> currentDeck;
    vector<string> suits;
    suits = {"Hearts", "Diamonds", "Spades", "Clubs"};
    for(int x = 0; x < suits.size(); x++){
        for(int i = 1; i < 14; i ++){
            if(i == 1) currentDeck.push_back(Card(suits[x], "Ace")); //ace

            else if(i == 11)currentDeck.push_back(Card(suits[x], "Jack")); //jack

            else if(i == 12)currentDeck.push_back(Card(suits[x], "Queen")); //queen

            else if(i == 13)currentDeck.push_back(Card(suits[x], "King")); //king

            else {
                currentDeck.push_back(Card(suits[x], to_string(i))); //adds a heart card from Ace to King (puts i to a char)
            }
        }
    }
    return currentDeck;
}

//randomly shuffles deck
vector<Card> shuffle(vector<Card> d){
    //shuffle method
    srand(unsigned(time(0))); 
  
    // using built-in random generator 
    random_shuffle(d.begin(), d.end()); 
  
    // using randomfunc 
    random_shuffle(d.begin(), d.end(), randomfunc); 

    return d;
}

//remove top card
vector<Card> draw(vector<Card> d){
    d.erase(d.begin());
    return d;
}


//calculate chances of a pair using cucrent deck and currnct hand (PASS DECK BY REFERENCE TO MAKE ANY NEVESSARY CHANGES TO IT(removals))
string calcPair(Player mainPlayer, vector<Card> &currentDeck){
    //ecounter for useful cards
    int count = 0;

    for(Card currentCard : currentDeck){
        //error message if matches suit AND VALUE and handles accordingly
        if(currentCard == mainPlayer.getCard1() || currentCard == mainPlayer.getCard2()){
            cout << "uh oh duplicate cards that wacky" << endl;
        }

        //matches by value
        else if(currentCard.getValue() == mainPlayer.getCard1().getValue() || currentCard.getValue() == mainPlayer.getCard2().getValue()){
            cout << "card found" << endl;
            count++;
        }
    }

    double d = static_cast<double>(count);
    double deckSize = static_cast<double>(currentDeck.size());

    double answer = (d / 50.0) * 100;
    return to_string(answer) + "% chance to get a pair"; //returns a percentage

}


//erases specific card from deck.
void removeSpecificCard(Card badCard, vector<Card>& badDeck){
    //iterator to erase
    auto iterator = find(badDeck.begin(), badDeck.end(), badCard);

    // If element is found found, erase it 
    if (iterator != badDeck.end()) { 
        badDeck.erase(iterator); 
    } 

    cout << "removed " + badCard.showCard() + " from deck" << endl;
}


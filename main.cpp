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
figure out how to calc trips
*/


//function prototypes
int randomfunc(int);
vector<Card> createDeck();
vector<Card> shuffle(vector<Card>);
vector<Card> draw(vector<Card>);
string calcPair(Player mainPlayer, vector<Card> &currentDeck);
string calcTrip(Player mainPlayer, vector<Card> &currentDeck);
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

    //loop to find outs
    for(Card currentCard : currentDeck){
        //error message if matches suit AND VALUE and handles accordingly
        if(currentCard == mainPlayer.getCard1() || currentCard == mainPlayer.getCard2()){
            cout << "uh oh duplicate cards that wacky" << endl;
        }

        //matches by value
        else if(currentCard.getValue() == mainPlayer.getCard1().getValue() || currentCard.getValue() == mainPlayer.getCard2().getValue()){
            //cout << "card found" << endl;
            count++;
        }
    }

    //unit tests
     cout << "useful cards: " << count << endl;
     cout << "deck size: " << currentDeck.size() << endl;

    double usefulCards = static_cast<double>(count);
    const double deckSize = static_cast<double>(currentDeck.size());

    //calculate the amount of cards that would break a pair(ie. trips or quads) and discludes from the deck
    double untakenCards = deckSize - usefulCards;
    cout << "untakenCards: " << untakenCards << endl;


    //flop permutation for numer (starts off with currentDeck -1 and goes 2 slots down)
    double numer = 1;
    for(int i = 0; i < 2; i++){
        numer *= untakenCards - i;
        //cout << "numer: " << numer << endl;
    }

    //flop permutation for denom(starts off with currentDeck and goes 3 slots down)
    double denom = 1;
    for(int i = 0; i < 3; i++){
        denom *= deckSize - i;
        //cout <<"denom:" << denom << endl;
    }

     double answerFlop = ((usefulCards * 3 * numer) / denom) * 100; //multiplies by amount of outs, 3 possible slots where the pair can hit, and by 100 for percentage
    
    //river permutation for numerator(starts off with currentDeck -1 and goes 4 slots down)
    numer = 1; 
    for(int i = 0; i < 4; i++){
        numer *= untakenCards - i;
    }

    //river permutation for denom(starts off with currentDeck and goes 5 slots down)
    denom = 1;
    for(int i = 0; i < 5; i++){
        denom *= deckSize - i;
    }

    double answerRiver = ((usefulCards * 5 * numer) / denom) * 100; //multiplies by amount of outs, 5 possible slots where the pair can hit, and by 100 for percentage

    return to_string(answerFlop) + "% chance to get only a pair by flop" + "\n" + to_string(answerRiver) + "% chance to get only a pair by river"; //returns the amount of useful cards in the deck that work divided by the total amount of cards 
}

//calculate catching a triplet
string calcTrip(Player mainPlayer, vector<Card> &currentDeck){
    
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


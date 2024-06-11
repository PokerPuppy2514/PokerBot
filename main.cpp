#include <iostream> 
#include<iterator>
#include <vector> 
#include <string>
#include <algorithm>
#include <ctime>     
#include <bits/stdc++.h>

#include "card.h"
#include "player.h"

using namespace std; //beans

//function prototypes
int randomfunc(int);
vector<Card> createDeck();
vector<Card> shuffle(vector<Card>);
vector<Card> draw(vector<Card>);

int main(){
    //create and shuffle deck
    vector<Card> deck = shuffle(createDeck());

    //create vector of players
    vector<Player> playerList;

    //print deck
    for (auto& card : deck) {
       cout << card.showCard() + "\n";
    }

    Player();
    
    playerList.push_back(Player());//create null player
    playerList.push_back(Player("Beyn", Card("Hearts", "2"), Card("Spades", "7")));

    //print playerlist
    for (auto& player : playerList) {
        cout << player.printPlayer() + "\n";
    }
    
};

// random generator function seed //randomizes based on time of compilation
int randomfunc(int j) { 
    return rand() % j; 
} 

vector<Card> createDeck(){
    vector<Card> currentDeck;
     //add cards for each suit
    //hearts
    for(int i = 1; i < 14; i ++){
        if(i == 1) currentDeck.push_back(Card("Hearts", "Ace")); //ace

        else if(i == 11)currentDeck.push_back(Card("Hearts", "Jack")); //jack

        else if(i == 12)currentDeck.push_back(Card("Hearts", "Queen")); //queen

        else if(i == 13)currentDeck.push_back(Card("Hearts", "King")); //king

        else {
            currentDeck.push_back(Card("Hearts", to_string(i))); //adds a heart card from Ace to King (puts i to a char)
        }
    }

    //diamonds
    for(int i = 1; i < 14; i ++){
        if(i == 1) currentDeck.push_back(Card("Diamonds", "Ace")); //ace

        else if(i == 11)currentDeck.push_back(Card("Diamonds", "Jack")); //jack

        else if(i == 12)currentDeck.push_back(Card("Diamonds", "Queen")); //queen

        else if(i == 13)currentDeck.push_back(Card("Diamonds", "King")); //king

        else {
            currentDeck.push_back(Card("Diamonds", to_string(i))); //adds a diamond card from Ace to King (puts i to a char)
        }
    }

    //spades
    for(int i = 1; i < 14; i ++){
        if(i == 1) currentDeck.push_back(Card("Spades", "Ace")); //ace

        else if(i == 11)currentDeck.push_back(Card("Spades", "Jack")); //jack

        else if(i == 12)currentDeck.push_back(Card("Spades", "Queen")); //queen

        else if(i == 13)currentDeck.push_back(Card("Spades", "King")); //king

        else {
            currentDeck.push_back(Card("Spades", to_string(i))); //adds a diamond card from Ace to King (puts i to a char)
        }
    }

    //clubs
    for(int i = 1; i < 14; i ++){
        if(i == 1) currentDeck.push_back(Card("Clubs", "Ace")); //ace

        else if(i == 11)currentDeck.push_back(Card("Clubs", "Jack")); //jack

        else if(i == 12)currentDeck.push_back(Card("Clubs", "Queen")); //queen

        else if(i == 13)currentDeck.push_back(Card("club", "King")); //king

        else {
            currentDeck.push_back(Card("Clubs", to_string(i))); //adds a diamond card from Ace to King (puts i to a char)
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
vector<Card>  draw(vector<Card> d){
    d.erase(d.begin());
    return d;
}
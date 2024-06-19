//card class, only has suit and value
using namespace std;

class Card
{
   public:
        Card();
        Card(string suit, string value);

        string getSuit();
        string getValue();
        string showCard();

    private:
        string suit;
        string value;

};

//default constructor
Card::Card(){
    suit = "NULL suit";
    value = "NULL value";
}

 Card::Card(string s, string v){
    suit = s;
    value = v;
}

string Card::getSuit(){ 
    return suit;
}

string Card::getValue(){ 
    return value;
}

string Card::showCard(){
    return value + " of " + suit;
}
//card class, only has suit and value
using namespace std;

class Card
{
   public:
        Card();
        Card(string suit, string value);

        string getSuit()const;
        string getValue()const;
        string showCard();

        bool operator==(const Card& otherCard)const{
            return ((suit == otherCard.getSuit()) && value == otherCard.getValue());
        }

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

string Card::getSuit() const{ 
    return suit;
}

string Card::getValue() const{ 
    return value;
}

string Card::showCard(){
    return value + " of " + suit;
}

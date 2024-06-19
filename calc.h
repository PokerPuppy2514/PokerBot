
class Calc{
    public:
        Calc();
        Calc(Player mainPlayer, vector<Player> currentPlayers, vector<Card> currentDeck);

    
    private:
        Player mainPlayer;
        vector<Player> currentPlayers;
        vector<Card> currentDeck;
};

Calc::Calc(){
    currentPlayers;
    currentDeck;
}

Calc::Calc(Player mp, vector<Player> cp, vector<Card> cd){
    mainPlayer = mp;
    currentPlayers = cp;
    currentDeck = cd;
}
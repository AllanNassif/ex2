#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) : m_player(playerName),
m_cardDeck(new Card[numOfCards]),m_deckSize(numOfCards),m_currentCardIndex(INITIAL_CARD_INDEX){
    for(int i=0 ; i< numOfCards; i++){
        m_cardDeck[i] = cardsArray[i];
    }

}



Mtmchkin::~Mtmchkin(){
    delete[] m_cardDeck;
}

Mtmchkin::Mtmchkin(const Mtmchkin& otherMtmchkin):m_player(otherMtmchkin.m_player),
m_cardDeck(new Card[otherMtmchkin.m_deckSize]),m_deckSize(otherMtmchkin.m_deckSize),
m_currentCardIndex(otherMtmchkin.m_currentCardIndex) {

    for(int i=0 ; i<m_deckSize;i++){
        m_cardDeck[i]=otherMtmchkin.m_cardDeck[i];
    }

}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& otherMtmchkin){
    if(this == &otherMtmchkin){
        return *this;
    }
    Card* temp = new Card[otherMtmchkin.m_deckSize];
    delete[] m_cardDeck;
    m_cardDeck = temp;
    for(int i = 0; i< otherMtmchkin.m_deckSize;i++){
        m_cardDeck[i]= otherMtmchkin.m_cardDeck[i];
    }
    m_player = otherMtmchkin.m_player;
    m_deckSize = otherMtmchkin.m_deckSize;
    m_currentCardIndex = otherMtmchkin.m_currentCardIndex;
    return *this;

}

void Mtmchkin::playNextCard(){
    if(m_currentCardIndex == m_deckSize){
        m_currentCardIndex = INITIAL_CARD_INDEX;
    }
    m_cardDeck[m_currentCardIndex].printInfo();
    m_cardDeck[m_currentCardIndex++].applyEncounter(m_player);
    m_player.printInfo();
}


bool Mtmchkin::isOver() const{
    if(m_player.isKnockedOut()){
        return true;
    }
    if(m_player.getLevel() == MAX_LEVEL){
        return true;
    }
    return false;
}

GameStatus Mtmchkin::getGameStatus() const{
    if(!isOver()){
        return GameStatus::MidGame;
    }
    else if(m_player.isKnockedOut()){
        return GameStatus::Loss;
    }
    else{
        return GameStatus::Win;
    }
}

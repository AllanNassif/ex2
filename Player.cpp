#include "utilities.h"
#include "Player.h"

void Player::printInfo() const {
    const char* name = m_name.std::string::c_str();
    printPlayerInfo(name,m_level,m_force,m_HP,m_coins);
}

void Player::levelUp(){
    if(getLevel() >= MAX_LEVEL){
        return;
    }
    m_level++;

}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(int forceToAdd){
    if(forceToAdd <= 0){
        return;
    }
    m_force += forceToAdd;
}

void Player::heal(int hpToAdd){
    if(m_HP == m_maxHP ||  hpToAdd <=0){
        return;
    }
    m_HP+= hpToAdd;
    if(m_HP > m_maxHP){
        m_HP = m_maxHP;
    }
}

void Player::damage(int hpToReduce){
    if(hpToReduce <=0){
        return;
    }
    m_HP -= hpToReduce;
    if(m_HP < 0){
        m_HP = 0;
    }

}

bool Player::isKnockedOut() const{
    if(m_HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd){
    if(coinsToAdd<= 0){
        return;
    }
    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToReduce){
    if(coinsToReduce <= 0){
        return true;
    }
    if(m_coins >= coinsToReduce){
        m_coins -= coinsToReduce;
        return true;
    }
    return false;
}
int Player::getAttackStrength() const{
    return m_force + m_level;
}

Player::Player(const std::string& name,int maxHP,int force) : m_name(name),m_level(INITIAL_LEVEL),m_HP(m_maxHP)
,m_coins(INITIAL_COINS) {
    if(force>0){
        m_force = force;
    }
    if(maxHP > 0){
        m_maxHP = maxHP;
        m_HP=m_maxHP;
    }
}

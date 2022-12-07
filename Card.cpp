#include "Card.h"


Card::Card(CardType type,const CardStats& stats): m_effect(type),m_stats(stats) {}

void Card::applyEncounter(Player& player) const{
    if (m_effect == CardType::Battle){
        bool win = false;
        if (m_stats.force <= player.getAttackStrength()){
            win = true;
            player.levelUp();
            player.addCoins(m_stats.loot);
            }
        else {
            player.damage(m_stats.hpLossOnDefeat);
        }
        printBattleResult(win);  
        }
    else if (m_effect == CardType::Heal && player.pay(m_stats.cost)){
        player.heal(m_stats.heal);
    }
    else if (m_effect == CardType::Buff && player.pay(m_stats.cost)){
        player.buff(m_stats.buff);
    }
    else if (m_effect == CardType::Treasure){
        player.addCoins(m_stats.loot);
    } 
    
}

void Card::printInfo() const {
    if (m_effect == CardType::Battle){
        printBattleCardInfo(m_stats);
    }
    else if (m_effect == CardType::Buff){
        printBuffCardInfo(m_stats);
    }
    else if (m_effect == CardType::Heal){
        printHealCardInfo(m_stats);
    }
    else {
        printTreasureCardInfo(m_stats);
    }
}



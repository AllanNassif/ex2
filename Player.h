

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

/*The max level of player*/
static const int MAX_LEVEL = 10;

class Player {

public:
    
    /*
     * printInfo - prints the player details
     * 
     * @return
     *     void
     * 
    */
    void printInfo() const;

    /*
     * levelUp - increases the level by one.The level can be increased till level 10.
     * 
     * @return
     *     void
    */
    void levelUp();

    /*
     * getLevel - returns the level of the player.
     * 
     * @return
     * Integer of the player level.
    */
    int getLevel() const;

    /*
     * buff - increases the force of the player by the amount given as an argument.
     * 
     * @param forceToAdd - Integer of the amount of force to be added.
     * @return
     *     void
    */
    void buff(int forceToAdd);

    /*
     * heal - increases the hp of the player by the amount given as an argument, up to maxHP.
     * 
     * @param hpToAdd - Integer of the amount of hp to be added.
     * @return
     *     void
    */
    void heal(int hpToAdd);

    /*
     * damamge - decreases the hp of the player by the amount given as an argument, up to 0.
     * 
     * @param hpToReduce - Integer of the amount of hp to be reduced.
     * @return 
     *     void
    */
    void damage(int hpToReduce);

    /*
     * isKnockedOut - checks if the hp of the player is 0.
     * 
     * @return
     * true - if the hp of the player is 0, 
     * false - if the hp of the player is not 0.
    */
    bool isKnockedOut() const;

    /*
     * addCoins - adds the amount of coins of the player
     * 
     * @param coinsToAdd - the amount of coins to add to the player
     * @return
     *     void
    */
    void addCoins(int coinsToAdd);

    /*
     * pay - makes a payment - decreases the amount of coins of the player
     * 
     * @param coinsToReduce - the amount of coins to be reducded.
     * @return
     * true - if the payment has been successfuly made,
     * false - thhe payment has been failed(the amount of coins have not been changed).
    */
    bool pay(int coinsToReduce);

    /*
     * getAttackStrength - gets the attack strength of player
     * the attack strength is defined to be the force of the player added with the level of the player
     * 
     * @return
     * Attack strength - player force + player level.
    */
    int getAttackStrength() const;

    /*
     * C'tor for Player class
     * 
     * @param name - The name of the player.
     * @param force - The force of the player.
     * @param maxHP - The maxHP of the player.
     * @return
     * New player - level 1 , with 0 coins , with full hp which is equal to the maxhp initialized,
     * with the initialized force.
    */
    Player(const std::string& name,int maxHP = DEFAULT_MAX_HP,int force = DEFAULT_FORCE);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& otherPlayer) = default;


private:

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

    /*Initial level of player*/
    static const int INITIAL_LEVEL = 1;

    /*Initial coins of player*/
    static const int INITIAL_COINS = 0;

    /*Initial default force of player*/
    static const int DEFAULT_FORCE = 5;

    /*Initial default max hp of player*/
    static const int DEFAULT_MAX_HP = 100;


};



#endif // PLAYER_H_
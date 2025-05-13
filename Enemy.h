

// enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Character;

enum class EnemyType { Goblin, Orc };

class Enemy {
protected:
    std::string name;
    EnemyType type;
    int health, attackPower, defense;

public:
    Enemy(std::string n, EnemyType t, int hp, int atk, int def);
    ~Enemy();  // Non-Virtual Destructor

    virtual void attack(Character& character);
    virtual void specialAction();  // Virtual method for special actions

    void takeDamage(int damage);

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    int getDefense() const { return defense; }

    EnemyType getType() const { return type; }

    friend void displayStatus(const Character& character, const Enemy& enemy);
    friend void battleSummary(const Character& character, const Enemy& enemy);
    friend void compareStrength(const Character& character, const Enemy& enemy);
};

#endif // ENEMY_H
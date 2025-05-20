
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include "Enemy.h"
#include <string>

class Warrior : public Character {
private:
    int rage;
    int defenseBoost;

public:
    Warrior(std::string n, int hp, int atk, int def, int r, int db);
    ~Warrior() override;  // This ensures proper virtual destruction

    void attack(Enemy& enemy) override;
    void increaseRage(int amount);
    void boostDefense();
    void specialAction() override;
    void gainhp();

    int getRage() const;  // ✅ Const getter added

    // Static function to return the default rage value
    static int getDefaultRage() { return 10; }  // Default rage value

};

#endif // WARRIOR_H

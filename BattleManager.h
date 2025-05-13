#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "Character.h"
#include "Enemy.h"

// BattleManager class to manage the battle flow
class BattleManager {
private:
    Character& character;  // Reference to the Character (Warrior or Mage)
    Enemy& enemy;          // Reference to the Enemy (Goblin or Orc)

public:
    // Constructor to initialize BattleManager with a character and an enemy
    BattleManager(Character& c, Enemy& e);

    // Method to start the battle between character and enemy
    void startBattle();
};

#endif // BATTLEMANAGER_H

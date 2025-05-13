
#pragma once
#ifndef ARENA_H
#define ARENA_H

#include "Character.h"
#include "Enemy.h"
#include "BattleManager.h"

// Arena class to manage a battle between characters and enemies
class Arena {
private:
    Character& character1;  // Reference to the first character
    Character& character2;  // Reference to the second character
    Enemy& enemy1;          // Reference to the first enemy
    Enemy& enemy2;          // Reference to the second enemy

public:
    // Constructor that initializes the Arena with two characters and two enemies
    Arena(Character& c1, Character& c2, Enemy& e1, Enemy& e2);

    // Method to simulate the battle between the characters and enemies
    void startArenaBattle();
};

#endif // ARENA_H#pragma once

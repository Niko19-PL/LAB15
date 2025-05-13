#include "BattleManager.h"
#include <iostream>

// Constructor for BattleManager that takes references to a character and an enemy
BattleManager::BattleManager(Character& c, Enemy& e) : character(c), enemy(e) {}

// Method to simulate the battle
void BattleManager::startBattle() {
    std::cout << "\n--- Battle Start ---\n";
    displayStatus(character, enemy);  // Display initial status
    compareStrength(character, enemy);  // Compare strength of character and enemy

    // Battle loop
    while (character.getHealth() > 0 && enemy.getHealth() > 0) {
        // Character attacks first
        character.attack(enemy);
        displayStatus(character, enemy);

        if (enemy.getHealth() <= 0) {
            battleSummary(character, enemy);
            std::cout << "\n" << character.getName() << "'s Victory!\n";
            break;
        }

        // Enemy attacks
        enemy.attack(character);
        displayStatus(character, enemy);

        if (character.getHealth() <= 0) {
            battleSummary(character, enemy);
            std::cout << "\n" << enemy.getName() << "'s Victory!\n";
            break;
        }
    }
}
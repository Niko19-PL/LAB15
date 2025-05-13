#include "BattleArena.h"
#include "Enemy.h"
#include "Character.h"
#include <iostream>

BattleArena::BattleArena(Character* c, Enemy* e) : character(c), enemy(e), battleOver(false) {}

void BattleArena::startBattle() {
    while (!battleOver) {
        // Display status of both participants
        displayStatus();

        // Character's turn to attack
        std::cout << character->getName() << "'s turn!\n";
        character->attack(*enemy);

        // Check if enemy is dead
        if (enemy->getHealth() <= 0) {
            battleOver = true;
            std::cout << enemy->getName() << " has been defeated!\n";
            break;
        }

        // Enemy's turn to attack
        std::cout << enemy->getName() << "'s turn!\n";
        enemy->attack(*character);

        // Check if character is dead
        if (character->getHealth() <= 0) {
            battleOver = true;
            std::cout << character->getName() << " has been defeated!\n";
            break;
        }
    }

    // Display the winner at the end
    displayWinner();
}

void BattleArena::displayStatus() {
    std::cout << "\n--- Battle Status ---\n";
    std::cout << character->getName() << " | Health: " << character->getHealth() << " | Attack: " << character->getAttackPower() << " | Defense: " << character->getDefense() << "\n";
    std::cout << enemy->getName() << " | Health: " << enemy->getHealth() << " | Attack: " << enemy->getAttackPower() << " | Defense: " << enemy->getDefense() << "\n";
}

void BattleArena::displayWinner() {
    if (character->getHealth() > 0) {
        std::cout << character->getName() << " wins the battle!\n";
    }
    else if (enemy->getHealth() > 0) {
        std::cout << enemy->getName() << " wins the battle!\n";
    }
    else {
        std::cout << "It's a draw! Both are defeated.\n";
    }
}

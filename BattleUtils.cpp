#include "BattleUtils.h"
#include <iostream>
#pragma once

void displayStatus(const Character& character, const Enemy& enemy) {
    std::cout << "\n--- Status Update ---\n";
    std::cout << "Character: " << character.getName() << " | Health: " << character.getHealth()
        << " | Attack: " << character.getAttackPower() << " | Defense: " << character.getDefense() << "\n";
    std::cout << "Enemy: " << enemy.getName() << " | Health: " << enemy.getHealth()
        << " | Attack: " << enemy.getAttackPower() << " | Defense: " << enemy.getDefense() << "\n";
}

void battleSummary(const Character& character, const Enemy& enemy) {
    std::cout << "\n--- Battle Summary ---\n";
    if (character.getHealth() > 0 && enemy.getHealth() <= 0) {
        std::cout << character.getName() << " is victorious!\n";
    }
    else if (enemy.getHealth() > 0 && character.getHealth() <= 0) {
        std::cout << enemy.getName() << " is victorious!\n";
    }
    else if (character.getHealth() <= 0 && enemy.getHealth() <= 0) {
        std::cout << "It's a draw! Both characters are defeated.\n";
    }
}

void compareStrength(const Character& character, const Enemy& enemy) {
    std::cout << "\nComparing Strength: \n";
    if (character.getAttackPower() > enemy.getAttackPower()) {
        std::cout << character.getName() << " has more attack power than " << enemy.getName() << ".\n";
    }
    else if (character.getAttackPower() < enemy.getAttackPower()) {
        std::cout << enemy.getName() << " has more attack power than " << character.getName() << ".\n";
    }
    else {
        std::cout << "Both characters have the same attack power.\n";
    }
}
#include "Goblin.h"
#include "Character.h"
#include <iostream>

Goblin::Goblin(std::string n, int hp, int atk, int def, int s)
    : Enemy(n, EnemyType::Goblin, hp, atk, def), stealth(s) {
}

void Goblin::attack(Character& character) {
    if (stealth > 0) {
        std::cout << name << " attacks stealthily!\n";
        character.takeDamage(attackPower + stealth);
    }
    else {
        std::cout << name << " attacks normally.\n";
        character.takeDamage(attackPower);
    }
}

void Goblin::hide() {
    stealth += 5;
    defense += 2;
    std::cout << name << " hides in the shadows, increasing stealth to " << stealth
        << " and defense to " << defense << "!\n";
}

void Goblin::specialAction() {
    std::cout << name << " performs a sneaky ambush!\n";
}
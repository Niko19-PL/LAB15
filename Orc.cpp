#include "Orc.h"
#include "Character.h"
#include <iostream>

Orc::Orc(std::string n, int hp, int atk, int def, int b)
    : Enemy(n, EnemyType::Orc, hp, atk, def), berserk(b) {
}

void Orc::attack(Character& character) {
    if (berserk > 0) {
        std::cout << name << " goes berserk and attacks with extra force!\n";
        character.takeDamage(attackPower + berserk);
    }
    else {
        std::cout << name << " attacks normally.\n";
        character.takeDamage(attackPower);
    }
}

void Orc::enrage() {
    berserk += 10;
    attackPower += 5;
    std::cout << name << " is enraged! Berserk increased to " << berserk
        << ", attack power now " << attackPower << "!\n";
}

void Orc::specialAction() {
    std::cout << name << " performs a terrifying roar, gaining strength!\n";
}
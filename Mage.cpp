
#pragma once

#include "Mage.h"
#include "Enemy.h"
#include <iostream>
#include <exception>

Mage::Mage(std::string n, int hp, int atk, int def, int m, int sp, int mr)
    : Character(n, CharacterType::Mage, hp, atk, def), mana(m), spellPower(sp), manaRegen(mr) {


   
    
}

void Mage::attack(Enemy& enemy) {
    if (mana > 0) {
        int magicDamage = attackPower * spellPower;
        mana -= 10;
        std::cout << name << " casts a spell on " << enemy.getName() << "!\n";
        enemy.takeDamage(magicDamage);
    }
    else {
        std::cout << name << " is out of mana!\n";
    }
}
void Mage::checkManaBeforeSpell() {
    if (mana < 10) {
        throw std::runtime_error("Mana too low to cast any spell. Provide a higher mana value!");
    }
    else {
        std::cout << name << " has sufficient mana to cast a spell.\n";
    }
}

void Mage::castSpell(Enemy& enemy) {
    if (mana >= 20) {
        mana -= 20;
        std::cout << name << " casts a powerful spell on " << enemy.getName() << "!\n";
        enemy.takeDamage(50);
    }
    else {
        std::cout << name << " doesn't have enough mana to cast the spell.\n";
    }
}

void Mage::regenerateMana() {
    mana += manaRegen;
    std::cout << name << " meditates and regenerates mana. Current mana: " << mana << "\n";
}

void Mage::specialAction() {
    std::cout << name << " casts a powerful spell, causing massive damage!\n";
}


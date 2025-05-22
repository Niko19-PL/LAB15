#pragma once
#ifndef MAGE_H
#define MAGE_H

#include "Character.h"
#include "Enemy.h"

class Mage : public Character {
private:
    int mana;
    int spellPower;
    int manaRegen;

public:
    Mage(std::string n, int hp, int atk, int def, int m, int sp, int mr);
    void attack(Enemy& enemy) override;
    void castSpell(Enemy& enemy);
    void regenerateMana();
    void specialAction() override;  // Overriding the base class method
    void checkManaBeforeSpell();
};

#endif // MAGE_H#pragma once
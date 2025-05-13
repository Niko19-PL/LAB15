#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin : public Enemy {
private:
    int stealth;

public:
    Goblin(std::string n, int hp, int atk, int def, int s);
    void attack(Character& character) override;
    void hide();  // New method
    void specialAction() override;  // Overriding the base class method
};

#endif // GOBLIN_H#pragma once

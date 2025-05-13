#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy {
private:
    int berserk;

public:
    Orc(std::string n, int hp, int atk, int def, int b);
    void attack(Character& character) override;
    void enrage();  // New method
    void specialAction() override;  // Overriding the base class method
};

#endif // ORC_H#pragma once

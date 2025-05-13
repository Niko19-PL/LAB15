#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include "Character.h"
#include "Enemy.h"

class BattleArena {
private:
    Character* character;
    Enemy* enemy;
    bool battleOver;

public:
    BattleArena(Character* c, Enemy* e);
    void startBattle();
    void displayWinner();
    void displayStatus();
};

#endif // BATTLEARENA_H
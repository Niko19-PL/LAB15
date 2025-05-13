#include "Arena.h"
#include <iostream>

Arena::Arena(Character& c1, Character& c2, Enemy& e1, Enemy& e2)
    : character1(c1), character2(c2), enemy1(e1), enemy2(e2) {
}

void Arena::startArenaBattle() {
    std::cout << "\n--- Arena Battle Start ---\n";

    // Battle between character1 and enemy1
    BattleManager battle1(character1, enemy1);
    battle1.startBattle();

    // Battle between character2 and enemy2
    BattleManager battle2(character2, enemy2);
    battle2.startBattle();
}



// enemy.cpp
#include "Enemy.h"
#include "Character.h"
#include <iostream>

Enemy::Enemy(std::string n, EnemyType t, int hp, int atk, int def)
    : name(n), type(t), health(hp), attackPower(atk), defense(def) {
}

Enemy::~Enemy() {  // Non-virtual destructor
    std::cout << "Enemy Destructor: " << name << " destroyed.\n";
}

void Enemy::attack(Character& character) {
    std::cout << name << " attacks " << character.getName() << "!\n";
    character.takeDamage(attackPower);
}

void Enemy::specialAction() {
    std::cout << name << " performs a basic enemy action.\n";  // Default enemy action
}

void Enemy::takeDamage(int damage) {
    int reduced = damage - defense;
    if (reduced < 0) reduced = 0;
    health -= reduced;
    if (health < 0) health = 0;
}

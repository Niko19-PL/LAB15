
#include "Warrior.h"
#include "Enemy.h"
#include <iostream>
#include <exception>
Warrior::Warrior(std::string n, int hp, int atk, int def, int r, int db)
    : Character(n, CharacterType::Warrior, hp, atk, def), rage(r), defenseBoost(db) {
    defense += defenseBoost;
    
    
  
    if (hp <= 0 ) {
        throw std::invalid_argument("Invalid Warrior parameters: values cannot be negative or equal 0.");
    }

    std::cout << "Warrior Constructor: " << name << " created with rage: " << rage << " and defense: " << defense << ".\n";
}

Warrior::~Warrior() {
    std::cout << "Warrior Destructor: " << name << " destroyed.\n";
}

void Warrior::attack(Enemy& enemy) {
    int bonusDamage = attackPower + rage;
    std::cout << name << " attacks " << enemy.getName() << " with a rage-fueled blow!\n";
    enemy.takeDamage(bonusDamage);
}

void Warrior::increaseRage(const int amount) {
    //amount += 5;  // ❌ This line will trigger a compiler error
    rage += amount;
    std::cout << name << "'s rage has increased by " << amount << "!\n";

}

void Warrior::gainmuscle() {
    if (rage > 75) {
        std::cout << name << " warrior is mad enough to gain muscle.\n";
    }
    else {
        throw std::logic_error("Warrior has not enough rage to gain muscle!");
    }
}


void Warrior::boostDefense() {
    defense += 5;
    std::cout << name << " braces for impact, increasing defense to " << defense << "!\n";
}

void Warrior::specialAction() {
    std::cout << name << " performs a powerful rage attack, gaining extra damage!\n";
}

int Warrior::getRage() const {
   // rage = 20;
    return rage;
}

#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Enemy.h"
#include <iostream>

int Character::objectCount = 0;


// Constructor and Destructor
Character::Character(std::string n, CharacterType t, int hp, int atk, int def)
    : name(n), type(t), health(hp), attackPower(atk), defense(def) {
    ++objectCount;  // Increment static count from Character class}
}
Character::~Character() {
    std::cout << "Character Destructor: " << name << " destroyed.\n";
}

// Static function to return the number of Character-derived objects created
int Character::getObjectCount() {
    return objectCount;
}


void Character::attack(Enemy& enemy) {
    std::cout << name << " attacks " << enemy.getName() << "!\n";
    enemy.takeDamage(attackPower);
}

void Character::specialAction() {
    std::cout << name << " performs a basic action.\n";  // Default base behavior
}

void Character::takeDamage(int damage) {
    int reduced = damage - defense;
    if (reduced < 0) reduced = 0;
    health -= reduced;
    if (health < 0) health = 0;

        notifyObservers();
    
}

Character* Character::operator+(const Character& other) {
    // Create new character based on the type of 'this' character (either Warrior or Mage)
    Character* newCharacter = nullptr;

    // If both characters are of the same type (either both Warrior or both Mage)
    if (this->getType() == other.getType()) {
        // Combining same types (Warrior + Warrior or Mage + Mage)
        if (this->getType() == CharacterType::Warrior) {
            const Warrior& w1 = dynamic_cast<const Warrior&>(*this);
            const Warrior& w2 = dynamic_cast<const Warrior&>(other);

            newCharacter = new Warrior(
                w1.getName() + " & " + w2.getName(),  // Combined name
                w1.getHealth() + w2.getHealth(),
                w1.getAttackPower() + w2.getAttackPower(),
                w1.getDefense() + w2.getDefense(),
                w1.getAttackPower(),  // Keep rage based on the first Warrior's rage (could be modified)
                w1.getDefense()       // Keep defense boost based on the first Warrior's defense boost
            );
        }
        else if (this->getType() == CharacterType::Mage) {
            const Mage& m1 = dynamic_cast<const Mage&>(*this);
            const Mage& m2 = dynamic_cast<const Mage&>(other);

            newCharacter = new Mage(
                m1.getName() + " & " + m2.getName(),  // Combined name
                m1.getHealth() + m2.getHealth(),
                m1.getAttackPower() + m2.getAttackPower(),
                m1.getDefense() + m2.getDefense(),
                m1.getHealth() + m2.getHealth(),  // Combined mana (you can decide how to handle this)
                m1.getAttackPower(),  // Default spell power (you can modify this logic)
                m1.getDefense()       // Default mana regen (you can modify this logic)
            );
        }
    }
    // If characters are of different types (e.g., Warrior + Mage)
    else {
        // Logic for combining different types, like Warrior + Mage (or Mage + Warrior)
        if (this->getType() == CharacterType::Warrior && other.getType() == CharacterType::Mage) {
            const Warrior& w = dynamic_cast<const Warrior&>(*this);
            const Mage& m = dynamic_cast<const Mage&>(other);

            // You can decide how to combine them, here's a simple example:
            newCharacter = new Warrior(
                w.getName() + " & " + m.getName(),  // Combined name
                w.getHealth() + m.getHealth(),
                w.getAttackPower() + m.getAttackPower(),
                w.getDefense() + m.getDefense(),
                0,  // Default rage (you can modify if needed)
                0   // Default defense boost (you can modify if needed)
            );
        }
        else if (this->getType() == CharacterType::Mage && other.getType() == CharacterType::Warrior) {
            const Mage& m = dynamic_cast<const Mage&>(*this);
            const Warrior& w = dynamic_cast<const Warrior&>(other);

            // Same as Warrior + Mage combination
            newCharacter = new Mage(
                m.getName() + " & " + w.getName(),  // Combined name
                m.getHealth() + w.getHealth(),
                m.getAttackPower() + w.getAttackPower(),
                m.getDefense() + w.getDefense(),
                m.getHealth() + w.getHealth(),  // Combined mana (you can decide how to handle this)
                0,  // Default spell power (you can modify this logic)
                0   // Default mana regen (you can modify this logic)
            );
        }
    }

    return newCharacter;
}
    bool Character::operator==(const Character & other) const {
        // Compare relevant properties to see if they are equal
        return name == other.name &&
            health == other.health &&
            attackPower == other.attackPower &&
            defense == other.defense;
    }
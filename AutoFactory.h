
#pragma once
#include "characterfactory.h"
#include "Warrior.h"
#include "Mage.h"
#include <iostream>
#include <type_traits>

template <typename T>
class AutoFactory;


template <>
class AutoFactory<Warrior> : public CharacterFactoryW {
public:
    Character* createcharacter(std::string n, int hp, int atk, int def, int r, int db) override {
        return new Warrior(n, hp, atk, def, r, db);
    }
};


template <>
class AutoFactory<Mage> : public CharacterFactoryM {
public:
    Character* createcharacter(std::string n, int hp, int atk, int def, int m, int sp, int mr) override {
        return new Mage(n, hp, atk, def, m, sp, mr);
    }
};
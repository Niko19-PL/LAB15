#ifndef CHARACTER_H
#define CHARACTER_H
#include "Observer.h"
#include "Subject.h"
#include <string>
#include <vector>
#pragma once


class Enemy;

enum class CharacterType { Warrior, Mage };

class Character : public Subject {



protected:
    std::string name;
    CharacterType type;
    int health, attackPower, defense;

    static int objectCount;  // Static counter for all Character instances
private:
    std::vector<Observer*> observers; 
    

public:
    Character(std::string n, CharacterType t, int hp, int atk, int def);
    virtual ~Character();  // Virtual Destructor

    virtual void attack(Enemy& enemy);
    virtual void specialAction();  // Virtual method for special actions

    virtual Character* operator+(const Character& other);  // Not pure virtual now

    bool operator==(const Character& other) const;

    void takeDamage(int damage);
   

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getAttackPower() const { return attackPower; }
    int getDefense() const { return defense; }
    CharacterType getType() const { return type; }


    static int getObjectCount();  // Static function to return object count

    friend void displayStatus(const Character& character, const Enemy& enemy);
    friend void battleSummary(const Character& character, const Enemy& enemy);
    friend void compareStrength(const Character& character, const Enemy& enemy);


    void addObserver(Observer* observer) override 
    {
        observers.push_back(observer);
    
    }

    void removeObserver(Observer* observer) override 
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());

    
    }

    void notifyObservers() override 
    {
        for (Observer* observer : observers)
        {
            observer->update();



        }

    }






};

#endif // CHARACTER_H

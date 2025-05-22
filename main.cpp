#include "Enemy.h"
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"
#include "Orc.h"
#include "UI.h"
#include "iostream"
#include "exception"
#include "Observer.h"
#include "Subject.h"
#include "characterfactory.h"
#include "warriormagefactory.h"
#pragma once


int main() {
    /*try {



        // Warrior with invalid (zero) health to demonstrate constructor-based exception
        //Warrior w2("BrokenThorin", 1, 30, 15, 10, 5);

        // Mage with too low mana to demonstrate method-based exception
       // Mage m2("Merlin", 80, 25, 10, 11, 40, 5); // Mana is too low
       // m2.checkManaBeforeSpell();


        // Warrior with invalid (zero) health to demonstrate constructor-based exception
        Warrior w3("BrokenThorin", 100, 30, 15, 74, 5);
         w3.gainhp();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "invalid_argument: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "out_of_range: " << e.what() << std::endl;
    }

    catch (const std::logic_error& e) {
        std::cerr << "logic_error : " << e.what() << std::endl;
    }

   /*


    /*

        Character* warrior = new Warrior("Noone", 100, 50, 30, 80, 30);

        UI* ui = new UI();

        warrior->addObserver(ui);

        std::cout << "Health before damage: " << warrior->getHealth() << std::endl;

        warrior->takeDamage(80);

        std::cout << "Health after damage: " << warrior->getHealth() << std::endl;


        return 0;

}
*/


    CharacterFactoryW* warriorFactory = new WarriorFactory();
    CharacterFactoryM* mageFactory = new MageFactory();

    Character* warrior = warriorFactory->createcharacter("WOLVERINE", 100, 15, 5, 80, 25);
    Character* mage = mageFactory->createcharacter("Gandalf", 100, 15, 5, 80, 25, 10);
};
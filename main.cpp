#include "Enemy.h"
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"
#include "Orc.h"
#include <iostream>
#include <exception>

int main() {
    try {
       

        // Mage with too low mana to demonstrate method-based exception
       // Mage m2("Merlin", 80, 25, 10, 9, 40, 5); // Mana is too low
       // m2.checkManaBeforeSpell(); // This should throw

        // Warrior with invalid (zero) health to demonstrate constructor-based exception
        //Warrior w2("BrokenThorin", 0, 30, 15, 10, 5); // This should throw

        // Warrior with invalid (zero) health to demonstrate constructor-based exception
        Warrior w3("BrokenThorin", 100, 30, 15, 10, 5); // This should throw
         w3.gainmuscle(); // This should throw
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

    return 0;
}
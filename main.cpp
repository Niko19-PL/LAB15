#include "Enemy.h"
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"
#include "Orc.h"
#include <iostream>

int main() {
    Warrior w1("Thorin", 100, 30, 15, 10, 5);
    Mage m1("Gandalf", 80, 25, 10, 100, 40, 5);
    Warrior w2("Thorin", 100, 30, 15, 10, 5);
    
    std::cout << "\nTotal Characters Created: " << Character::getObjectCount() << std::endl;

    // Call the const getter function
    std::cout << w1.getName() << "'s current rage: " << w1.getRage() << std::endl;


    // Call the static function to get the default rage value
    std::cout << "Default rage value for Warrior: " << Warrior::getDefaultRage() << std::endl;

    return 0;
}
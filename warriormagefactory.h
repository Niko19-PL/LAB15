#pragma once
#include "Character.h"

#include "Warrior.h"
#include "Mage.h"
#include "characterfactory.h"
#include"iostream"

class WarriorFactory : public CharacterFactoryW
{
	Character* createcharacter(std::string n, int hp, int atk, int def, int r, int db) override
	{
	
		return new Warrior(n,hp,atk,def,r,db);
		
	}
};


class MageFactory : public CharacterFactoryM
{
public:
	Character* createcharacter(std::string n, int hp, int atk, int def, int m, int sp, int mr) override
	{
		return new Mage(n,hp,atk,def,m,sp,mr);
	}



};
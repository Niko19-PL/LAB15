#pragma once
#include "Character.h"

#include "iostream"


class CharacterFactoryW
{

public:
	virtual Character* createcharacter(std::string n, int hp, int atk, int def, int r, int db) = 0;
	
	virtual ~CharacterFactoryW() {}



};

class CharacterFactoryM
{

public:
	virtual Character* createcharacter(std::string n, int hp, int atk, int def, int m, int sp, int mr) = 0;

	virtual ~CharacterFactoryM() {}


};
































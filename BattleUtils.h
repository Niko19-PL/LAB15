#ifndef BATTLEUTILS_H
#define BATTLEUTILS_H

#include "Character.h"
#include "Enemy.h"

// Friend functions
void displayStatus(const Character& character, const Enemy& enemy);
void battleSummary(const Character& character, const Enemy& enemy);
void compareStrength(const Character& character, const Enemy& enemy);

#endif // BATTLEUTILS_H#pragma once

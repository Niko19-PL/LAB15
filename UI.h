#pragma once
#include "Observer.h"
#include "Subject.h"
#include "iostream"
class UI : public Observer
{

public:
	void update() override

	{
	
		std::cout << "UI: Characters's state has changed" << std::endl;

	
	}

};
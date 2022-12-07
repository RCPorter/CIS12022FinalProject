#ifndef MEAL_H
#define MEAL_H

#include "Consume.h"
class Meal : 
	public Consume
{
private:

public:
	//Constuctor
	Meal() : Consume::Consume() {};

	//Accessor
	int getTotalCals();

};

#endif MEAL_H
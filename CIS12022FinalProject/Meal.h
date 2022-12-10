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
	double getTotalCals();//Meal.cpp: 3-14
	void showCons();//Meal.cpp: 16-24
};

#endif MEAL_H
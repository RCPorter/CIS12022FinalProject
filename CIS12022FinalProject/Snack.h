#ifndef SNACK_H
#define SNACK_H

#include "Consume.h"
class Snack :
    public Consume
{
private:
	bool healthy;

public:
	//Constuctor
	Snack() : Consume::Consume() {};
	
	//Mutator
	void setHealthy();//Snack.cpp: 3-25

	//Accessor
	inline bool getHealthy() { return healthy; };
	void showCons();//Snack.cpp: 27-40
};

#endif SNACK_H
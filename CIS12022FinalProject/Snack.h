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
	Snack() : Consume::Consume() { };
	
	//Mutator
	void setHealthy();

	//Accessor
	inline bool getHealthy() { return healthy; };
};

#endif SNACK_H
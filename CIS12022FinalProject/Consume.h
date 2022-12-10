#ifndef CONSUME_H
#define CONSUME_H
#include <vector>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

struct FoodItem {
	char unit; 
	int calPerUnit;
};

class Consume
{
protected:
	vector<pair<FoodItem, double>> ate;
	vector<string> name;

public:
	//Constructor
	Consume() {}
	
	//Mutator
	void addItem(const FoodItem& food, const string& name);//Consume.h: 3-24

	//Accessors
	void showItem(int sub);//Consume.h: 26-33

	//Utility
	double itemCal(int sub);//Consume.h: 35-39
	void showList();//Consume.h: 41-47
	void cupGram(char unit);//Consume.h: 49-61
	double doubCheck(const string& test);//Consume.h: 63-80
	void doubErr(string& test);//Consume.h: 82-87
};

#endif CONSUME_H
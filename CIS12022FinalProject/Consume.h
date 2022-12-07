#ifndef CONSUME_H
#define CONSUME_H
#include <vector>
#include <utility>
#include "Func.h"
struct FoodItem {
	string name;
	char unit; 
	int calPerUnit;
};

class Consume
{
protected:
	vector<pair<FoodItem, int>> ate; 
public:
	Consume() {}
	void addItem(const vector<FoodItem>& list, FoodItem food);
	int itemCal(const pair<FoodItem, int>& item);
	void showItem(const pair<FoodItem, int>& item);
	void showList();
};

#endif CONSUME_H
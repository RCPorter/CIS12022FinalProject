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
	vector<pair<FoodItem, int>> ate;
	vector<string> name;
public:
	Consume() {}
	
	void addItem(const FoodItem& food, const string& name);
	int itemCal(int sub);
	void showItem(int sub);
	void showList();
	int intCheck(const string& test);
	void intErr(string& test);
	void cupGram(char unit);
};

#endif CONSUME_H
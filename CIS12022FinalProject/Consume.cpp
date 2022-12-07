#include "Consume.h"


void Consume::addItem(const vector<FoodItem> &list, FoodItem food) {

	pair<FoodItem, int> temp;
	string holdQty;
	int convQty;

	cout << "\nPlease enter how many ";
	cupGram(food.unit);
	cout << " of " << food.name << " you ate: ";
	getline(cin, holdQty);
	convQty = intCheck(holdQty);
	while (!convQty) {
		intErr(holdQty);
		convQty = intCheck(holdQty);
	}

	temp.first = food;
	temp.second = convQty;
}

int Consume::itemCal(const pair<FoodItem, int> &item) {
	return item.first.calPerUnit * item.second;
}

void Consume::showItem(const pair<FoodItem, int> &item) {
	cupGram(item.first.unit);
	cout << " of " << item.first.name << ": ";
	itemCal(item);
	cout << " Calories";
}

void Consume::showList() {

	for (int i = 0; i < ate.size(); i++) {
		showItem(ate[i]);
	}
}
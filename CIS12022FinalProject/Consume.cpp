#include "Consume.h"


void Consume::addItem(const FoodItem& food, const string& foodName) {

	pair<FoodItem, int> temp;
	string holdQty;
	int convQty;

	cout << "\nPlease enter how many ";
	cupGram(food.unit);
	cout << " of " << foodName << " you ate: ";
	getline(cin, holdQty);
	convQty = intCheck(holdQty);
	while (!convQty) {
		intErr(holdQty);
		convQty = intCheck(holdQty);
	}

	temp.first = food;
	temp.second = convQty;

	ate.push_back(temp);
	name.push_back(foodName);
}

int Consume::itemCal(int sub) {
	return ate[sub].first.calPerUnit * ate[sub].second;
}

void Consume::showItem(int sub) {
	cout << endl << endl << ate[sub].second << " ";
	cupGram(ate[sub].first.unit);
	cout << " of " << name[sub] << ": " << itemCal(sub);
	cout << " Calories";
}

void Consume::showList() {

	for (int i = 0; i < ate.size(); i++) {
		showItem(i);
	}
}

int Consume::intCheck(const string& test) {
	for (int i = 0; i < test.length(); i++) {
		if (!isdigit(test.at(i))) {
			return 0;
		}
	}
	return stoi(test);

}

void Consume::intErr(string& test) {
	cout << "\nError: " << test << " is not a valid option. Please enter a positive whole number (ex. 100): ";
	getline(cin, test);
}

void Consume::cupGram(char unit) {
	if (unit == 'g') {
		cout << "Grams";
	}
	else if (unit == 'c') {
		cout << "Cups";
	}
	else {
		cout << "Critical Unit Error";
	}
}
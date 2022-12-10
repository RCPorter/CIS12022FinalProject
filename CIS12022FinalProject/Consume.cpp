#include "Consume.h"

void Consume::addItem(const FoodItem& food, const string& foodName) {

	pair<FoodItem, int> temp;
	string holdQty;
	double convQty;

	cout << "\nPlease enter how many ";
	cupGram(food.unit);
	cout << " of " << foodName << " you ate: ";
	getline(cin, holdQty);
	convQty = doubCheck(holdQty);
	while (!convQty) {
		doubErr(holdQty);
		convQty = doubCheck(holdQty);
	}

	temp.first = food;
	temp.second = convQty;

	ate.push_back(temp);
	name.push_back(foodName);
}

void Consume::showItem(int sub) {

	cout << endl << endl << ate[sub].second << " ";
	cupGram(ate[sub].first.unit);
	cout << " of " << name[sub] << ": " << itemCal(sub);
	cout << " Calories";

}

double Consume::itemCal(int sub) {

	return (double)ate[sub].first.calPerUnit * ate[sub].second;

}

void Consume::showList() {

	for (int i = 0; i < ate.size(); i++) {
		showItem(i);
	}

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

double Consume::doubCheck(const string& test) {

	int dotCnt = 0;
	for (int i = 0; i < test.size(); i++) {
		if (!isdigit(test.at(i)) && test.at(i) != '.') {
			return 0.0;
		}
		if (test.at(i) == '.') {
			dotCnt++;
			if (dotCnt > 1) {
				return 0.0;
			}
		}

	}
	return stod(test);

}

void Consume::doubErr(string& test) {

	cout << "\nError: " << test << " is not a valid option. Please enter a positive number (ex. 1.5): ";
	getline(cin, test);

}
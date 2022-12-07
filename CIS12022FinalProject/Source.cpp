/*
->Author: Robert C. Porter
->Class: 22.FA.CIS.1202.502 C++ Software Development
->Date: MM.DD.YY
->Assignment: ASSIGNMENT NAME
*/
#include "Meal.h"
#include "Snack.h"
#include <iostream>

void getItem(vector<FoodItem>& list);
bool checkList(const string& search, const vector<FoodItem> &list);
void addItem(vector<FoodItem>& list, string name);

int main() {

	vector<FoodItem> savedItems;
	vector<Meal> listMeal;
	vector<Snack> listSnack;

	cout << "\nFirst Add Test:";
	getItem(savedItems);
	cout << "\nSecond Add Test:";
	getItem(savedItems);

	cout << "\nCreate Meal: ";
	Meal tempMeal;
	tempMeal.addItem(savedItems, savedItems[0]);
	tempMeal.addItem(savedItems, savedItems[0]);

	cout << "\nTesting Show List: ";
	tempMeal.showList();

	cout << endl << endl;
	system("pause");
	return 0;
}

void getItem(vector<FoodItem>& list) {
	
	string name;

	cout << "\nPlease enter the name of the food: ";
	getline(cin, name);
	
	if (!checkList(name, list)) {
		
		cout << "\nYou have not entered the information for " << name << " yet.\n";
		addItem(list, name);

	}
	else {
		//Ask for quantity of food then pass both to the meal
		cout << "\nBy some miracle of GOD HIMSELF, there is a " << name << "in this list.";
	}

}

bool checkList(const string &search, const vector<FoodItem>& list) {

	bool isInList = false;

	for (int i = 0; i < list.size(); i++) {
		if (search == list[i].name) {
			isInList = true;
		}
	}

	return isInList;

}

void addItem(vector<FoodItem>& list, string name) {

	FoodItem temp;
	

	string holdUnit; //g for Gram, c for Cup
	char convUnit;
	cout << "\nPlease enter which unit you will use for the food (g for per Gram, c for per Cup): ";
	getline(cin, holdUnit);
	convUnit = tolower(holdUnit.at(0));
	
	while (convUnit != 'c' && convUnit != 'g') {
		cout << "\nError: " << holdUnit << " is not a valid option. Please enter either c for Cups or g for Grams: ";
		getline(cin, holdUnit);
		convUnit = tolower(holdUnit.at(0));
	}

	string holdCals;
	int convCals;
	cout << "\nPlease enter how many caleries are in a ";
	cupGram(convUnit);
	cout << " of " << name << ": ";
	getline(cin, holdCals);
	convCals = intCheck(holdCals);
	while (!convCals) {
		intErr(holdCals);
		convCals = intCheck(holdCals);
	}

	temp = { name, convUnit, convCals };
	list.push_back(temp);

}
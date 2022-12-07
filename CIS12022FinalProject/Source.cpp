/*
->Author: Robert C. Porter
->Class: 22.FA.CIS.1202.502 C++ Software Development
->Date: MM.DD.YY
->Assignment: ASSIGNMENT NAME
*/
#include "Meal.h"
#include "Snack.h"
#include <iostream>

int getItem(vector<FoodItem>& list);
int checkList(const string& search, const vector<FoodItem> &list);
void addItem(vector<FoodItem>& list, string name);
int intCheck(const string& test);
void intErr( string& test);
void charCheck(string& inp, char& test, char x, char y);
void cupGram(char unit);
void addCons(vector<Meal>& listM, vector<FoodItem>& listFI);
void addCons(vector<Snack>& listS, vector<FoodItem>& listFI);

int main() {

	vector<FoodItem> savedItems;
	vector<Meal> listMeal;
	vector<Snack> listSnack;

	cout << "\nAdding Meal: ";
	addCons(listMeal, savedItems);
	cout << "\nFinished Adding Meal: ";

	cout << "\nAdding Snack: ";
	addCons(listSnack, savedItems);
	cout << "\nFinished Adding Snack: ";

	cout << "\nShowing Meal: ";
	listMeal[0].showCons();
	cout << "\nDone Showing Meal:";

	cout << "Showing Snack: ";
	listSnack[0].showCons();
	cout << "\nDone Showing Snack: ";

	cout << endl << endl;
	system("pause");
	return 0;
}

int getItem(vector<FoodItem>& list) {
	
	string name;

	cout << "\nPlease enter the name of the food: ";
	getline(cin, name);
	int found = checkList(name, list);
	
	if (found < 0) {
		
		cout << "\nYou have not entered the information for " << name << " yet.\n";
		addItem(list, name);
		return list.size() - 1;

	}
	else {
		return found;
	}

}

int checkList(const string &search, const vector<FoodItem>& list) {

	int isInList = -1; //-1 for not found

	for (int i = 0; i < list.size(); i++) {
		if (search == list[i].name) {
			isInList = i;
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
	
	charCheck(holdUnit, convUnit, 'c', 'g');

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

int intCheck(const string& test) {
	for (int i = 0; i < test.length(); i++) {
		if (!isdigit(test.at(i))) {
			return 0;
		}
	}
	return stoi(test);

}

void intErr(string& test) {
	cout << "\nError: " << test << " is not a valid option. Please enter a positive whole number (ex. 100): ";
	getline(cin, test);
}

void charCheck(string& inp, char& test, char x, char y) {
	while (test != x && test != y) {
		cout << "\nError: " << inp << " is not a valid option. Please enter either c for Cups or g for Grams: ";
		getline(cin, inp);
		test = tolower(inp.at(0));
	}
}

void cupGram(char unit) {
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

void addCons(vector<Meal>& listM, vector<FoodItem>& listFI) {

	Meal temp;
	char again = 'n';

	do {
		temp.addItem(listFI[getItem(listFI)]);
		cout << "\nAdd another food to the meal? (y for Yes, n for No)";
		string holdAgain;
		char again;
		getline(cin, holdAgain);
		again = tolower(holdAgain.at(0));
		charCheck(holdAgain, again, 'y', 'n');
	} while (again != 'n');

	listM.push_back(temp);
}

void addCons(vector<Snack>& listS, vector<FoodItem>& listFI) {

	Snack temp;
	char again = 'n';

	do {
		temp.addItem(listFI[getItem(listFI)]);
		string holdAgain;
		char again;
		cout << "\nAdd another food to the snack? (y for Yes, n for No): ";
		getline(cin, holdAgain);
		again = tolower(holdAgain.at(0));
		charCheck(holdAgain, again, 'y', 'n');
	} while (again != 'n');

	temp.setHealthy();

	listS.push_back(temp);
}
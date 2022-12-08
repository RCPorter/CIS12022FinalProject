/*
->Author: Robert C. Porter
->Class: 22.FA.CIS.1202.502 C++ Software Development
->Date: MM.DD.YY
->Assignment: ASSIGNMENT NAME
*/
#include "Meal.h"
#include "Snack.h"
#include <fstream>

int getItem(vector<FoodItem>& savedList, vector<string>& savedName);
int checkList(const string& search, const vector<FoodItem>& savedList, const vector<string>& savedName);
void addItem(vector<FoodItem>& savedList, vector<string>& savedName, string newName);
int intCheck(const string& test);
void intErr( string& test);
void charCheck(string& inp, char& test, char x, char y);
void cupGram(char unit);
void addCons(vector<Meal>& listM, vector<FoodItem>& listFI, vector<string>& listN);
void addCons(vector<Snack>& listS, vector<FoodItem>& listFI, vector<string>& listN);
//void readSave(vector<FoodItem>& list);
//void writeSave(vector<FoodItem>& list);

int main() {

	vector<FoodItem> savedItems;
	vector<string> savedNames;
	/*readSave(savedItems);*/
	
	vector<Meal> listMeal;
	vector<Snack> listSnack;

	cout << "\nAdding Meal: ";
	addCons(listMeal, savedItems, savedNames);
	cout << "\nFinished Adding Meal: ";

	cout << "\nAdding Snack: ";
	addCons(listSnack, savedItems, savedNames);
	cout << "\nFinished Adding Snack: ";

	cout << "\nShowing Meal: ";
	listMeal[0].showCons();
	cout << "\nDone Showing Meal:";

	cout << "Showing Snack: ";
	listSnack[0].showCons();
	cout << "\nDone Showing Snack: ";

	/*writeSave(savedItems);*/
	
	cout << endl << endl;
	system("pause");
	return 0;
}

int getItem(vector<FoodItem>& savedList, vector<string>& savedName) {
	
	string name;

	cout << "\nPlease enter the name of the food: ";
	getline(cin, name);
	int found = checkList(name, savedList, savedName);
	
	if (found < 0) {
		
		cout << "\nYou have not entered the information for " << name << " yet.\n";
		addItem(savedList, savedName, name);
		return savedList.size() - 1;

	}
	else {
		return found;
	}

}

int checkList(const string &search, const vector<FoodItem>& savedList, const vector<string>& savedName) {

	int isInList = -1; //-1 for not found

	for (int i = 0; i < savedList.size(); i++) {
		if (search == savedName[i]) {
			isInList = i;
		}
	}

	return isInList;

}

void addItem(vector<FoodItem>& savedList, vector<string>& savedName, string newName) {

	FoodItem temp;

	string holdUnit; //g for Gram, c for Cup
	char convUnit;
	cout << "\nPlease enter which unit you will use for " << newName << " (g for per Gram, c for per Cup) : ";
	getline(cin, holdUnit);
	convUnit = tolower(holdUnit.at(0));
	
	charCheck(holdUnit, convUnit, 'c', 'g');

	string holdCals;
	int convCals;
	cout << "\nPlease enter how many caleries are in a ";
	cupGram(convUnit);
	cout << " of " << newName << ": ";
	getline(cin, holdCals);
	convCals = intCheck(holdCals);
	while (!convCals) {
		intErr(holdCals);
		convCals = intCheck(holdCals);
	}

	temp = { convUnit, convCals };
	savedList.push_back(temp);
	savedName.push_back(newName);
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
		cout << "\nError: " << inp << " is not a valid option. Please enter either " << x << " or " << y << ": ";
		getline(cin, inp);
		test = tolower(inp.at(0));
	}
}

void cupGram(char unit) {
	if (unit == 'g') {
		cout << "Gram";
	}
	else if (unit == 'c') {
		cout << "Cup";
	}
	else {
		cout << "Critical Unit Error";
	}
}

void addCons(vector<Meal>& listM, vector<FoodItem>& listFI, vector<string>& listN) {

	Meal temp;
	int sub;
	char again = 'n';

	do {
		sub = getItem(listFI, listN);
		temp.addItem(listFI[sub], listN[sub]);
		cout << "\nAdd another food to the meal? (y for Yes, n for No)";
		string holdAgain;
		getline(cin, holdAgain);
		again = tolower(holdAgain.at(0));
		charCheck(holdAgain, again, 'y', 'n');
	} while (again != 'n');

	listM.push_back(temp);
}

void addCons(vector<Snack>& listS, vector<FoodItem>& listFI, vector<string>& listN) {

	Snack temp;
	int sub;
	char again = 'n';

	do {
		sub = getItem(listFI, listN);
		temp.addItem(listFI[sub], listN[sub]);
		string holdAgain;
		cout << "\nAdd another food to the snack? (y for Yes, n for No): ";
		getline(cin, holdAgain);
		again = tolower(holdAgain.at(0));
		charCheck(holdAgain, again, 'y', 'n');
	} while (again != 'n');

	temp.setHealthy();

	listS.push_back(temp);
}

//void readSave(vector<FoodItem>& list) {
//	fstream totFile("Total.txt", ios::in);
//	int totalSavedItems = 0;
//	totFile >> totalSavedItems;
//	cout << "\n\nTotalSavedItems: " << totalSavedItems;
//	totFile.close();
//	fstream saveFile("FoodItems.dat", ios::in | ios::binary);
//	if (!saveFile) {
//		cout << "\n\nError opening file. Program Aborting.";
//		exit(EXIT_FAILURE);
//	}
//	FoodItem temp;
//	for (int i = 0; i < totalSavedItems; i++) { 
//		saveFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
//		list.push_back(temp);
//		cout << endl << i << " : " << list[i].unit << " : " << list[i].calPerUnit;
//	}
//	saveFile.close();
//}
//
//void writeSave(vector<FoodItem>& list) {
//	fstream totFile("Total.txt", ios::out);
//	totFile << list.size();
//	totFile.close();
//	fstream saveFile("FoodItems.dat", ios::out | ios::binary);
//	for (int i = 0; i < list.size(); i++) {
//		saveFile.write(reinterpret_cast<char*>(&list[i]), sizeof(list[i]));
//	}
//	saveFile.close();
//}
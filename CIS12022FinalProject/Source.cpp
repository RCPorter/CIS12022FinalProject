/*
->Author: Robert C. Porter
->Class: 22.FA.CIS.1202.502 C++ Software Development
->Date: MM.DD.YY
->Assignment: ASSIGNMENT NAME
*/
#include "Meal.h"
#include "Snack.h"
#include <fstream>
#include <cmath>
#include <iomanip>

//Main Functions
int getMenuSelect();//92-142
void addCons(vector<Meal>& listM, vector<FoodItem>& listFI, vector<string>& listN);//144-162
void addCons(vector<Snack>& listS, vector<FoodItem>& listFI, vector<string>& listN);//164-184
void showList(const vector<FoodItem>& savedList, const vector<string>& savedName);//186-194
void showAvgCal(vector<Meal>& list);//196-212
void showPerc(vector<Snack>& list);//214-232
void showEoDFact(vector<Meal>& listM, vector<Snack>& listS);//234-253

//File Functions
void readSave(vector<FoodItem>& savedList, vector<string>& savedName);//255-289
void writeSave(vector<FoodItem>& savedList, vector<string>& savedName);//291-311

//Secondary Functions
int getItem(vector<FoodItem>& savedList, vector<string>& savedName);//313-332
void addItem(vector<FoodItem>& savedList, vector<string>& savedName, string newName);//334-362
void showList(vector<Meal>& list);//364-371
void showList(vector<Snack>& list);//373-380
int checkList(const string& search, const vector<FoodItem>& savedList, const vector<string>& savedName);//382-394
void cupGram(char unit);//396-408

//Input Verification Functions
int intCheck(const string& test);//410-419
void charCheck(string& inp, char& test, char x, char y);//421-429

//Input Error Functions
void intErr( string& test);//431-436
void inpErr(string inp, int numSel);//438-443


int main() {

	vector<FoodItem> savedItems;//Hold saved list of FoodItems
	vector<string> savedNames;//Hold saved list of Names
	readSave(savedItems, savedNames);//Read Saved FoodItems and Names from files
	
	vector<Meal> listMeal;//Hold list of meals for the day
	vector<Snack> listSnack;//Hold list of Snacks for the day

	cout << setprecision(2) << fixed;

	int menSel;//Hold menu select
	do {

		menSel = getMenuSelect();

		switch (menSel) {

		case(1):
			addCons(listMeal, savedItems, savedNames);
			break;
		case(2):
			addCons(listSnack, savedItems, savedNames);
			break;
		case(3):
			showList(savedItems, savedNames);
			break;
		case(4):
			showAvgCal(listMeal);
			break;
		case(5):
			showPerc(listSnack);
			break;
		case(6):
			showEoDFact(listMeal, listSnack);
			break;

		}

	} while (menSel != 6);

	writeSave(savedItems, savedNames);
	
	cout << endl << endl;
	system("pause");
	return 0;

}

int getMenuSelect() {

	string select;
	const int NUM_SEL = 6;

	cout << setprecision(2) << fixed;

	cout << "\nMain Menu:\n"
		<< "\nOption 1: Add Meal"
		<< "\nOption 2: Add Snack"
		<< "\nOption 3: See List of Food Items"
		<< "\nOption 4: Show Average Calories Per Meal"
		<< "\nOption 5: Show What Percentage of Snacks Have Been Healthy"
		<< "\nOption 6: Show End of Day Facts and Exit Program\n"
		<< "\nPlease choose a Menu Option: ";
	getline(cin, select);

	bool inpCor = false;

	while (!inpCor) {

		if (select.size() > 1) {
			inpCor = false;
			inpErr(select, NUM_SEL);
			getline(cin, select);
			cout << endl;
		}

		else if (!isdigit(select.at(0))) {
			inpCor = false;
			inpErr(select, NUM_SEL);
			getline(cin, select);
			cout << endl;
		}

		else if (stoi(select) <= 0 || stoi(select) > NUM_SEL) {
			inpCor = false;
			inpErr(select, NUM_SEL);
			getline(cin, select);
			cout << endl;
		}

		else {
			inpCor = true;
		}

	}

	return stoi(select);

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

void showList(const vector<FoodItem>& savedList, const vector<string>& savedName) {

	cout << endl;
	for (int i = 0; i < savedList.size(); i++) {
		cout << endl << savedName[i] << ": " << savedList[i].calPerUnit << " Calories Per ";
		cupGram(savedList[i].unit);
	}

}

void showAvgCal(vector<Meal>& list) {

	double total = 0.0;

	if (list.size() > 0) {

		for (int i = 0; i < list.size(); i++) {
			total += list[i].getTotalCals();
		}

		cout << "\n\nAverage Calories Per Meal: " << total / list.size();
	}
	else {
		cout << "\n\nAverage Calories Per Meal: 0.00";
	}

}

void showPerc(vector<Snack>& list) {

	int total = 0;
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getHealthy()) {
			total++;
		}
	}

	double perc = ((double)total / (list.size())) * 100;
	cout << endl << endl << perc << "% of Snacks have been Healthy.";
	if (perc < 50) {
		cout << "\nTry eating more healthy snacks tomorrow.";
	}
	else {
		cout << "\nKeep it up!";
	}

}

void showEoDFact(vector<Meal>& listM, vector<Snack>& listS) {

	cout << "\nMeals Eaten Today: ";
	showList(listM);
	cout << "\nSnacks Eaten Today: ";
	showList(listS);

	if (listS.size() > listM.size()) {
		cout << "\nYou have eaten more snacks than meals today."
			<< "\nTry eating fewer snacks tomorrow.";
	}

	if (listM.size() > 3) {
		cout << "\nYou have eaten more than three meals today."
			<< "\nTry eating fewer meals tomorrow.";
	}

	cout << "\nFun Fact: The Square Root of the Total Calories of your first meal of the day is " << sqrt(listM[0].getTotalCals());

}

void readSave(vector<FoodItem>& savedList, vector<string>& savedName) {

	fstream totFile("Total.txt", ios::in);
	if (!totFile) {
		cout << "\n\nError opening file. FileName: Total.txt. Program Aborting.";
		exit(EXIT_FAILURE);
	}
	int totalSavedItems = 0;
	totFile >> totalSavedItems;
	totFile.close();

	fstream saveName("Names.txt", ios::in);
	if (!saveName) {
		cout << "\n\nError opening file. FileName: Name.txt. Program Aborting.";
		exit(EXIT_FAILURE);
	}
	string tempN;
	for (int i = 0; i < totalSavedItems; i++) {
		getline(saveName, tempN);
		savedName.push_back(tempN);
	}
	saveName.close();

	fstream saveFile("FoodItems.dat", ios::in | ios::binary);
	if (!saveFile) {
		cout << "\n\nError opening file. FileName: FoodItems.dat Program Aborting.";
		exit(EXIT_FAILURE);
	}
	FoodItem tempFI;
	for (int i = 0; i < totalSavedItems; i++) {
		saveFile.read(reinterpret_cast<char*>(&tempFI), sizeof(tempFI));
		savedList.push_back(tempFI);
	}
	saveFile.close();
}

void writeSave(vector<FoodItem>& savedList, vector<string>& savedName) {

	fstream totFile("Total.txt", ios::out);//Contains total number of items in the parallel lists to prevent .eof() issues
	int total = savedList.size();
	totFile << total;
	totFile.close();

	fstream saveName("Names.txt", ios::out);//Contains names, strings do not work in binary file operations
	for (int i = 0; i < total; i++) {
		saveName << savedName[i] << endl;

	}
	saveName.close();

	fstream saveFile("FoodItems.dat", ios::out | ios::binary);//Contains FoodItems
	for (int i = 0; i < total; i++) {
		saveFile.write(reinterpret_cast<char*>(&savedList[i]), sizeof(savedList[i]));
	}
	saveFile.close();

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
	cout << "\nPlease enter how many calories are in a ";
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

void showList(vector<Meal>& list) {

	cout << endl;
	for (int i = 0; i < list.size(); i++) {
		list[i].showCons();
	}

}

void showList(vector<Snack>& list) {

	cout << endl;
	for (int i = 0; i < list.size(); i++) {
		list[i].showCons();
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

int intCheck(const string& test) {

	for (int i = 0; i < test.length(); i++) {
		if (!isdigit(test.at(i))) {
			return 0;
		}
	}
	return stoi(test);

}

void charCheck(string& inp, char& test, char x, char y) {

	while (test != x && test != y) {
		cout << "\nError: " << inp << " is not a valid option. Please enter either " << x << " or " << y << ": ";
		getline(cin, inp);
		test = tolower(inp.at(0));
	}

}

void intErr(string& test) {

	cout << "\nError: " << test << " is not a valid option. Please enter a positive whole number (ex. 100): ";
	getline(cin, test);

}

void inpErr(string inp, int numSel) {

	cout << "\nError: " << inp << " is not a valid selection.\n"
		<< "Please choose from the Available Menu Options (1 - " << numSel << "): ";

}
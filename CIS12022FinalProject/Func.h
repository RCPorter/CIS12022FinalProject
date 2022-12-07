#ifndef FUNC_H
#define FUNC_H
#include <string>
#include <iostream>

using namespace std;

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

#endif FUNC_H
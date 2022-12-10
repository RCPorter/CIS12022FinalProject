#include "Snack.h"

void Snack::setHealthy() {

	string choice;
	char convChoice;
	cout << "\nWas this a healthy snack? (y for Yes, n for No): ";
	getline(cin, choice);

	convChoice = tolower(choice.at(0));

	while (convChoice != 'y' && convChoice != 'n') {
		cout << "\nError: " << choice << " is not a valid option. Please enter either y for Yes or n for No: ";
		getline(cin, choice);
		convChoice = tolower(choice.at(0));
	}

	if (convChoice == 'y') {
		healthy = true;
	}
	else {
		healthy = false;
	}

}

void Snack::showCons() {

	cout << endl;
	for (int i = 0; i < ate.size(); i++) {
		showItem(i);
	}
	if (healthy) {
		cout << "\nThis Snack was healthy!";
	}
	else {
		cout << "\nThis Snack was NOT healthy!";
	}

}
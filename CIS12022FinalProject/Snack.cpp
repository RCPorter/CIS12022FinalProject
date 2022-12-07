#include "Snack.h"

void Snack::setHealthy() {
	string choice;
	char convChoice;
	cout << "Was this a healthy snack? (y for Yes, n for No): ";
	getline(cin, choice);

	convChoice = tolower(choice.at(0));

	while (convChoice != 'c' && convChoice != 'g') {
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
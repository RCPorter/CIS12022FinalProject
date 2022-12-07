#include "Meal.h"

int Meal::getTotalCals() {
	
	int total = 0;

	for (int i = 0; i < ate.size(); i++) {

		total += itemCal(i);

	}
	return total;
}

void Meal::showCons() {
	for (int i = 0; i < ate.size(); i++) {
		showItem(i);
	}
	cout << "\nTotal Caleries in Meal: " << getTotalCals();
}
#include "Meal.h"

double Meal::getTotalCals() {
	
	double total = 0.0;

	for (int i = 0; i < ate.size(); i++) {

		total += itemCal(i);

	}
	return total;

}

void Meal::showCons() {

	cout << endl;
	for (int i = 0; i < ate.size(); i++) {
		showItem(i);
	}
	cout << "\nTotal Calories in Meal: " << getTotalCals();

}
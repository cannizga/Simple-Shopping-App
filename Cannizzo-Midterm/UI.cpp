#include "UI.h"

void UI::Options() {
	cout << "---------------------------------------\n(1) Pickup\n(2) Delivery\n(3) Admin Login\n(6) Exit\n---------------------------------------" << endl;
}

void UI::MainMenu() {
	cout << "---------------------------------------\n(1) Fresh Produce\n(2) Meat and Seafood\n(3) Frozen Foods\n(5) Check Out\n(6) Exit\n---------------------------------------" << endl;
}

void UI::DisplayPoundItems(string name1, string name2, string name3, double price1, double price2, double price3) {
	cout << "---------------------------------------\n(1) " <<  name1 << " $" << price1 << " / lb\n(2) " << name2 << " $" << price2 <<  " / lb\n(3) " << name3 << " $" << price3 << " / lb\n\n(4) Back\n(6) Exit\n-------------------------------------- - " << endl;
}

/*void UI::MeatSeaItems(char name1[30], char name2[30], char name3[30], double price1, double price2, double price3) {
	cout << "---------------------------------------\n(1) " << name1 << " $" << price1 << " / lb\n(2) " << name2 << " $" << price2 << " / lb\n(3) " << name3 <<" $" << price3 << " / lb\n\n(4) Back\n(5) Exit\n-------------------------------------- - " << endl;
}*/

void UI::FrozenItems(string name1, string name2, string name3, double price1, double price2, double price3) {
	cout << "---------------------------------------\n(1) " << name1 << " $" << price1 << "\n(2) " << name2 << " $" << price2 << "\n(3) " << name3 << " $" << price3 << "\n\n(4) Back\n(6) Exit\n-------------------------------------- - " << endl;
}

void UI::Checkout(string name, double price, double num, double basePrice) {
		cout << left << setw(14) << name << ": " << "$" << fixed << setprecision(2)<< price << "\n" << num << " @ $" << fixed << setprecision(2) << basePrice << "\n";
}

void UI::TotalPrice(double totalPrice, bool deliver, double tip, double deliveryFee, bool Tip) {
	if (deliver) {
		cout << "------------\n"; 
		cout << left << setw(14) << "Tip" << ": " << "$" << fixed << setprecision(2) << tip << endl;
		cout << left << setw(14) << "Delivery" << ": " << "$" << fixed << setprecision(2) << deliveryFee;
		cout << "\n------------\n";
		cout << left << setw(14) << "Total" << ": " << "$" << fixed << setprecision(2) << totalPrice;
		cout << "\n------------";
	}
	else {
		if (Tip) {
			cout << "------------\n";
			cout << left << setw(14) << "Tip" << ": " << "$" << fixed << setprecision(2) << tip << endl;
			cout << "\n------------\n";
			cout << left << setw(14) << "Total" << ": " << "$" << fixed << setprecision(2) << totalPrice << "\n------------" << endl;
		}
		else {
			cout << "\n------------\n";
			cout << left << setw(14) << "Total" << ": " << "$" << fixed << setprecision(2) << totalPrice << "\n------------" << endl;
		}
	}
}
void UI::ThankYou() {
	cout << "\nThanks For Your Order!!!\nWe Will Begin To Process Your Order" << endl;
}
void UI::GoodBye() {
	cout << "Goodbye!!!!\nHave A Good Day!! :)" << endl;
}

void UI::Error() {
	cout << "Error!!!! Invalid Input" << endl;
}

void UI::Weight(string itemName) {
	cout << "Enter The Weight In Pounds Of " << itemName << " That You Would Like To Purchase" << endl;
}

void UI::Quantity(string itemName) {
	cout << "Enter The Amount Of " << itemName << " That You Would Like To Purchase" << endl;
}

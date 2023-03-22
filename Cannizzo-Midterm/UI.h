#include <iostream>
#include <iomanip>
using namespace std;
class UI {
public:
	void Options();
	void MainMenu();
	void DisplayPoundItems(string name1, string name2, string name3, double price1, double price2, double price3);
	void FrozenItems(string name1, string name2, string name3, double price1, double price2, double price3);
	void Checkout(string name, double price, double num, double basePrice);
	void TotalPrice(double totalPrice, bool deliver, double tip, double deliveryFee, bool Tip);
	void ThankYou();
	void GoodBye();
	void Error();
	void Weight(string itemName); // In Pounds
	void Quantity(string itemName);
};


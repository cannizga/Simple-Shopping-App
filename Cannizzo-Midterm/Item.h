#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Item {
public:
	Item(double price, string name);
	Item();
	double getDelivery();
	double getPrice();
	double getBasePrice();
	double getTip();
	double getNumItems();
	double getTotalPrice();
	string getName();
	vector <Item*> getList();
	void setDelivery(double val);
	void setPrice(double val);
	void setBasePrice(double price);
	void setTip(double val);
	void setNumItems(double num);
	void setTotalPrice(double val, bool deliver, double tip);
	void setName(string val);
private:
	double price = 0;
	double basePrice = 0;
	double totalPrice = 0;
	static double delivery;
	static double tip;
	double numItems = 0;
	//vector <Item*> List;
	string name;
};

class AdminLogin : public Item {
public:
	void setUserName(char User[30]);
	void setPassword(char Password[30]);
	char* getUserName();
	char* getPassword();
	void adminLogin();
	AdminLogin(char Username[30], char PassWord[30]);
	AdminLogin();
	vector <AdminLogin*> AdminList;
private:
	char userName[30] = "", password[30] = "";
};

class ItemList : public Item {
public:
	ItemList();
	ItemList(string name, double price);
	bool getBack();
	void setBack(bool back);
	void openFile();
	void readFile();
	void updateList(vector <ItemList*> itemList);
	void editFile(vector <ItemList*> itemList);
	void diplayList(vector <ItemList*> itemList);
	vector <ItemList*> List;
private:
	bool goBack = false;
};

class FreshProduce : public Item {
public:
	FreshProduce(double price, string name, double num, double basePrice);
	FreshProduce(string name);
	FreshProduce(double price);
	FreshProduce();
	double getPounds();
	void calcPrice(double pounds, double price);
	void setPounds(double val);
private:
	double pounds = 0;
};

class MeasuredProduct : public Item {
public:
	MeasuredProduct(double price, string name, double num, double basePrice);
	MeasuredProduct();
	double getQuantity();
	void calcPrice(double quantity, double price);
	void setQuantity(double val);
private:
	double quantity = 0;
};


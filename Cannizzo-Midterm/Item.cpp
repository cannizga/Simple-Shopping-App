#include "Item.h"
#include <string>

Item::Item(double Price, string Name) {
    price = Price;
    name = Name;
    
}

Item::Item() {

}

double Item::getDelivery() {
    return delivery;
}

double Item::getPrice() {
    return price;
}

double Item::getBasePrice() {
    return basePrice;
}

double Item::getTip() {
    return tip;
}

double Item::getNumItems() {
    return numItems;
}

double Item::getTotalPrice() {
    return totalPrice;
}

string Item::getName() {
    return name;
}

void AdminLogin::adminLogin() {
    ItemList start;
    string fileData;
    int findIndex;
    char convertToChar[30], convertToChar2[30];
    char userNam[30];
    char passWord[30];
    bool match = false;
    char Loop = 'y';
    string file = "Admin-Logins.txt";

    ifstream fileRead;
    fileRead.open(file, ios::in);
    if (fileRead.is_open()) {
        while (!fileRead.eof()) {
                for (int j = 0; j < 2; j++) { // Copy the username and password to the same index so that we can compare those together to login
                    getline(fileRead, fileData);
                    if (j == 0) {
                        strcpy_s(convertToChar, fileData.c_str());
                    }
                    else if (j == 1) {
                        strcpy_s(convertToChar2, fileData.c_str());
                    }
                }
                AdminList.push_back(new AdminLogin(convertToChar, convertToChar2));
        }
    }
    else {
        cout << "could not open file!!!" << endl;
    }
    /*for (int index = 0; index < AdminList.size(); index++) {
        cout << "Username: " << AdminList[index]->getUserName() << "\nPassword: " << AdminList[index]->getPassword() << "\n" << endl;  (DEBUGGING)
    }*/

    while (Loop == 'y') {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Username: ";
        cin.getline(userNam, 30); // Using getline to avoid errors from spaces in names

        cout << "Enter Password: ";
        cin.getline(passWord, 30);

        for (int check = 0; check < AdminList.size(); check++) {
   
            if (strcmp(userNam, AdminList[check]->getUserName()) == 0 && strcmp(passWord, AdminList[check]->getPassword()) == 0) { 
                // Compare indexes to see if the username and password match. This should only work if they are on the same index one username 0 and password 0 should work together
                findIndex = check; 
                Loop = 'n';
                match = true;
                printf("\033c");
                break;
            }
            else {
                match = false;
            }
        }

        if (!match) {
            cout << "\nInvalid Username or Password\n" << endl;
        }
    }

    cout << "Login Successful!!\nLogged in as " << AdminList[findIndex]->getUserName() << "\n" << endl;
    start.openFile();
}


void Item::setDelivery(double val) {
    delivery = val;
}

double Item::delivery = 0;

double Item::tip = 0;

void Item::setName(string val) {
    name = val;
}

ItemList::ItemList() {
}

ItemList::ItemList(string name, double price) {
    setName(name);
    setPrice(price);
}

bool ItemList::getBack() {
    return goBack;
}

void ItemList::setBack(bool back) {
    goBack = back;
}

void ItemList::openFile() {
    string fileData, copyName;
    double convertDouble;
    string file = "Item-List.txt";

    ifstream fileRead;
    fileRead.open(file, ios::in);
    if (fileRead.is_open()) {
        while (!fileRead.eof()) {
           for (int j = 0; j < 2; j++) {
             getline(fileRead, fileData);
             
             if (j == 0) { // Copy every two lines in order to get both the name and price in the same index
                copyName = fileData;
             }
                else if (j == 1) {
                  convertDouble = stod(fileData);
                        
                }
           }
             List.push_back(new ItemList(copyName, convertDouble)); // Get the name of the food item and the price in which we will have to convert to a double
        
        }
    }
    else {
        cout << "could not open file!!!" << endl;
    }
    for (int index = 0; index < List.size(); index++) { // Print out the entire items list
        cout << "(" << index << ") " << List[index]->getName() << " $" << List[index]->getPrice() << "\n" << endl;
    }
    editFile(List);
}

void ItemList::readFile() {
    string fileData, copyName;
    double convertDouble;
    string file = "Item-List.txt";

    ifstream fileRead;
    fileRead.open(file, ios::in);
    if (fileRead.is_open()) {
        while (!fileRead.eof()) {
            for (int j = 0; j < 2; j++) {
                getline(fileRead, fileData);

                if (j == 0) { // Copy every two lines in order to get both the name and price in the same index
                    copyName = fileData;
                }
                else if (j == 1) {
                    convertDouble = stod(fileData);

                }
            }
            List.push_back(new ItemList(copyName, convertDouble)); // Get the name of the food item and the price in which we will have to convert to a double
        }
    }
    else {
        cout << "could not open file!!!" << endl;
    }
}

void ItemList::updateList(vector<ItemList*> itemList) {
    string fileName = "Item-List.txt";
    ofstream file;
    file.open(fileName); // Open the text file
    for (int i = 0; i < itemList.size(); i++) {
        for (int f = 0; f < 2; f++) {
            if (f == 0) { // In the same way we had to put two lines in the same index we now need to separate those lines apart again in order to get the name and price on their own lines
                file << itemList[i]->getName() << endl;
            }
            else if (f == 1) {
                if (i == itemList.size() - 1) { // So We don't have an empty line at the end of the text file
                    file << itemList[i]->getPrice();
                }
                else {
                    file << itemList[i]->getPrice() << endl; // If we ended up writing to the file like this we would have an empty line at the bottom
                }
            }
        }
    }
    file.close();
}

void ItemList::editFile(vector<ItemList*> itemList) {
    bool finish = false;
    char state = 'y', state2 = 'y';
    int input;
    while (state == 'y') {
        try {
            cout << "(0) Edit\n(1) Display Item List\n(2) Logout (Make Sure To Logout To Update The List)" << endl;
            cin >> input;
            if (cin.fail() || input > 2) {
                throw exception("\nInvalid Input\n");
            }
        }
        catch (exception e) {
            char correct = 'n';
            while (correct == 'n') {
                cin.clear(); // Clears error flags
                cin.ignore();
                cout << "(0) Edit\n(1) Display Item List\n(2) Logout (Make Sure To Logout To Update The List)" << endl;
                cin >> input;
                if (cin.fail() || input > 2) {
                    cout << "\nInvalid Input\n" << endl;
                    correct = 'n';
                }
                else {
                    correct = 'y';
                }
            }
        }
        state2 = 'y';
        while (state2 == 'y') {
            switch (input) {
            case 0: // EDIT ITEM
                int in;
                int options;
                try {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "What Item Would You Like To Edit? (EX: type in the number of the item if its the first item type 0) (Type (-1) To Go Back)";
                    cin >> in;
                    if (cin.fail() || in > itemList.size() - 1) {
                        if (in == -1) {
                            state2 = 'n';
                            break;
                        }
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw exception("\nItem either doesn't exist or the input was invalid\n");
                    }
                    else {
                        finish = true;
                        // Do Nothing
                    }
                }
                catch (exception e) {
                    char correct = 'n';
                    while (correct == 'n') {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "What Item Would You Like To Edit? (EX: type in the number of the item if its the first item type 0) (Type (-1) To Go Back)";
                        cin >> in;
                        if (cin.fail() || in > itemList.size() - 1 ) {
                            cout << "\nItem either doesn't exist or the input was invalid\n" << endl;
                            correct = 'n';
                            finish = false;
                            break;
                        }
                        else if (in == -1) {
                            state2 = 'n';
                            break;
                        }
                        else {
                            finish = true;
                            correct = 'y';
                        }
                    }
                }

                if (finish) {
                    cout << "Editing Item " << itemList[in]->getName() << "\nOptions\n (0) Change Item Name\n (1) Change Item Price\n (2) Set Discount On Item\n (3) Back" << endl;
                    cin >> options;
                }

                switch (options) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                case 0: // CHANGE ITEM NAME
                    char name[30];
                    try {
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "What would you like to rename " << itemList[in]->getName() << " to?" << endl;
                        cin.getline(name, 30);

                       if (isdigit(name[0])) { // We don't want numbers to be entered here only letters/characters
                         throw exception("\nNo Numbers Please\n");
                       }
                       else {
                           itemList[in]->setName(name);
                           cout << "Item Renamed To: " << itemList[in]->getName() << endl;
                       }
                    }
                    catch (exception e) {
                        char correct = 'n';
                        while (correct == 'n') {
                            cout << "What would you like to rename " << itemList[in]->getName() << " to?" << endl;
                            cin.getline(name, 30);

                            if (!isdigit(name[0])) {
                                correct = 'y';
                                itemList[in]->setName(name);
                                cout << "Item Renamed To: " << itemList[in]->getName() << endl;
                            }
                            else {
                                cout << "\nNo Numbers Please\n"<< endl;
                                correct = 'n';
                            }
                        }
                    }
                    break;
                case 1: // CHANGE ITEM PRICE
                    double price;
                    try {
                        cout << "What would you like to change the price of " << itemList[in]->getName() << " to?" << endl;
                        cin >> price;
                        if (cin.fail()) {
                            throw exception("\nOnly Numbers Are Allowed!!\n");
                        }
                        else { 
                            itemList[in]->setPrice(price);
                            cout << "Item Price Changed To: $" << itemList[in]->getPrice() << endl;
                        }
                    }
                    catch (exception e) {
                        char correct = 'n';
                        while (correct == 'n') {
                            cout << "What would you like to rename the item to?";
                            cin >> name;
                            if (!cin.fail()) {
                                correct = 'y';
                                itemList[in]->setPrice(price);
                                cout << "Item Price Changed To: $" << itemList[in]->getPrice() << endl;
                            }
                            else {
                                cout << "\nOnly Numbers Are Allowed!!\n" << endl;
                                correct = 'n';
                            }
                        }
                    }
                    break;
                case 2: // SET DISCOUNT
                    double discountVal, discountBy, itemPrice;
                    try {
                        cout << "(Note: Use Decimals. EX: .2 is 20%)\nBy How Much Would You Like To Discount " << itemList[in]->getName() << ": ";
                        cin >> discountVal;
                        if (discountVal < 0 || discountVal > .9) {
                            cout << "\nDiscount Too High Or Too Low\n" << endl;
                            throw exception("\nDiscount Too High Or Too Low\n");
                        }
                        else {
                            discountBy = itemList[in]->getPrice() * discountVal;
                            itemPrice = itemList[in]->getPrice() - discountBy;
                            itemList[in]->setPrice(itemPrice);
                            cout << "Price of item after discount: " << itemList[in]->getPrice() << "\n" << endl;
                        }
                    }
                    catch (exception e) {
                        char correct = 'n';
                        while (correct == 'n') {
                            cout <<  "(Note: Use Decimals. EX: .2 is 20%)\nBy How Much Would You Like To Discount " << itemList[in]->getName() << ": ";
                            cin >> discountVal;
                            if (discountVal < 0 || discountVal > .9) {
                                cout << "\nDiscount Too High Or Too Low\n" << endl;
                                correct = 'n';
                            }
                            else {
                                discountBy = itemList[in]->getPrice() * discountVal; // We multiply the decimal input then subtract that from the price of the item to discount it
                                itemPrice = itemList[in]->getPrice() - discountBy;
                                itemList[in]->setPrice(itemPrice);
                                cout << itemList[in]->getPrice();
                                correct = 'y';
                            }
                        }
                    }
                    break;
                case 3: // BACK
                    state2 = 'y';
                    break;
                }
                break;
            case 1: // DISPLAY LIST
                diplayList(itemList);
                state2 = 'n';
                break;
            case 2: // LOGOUT
                goBack = true;
                updateList(itemList); // Update the edits we did to the text file
                state2 = 'n';
                state = 'n';
            }
        }
    }
}

void ItemList::diplayList(vector<ItemList*> itemList) { // Universal vector read method kind of.
    for (int index = 0; index < itemList.size(); index++) {
        cout << "(" << index << ") " << itemList[index]->getName() << " $" << itemList[index]->getPrice() << "\n" << endl;
    }
}

void Item::setPrice(double val) {
    price = val;
}

void Item::setBasePrice(double price) {
    basePrice = price;
}

void Item::setTip(double val) {
    tip = val; 
}

void Item::setNumItems(double num) {
    numItems = num;
}

void Item::setTotalPrice(double val, bool deliver, double tip) {
    setTip(tip);
    if (deliver) { // If delivery is selected we grab our boolean value from the main and determine if our delivery and tip values are set
        setDelivery(20);
    }
    totalPrice = val + getDelivery() + getTip(); // If our delivery value is 0 and our tip value is 0 this wont do much of anything except set the total price of what was bought
}

void AdminLogin::setUserName(char* User) {
    strcpy_s(userName, User);
}

void AdminLogin::setPassword(char* Password) {
    strcpy_s(password, Password);
}

char* AdminLogin::getUserName() {
    return userName;
}

char* AdminLogin::getPassword() {
    return password;
}

AdminLogin::AdminLogin(char UserName[30], char PassWord[30]) {
        setUserName(UserName);
        setPassword(PassWord);
}

AdminLogin::AdminLogin() {
}

FreshProduce::FreshProduce(double price, string name, double num, double basePrice) { // Set the price and name of the product upon instantiation
    setPrice(price);
    setName(name);
    setNumItems(num);
    setBasePrice(basePrice);
}

FreshProduce::FreshProduce(string name) {
    setName(name);
    //double convertDouble = stod(copy);
}

FreshProduce::FreshProduce(double price) {
    setPrice(price);
}

FreshProduce::FreshProduce() {
    // BLANK
}

double FreshProduce::getPounds() {
    return pounds;
}

void FreshProduce::calcPrice(double pounds, double price) {
    setPrice(pounds * price); // Take the pounds and multiply it by the price of the product
}

void FreshProduce::setPounds(double val) {
    pounds = val;
}

MeasuredProduct::MeasuredProduct(double price, string name, double num, double basePrice) { // Set the price and name of the product upon instantiation
    setPrice(price);
    setName(name);
    setNumItems(num);
    setBasePrice(basePrice);
}

MeasuredProduct::MeasuredProduct() {
    // BLANK
}

double MeasuredProduct::getQuantity() {
    return quantity;
}

void MeasuredProduct::calcPrice(double quantity, double price) {
    /*double temp = (getPrice() * quantity);
    setTotalPrice(temp);*/
    setPrice(quantity * price); // Multiply the quanitity of item by the price of the item
}

void MeasuredProduct::setQuantity(double val) {
    quantity = val;
}
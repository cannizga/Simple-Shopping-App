#include "UI.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
UI display;
FreshProduce poundsPerItem;
MeasuredProduct quantityPerItem;
vector <Item*> cart;
AdminLogin login;
ItemList getList;
char state1 = 'y', state2 = 'y', state3 = 'y', state4 = 'y', programState = 'y';
int input, input2, input3, check = 0, numItems = 0, id = 0, yesNo = 0, tipAmount = 0;
double total = 0;
// int size = (sizeof(cart) / sizeof(cart[0])); (You Can Just Call cart.size())
bool back = false, deliver = false, tip = false;
int main() {
    do {
        /*if (state1 == 'y') {
            display.Options();
        }*/
        while (state1 == 'y') { // STATE 1 OPTIONS MENU
            try {
                display.Options();
                cin >> input;

                if (cin.fail()) {
                    printf("\033c");
                    display.Error();
                    throw exception("ERROR");
                }
                else {
                    //Clear The Screen
                    printf("\033c");
                }

            }
            catch (exception e) {
                char correct = 'n';
                while (correct == 'n') {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    display.Options();
                    cin >> input;

                    if (cin.fail()) {
                        printf("\033c");
                        display.Error();
                    }
                    else {
                        //Clear The Screen
                        correct = 'y';
                        printf("\033c");
                    }
                }

            }
            switch (input) {
            case 1: // No Delivery Fee
                deliver = false;
                getList.readFile();
                state1 = 'n';
                break;
            case 2: // Delivery Fee
                deliver = true;
                getList.readFile();
                state1 = 'n';
                break;
            case 3: // ADMIN LOGIN
                login.adminLogin();
                if (getList.getBack()) {
                    state1 = 'y';
                }
                break;
            case 6: // EXIT APPLICATION!!!!   
                display.GoodBye();
                exit(3);
                break;
            default:
                display.Error();
                break;
            }

        } 
  
        while (state2 == 'y') { // STATE 2 MAIN MENU
            if (state3 == 'y' || back) {
                try {
                    display.MainMenu();
                    cin >> input2;
                    if (cin.fail()) {
                        printf("\033c");
                        display.Error();
                        throw exception("ERROR");
                    }
                    else {
                        //Clear The Screen
                        printf("\033c");
                    }
                }
                catch (exception e) {
                    char correct = 'n';
                    while (correct == 'n') {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        display.MainMenu();
                        cin >> input2;

                        if (cin.fail()) {
                            printf("\033c");
                            display.Error();
                        }
                        else {
                            //Clear The Screen
                            printf("\033c");
                            correct = 'y';
                        }
                    }
                }
            }
            switch (input2) {
            case 1:
                display.DisplayPoundItems(getList.List[0]->getName(), getList.List[1]->getName(), getList.List[2]->getName(), getList.List[0]->getPrice(), getList.List[1]->getPrice(), getList.List[2]->getPrice());
                state2 = 'n';
                state3 = 'y';
                state4 = 'n';
                id = 1;
                break;
            case 2:
                display.DisplayPoundItems(getList.List[3]->getName(), getList.List[4]->getName(), getList.List[5]->getName(), getList.List[3]->getPrice(), getList.List[4]->getPrice(), getList.List[5]->getPrice());
                state2 = 'n';
                state3 = 'y';
                state4 = 'n';
                id = 2;
                break;
            case 3:
                display.FrozenItems(getList.List[6]->getName(), getList.List[7]->getName(), getList.List[8]->getName(), getList.List[6]->getPrice(), getList.List[7]->getPrice(), getList.List[8]->getPrice());
                state2 = 'n';
                state3 = 'y';
                state4 = 'n';
                id = 3;
                break;
            case 5: // CHECKOUT
                try {
                    cout << "Would you like to tip?\n(0) Yes\n(1) No" << endl;
                    cin >> yesNo;
                    if (yesNo == 0) {
                        cout << "(If you actually want to tip nothing just type 0) How much would you like to tip? ";
                        cin >> tipAmount;
                        if (tip <= 0) {
                            tip = false;
                        }
                        else {
                            tip = true;
                        }
                    } else if (cin.fail()) {
                        printf("\033c");
                        display.Error();
                        throw exception("ERROR");
                    }
                    else {
                        tip = false;
                        tipAmount = 0;
                    }
                }
                catch (exception e) {
                    char correct = 'n';
                    while (correct == 'n') {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Would you like to tip?\n(0) Yes\n(1) No" << endl;
                        cin >> yesNo;
                        if (yesNo == 0) {
                            cout << "(If you actually want to tip nothing just type 0) How much would you like to tip? ";
                            cin >> tipAmount;
                            if(tip <= 0) {
                                tip = false;
                            }
                            else {
                                tip = true;
                            }
                            correct = 'y';
                        }
                        else if (cin.fail()) {
                            printf("\033c");
                            display.Error();
                            correct = 'n';
                        }
                        else {
                            tip = false;
                            tipAmount = 0;
                            correct = 'y';
                        }
                    }
                }

                printf("\033c");
                for (int g = 0; g < cart.size(); g++) {
                    display.Checkout(cart[g]->getName(), cart[g]->getPrice(), cart[g]->getNumItems(), cart[g]->getBasePrice());
                    total += cart[g]->getPrice();
                }
                //cout << "Total: " << total; (Debugging)
                poundsPerItem.setTotalPrice(total, deliver, tipAmount);
                display.TotalPrice(poundsPerItem.getTotalPrice(), deliver, poundsPerItem.getTip(), poundsPerItem.getDelivery(), tipAmount);
                state2 = 'n';
                state3 = 'n';
                state1 = 'n';
                programState = 'n';
                display.ThankYou();
                break;
            case 6: // EXIT APPLICATION!!!!
                display.GoodBye();
                exit(3);
                break;
            default:
                display.Error();
                break;
            }
        } 

        while (state3 == 'y') {
            //cin >> input3;
            switch (id) {
                cin.sync();
                case 1: //ID 1 FRESH ITEMS
                    cin >> input3;
                    switch (input3) {
                        case 1:
                            display.Weight(getList.List[0]->getName());
                            cin >> numItems;
                            printf("\033c");
                            getList.List[0]->setBasePrice(getList.List[0]->getPrice());
                            poundsPerItem.calcPrice(numItems, getList.List[0]->getPrice());
                            cart.push_back(new FreshProduce(poundsPerItem.getPrice(), getList.List[0]->getName(), numItems, getList.List[0]->getBasePrice()));
                            //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                            state3 = 'n';
                            state2 = 'y';
                            state1 = 'n';
                            input2 = 1;
                            back = false;
                            break;
                        case 2:
                            display.Weight(getList.List[1]->getName());
                            cin >> numItems;
                            printf("\033c");
                            getList.List[1]->setBasePrice(getList.List[1]->getPrice());
                            poundsPerItem.calcPrice(numItems, getList.List[1]->getPrice());
                            cart.push_back(new FreshProduce(poundsPerItem.getPrice(), getList.List[1]->getName(), numItems, getList.List[1]->getBasePrice()));
                            //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                            state3 = 'n';
                            state2 = 'y';
                            state1 = 'n';
                            input2 = 1;
                            back = false;
                            break;
                        case 3:
                            display.Weight(getList.List[2]->getName());
                            cin >> numItems;
                            printf("\033c");
                            getList.List[2]->setBasePrice(getList.List[2]->getPrice());
                            poundsPerItem.calcPrice(numItems, getList.List[2]->getPrice());
                            cart.push_back(new FreshProduce(poundsPerItem.getPrice(), getList.List[2]->getName(), numItems, getList.List[2]->getBasePrice()));
                            //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                            state3 = 'n';
                            state2 = 'y';
                            state1 = 'n';
                            input2 = 1;
                            back = false;
                            break;
                        case 4: //BACK
                            printf("\033c");
                            state1 = 'n';
                            state2 = 'y';
                            state3 = 'n';
                            back = true;
                            cin.sync();
                            break;
                        case 6: // EXIT APPLICATION!!!!
                            printf("\033c");
                            display.GoodBye();
                            exit(3);
                            break;
                        default:
                            display.Error();
                    }
                    break;
                case 2: //ID 2 MEAT AND SEAFOOD ITEMS
                    cin >> input3;
                    switch (input3) {
                        case 1:
                            display.Weight(getList.List[3]->getName());
                            cin >> numItems;
                            printf("\033c");
                            getList.List[3]->setBasePrice(getList.List[3]->getPrice());
                            poundsPerItem.calcPrice(numItems, getList.List[3]->getPrice());
                            cart.push_back(new FreshProduce(poundsPerItem.getPrice(), getList.List[3]->getName(), numItems, getList.List[3]->getBasePrice()));
                            //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                            state3 = 'n';
                            state2 = 'y';
                            state1 = 'n';
                            input2 = 2;
                            back = false;
                            break;
                        case 2:
                            display.Weight(getList.List[4]->getName());
                            cin >> numItems;
                            printf("\033c");
                            getList.List[4]->setBasePrice(getList.List[4]->getPrice());
                            poundsPerItem.calcPrice(numItems, getList.List[4]->getPrice());
                            cart.push_back(new FreshProduce(poundsPerItem.getPrice(), getList.List[4]->getName(), numItems, getList.List[4]->getBasePrice()));
                            //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                            state3 = 'n';
                            state2 = 'y';
                            state1 = 'n';
                            input2 = 2;
                            back = false;
                            break;
                        case 3:
                            display.Weight(getList.List[5]->getName());
                            cin >> numItems;
                            printf("\033c");
                            getList.List[5]->setBasePrice(getList.List[5]->getPrice());
                            poundsPerItem.calcPrice(numItems, getList.List[5]->getPrice());
                            cart.push_back(new FreshProduce(poundsPerItem.getPrice(), getList.List[5]->getName(), numItems, getList.List[5]->getBasePrice()));
                            //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                            state3 = 'n';
                            state2 = 'y';
                            state1 = 'n';
                            input2 = 2;
                            back = false;
                            break;
                        case 4: //BACK
                            printf("\033c");
                            state1 = 'n';
                            state2 = 'y';
                            state3 = 'n';
                            back = true;
                            cin.sync();
                            break;
                        case 6: // EXIT APPLICATION!!!!
                            printf("\033c");
                            display.GoodBye();
                            exit(3);
                            break;
                        default:
                            display.Error();
                            break;
                    }
                    break;
                case 3: //ID 3 FROZEN ITEMS
                    cin >> input3;    
                    switch (input3) {
                    case 1:
                        display.Quantity(getList.List[6]->getName());
                        cin >> numItems;
                        printf("\033c");
                        getList.List[6]->setBasePrice(getList.List[6]->getPrice());
                        poundsPerItem.calcPrice(numItems, getList.List[6]->getPrice());
                        cart.push_back(new MeasuredProduct(poundsPerItem.getPrice(), getList.List[6]->getName(), numItems, getList.List[6]->getBasePrice()));
                        //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                        state3 = 'n';
                        state2 = 'y';
                        state1 = 'n';
                        input2 = 3;
                        back = false;
                        break;
                    case 2:
                        display.Quantity(getList.List[7]->getName());
                        cin >> numItems;
                        printf("\033c");
                        getList.List[7]->setBasePrice(getList.List[7]->getPrice());
                        poundsPerItem.calcPrice(numItems, getList.List[7]->getPrice());
                        cart.push_back(new MeasuredProduct(poundsPerItem.getPrice(), getList.List[7]->getName(), numItems, getList.List[7]->getBasePrice()));
                        //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                        state3 = 'n';
                        state2 = 'y';
                        state1 = 'n';
                        input2 = 3;
                        back = false;
                        break; 
                    case 3:
                        display.Quantity(getList.List[8]->getName());
                        cin >> numItems;
                        printf("\033c");
                        getList.List[8]->setBasePrice(getList.List[8]->getPrice());
                        poundsPerItem.calcPrice(numItems, getList.List[8]->getPrice());
                        cart.push_back(new MeasuredProduct(poundsPerItem.getPrice(), getList.List[8]->getName(), numItems, getList.List[8]->getBasePrice()));
                        //display.Checkout(cart[0]->getName(), cart[0]->getPrice()); (Debugging)
                        state3 = 'n';
                        state2 = 'y';
                        state1 = 'n';
                        input2 = 3;
                        back = false;
                        break;
                    case 4: //BACK
                        printf("\033c");
                        state1 = 'n';
                        state2 = 'y';
                        state3 = 'n';
                        back = true;
                        cin.sync();
                        break;
                    case 6: // EXIT APPLICATION!!!!
                        printf("\033c");
                        display.GoodBye();
                        exit(3);
                        break;
                    default:
                        display.Error();
                        break;
                    }
                    break;
                default:
                    display.Error();
            }
        }

    } while (programState == 'y');
}

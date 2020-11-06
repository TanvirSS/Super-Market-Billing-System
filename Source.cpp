#include <iostream>
using namespace std;

int main() {
	int i, input, j, stop = 0;
	const int size = 10; //
	char billReport[size][20] = { "Carrots", "Potatoes", "Onions" };
	char description[size][50] = { "Type: Vegetable\nCost: $0.50\n", "Type:Vegetable\nCost: $0.80\n", "Type:Vegetable\nCost: $0.75\n" };	
//When we loop the program this vvvvv will be an issue, so we probably have to have an internal loop or so NOT SURE
	char prefixType[50] = "Type: ", prefixCost[50] = "\nCost: ", add[50], subtract[50], detailType[50], detailCost[50]; //These can't be too small or the program won't let it add complex characters like $ to it OR large #s
	char button ;
//For some of the variables here^^^^^, i can put them into the loop function but i need to have them all initialised before using them ahhhhhhh ok
	start:
	cout << "\n====================\nSuper Market Billing\n====================\n\n1.Bill Report\n2.Add/Remove/Edit Item\n3.Show Item Details\n4.Exit\nPlease Select a Number from the options above: ";
	//The following should redirect page to whatever input is needed
	cin >> input;
	switch (input) {
		//This one is done
	case 1:
		//This is the functon for the billReport option 1.
		cout << "\n===========\nBill Report\n===========\n";
		for (i = 0; i < size; i++) {
			if (strlen(billReport[i]) != 0) {
				cout << endl << billReport[i];
			}
			else {
			}
		}
		cout << endl;
		cout << "\nPress the '\\' key to go back: ";
		cin >> button;
		if (button == '\\') {
			goto start;
		}
		//This leads to another menu system so more complex
	case 2:
		bE:
		cout << "\nBill Editor\n===========\n\n1.Add Item Details\n2.Edit Item Details (This Feature is Currently unavailable)\n3.Delete Item Details\n4.Return to Main Menu \nPlease Select a Number from the options above: ";
		//Create some arrays to do some string operations
		cin >> input;
		switch (input) {

			//WE NEED TO THINK OF A WAY TO ADD ITEM DETAILS TO THE 'add' ARRAY
		case 1:
			//This will just print out the list
			cout << endl;
			for (i = 0; i < size; i++) {
				if (strlen(billReport[i]) != 0) {
					cout << billReport[i] << endl;
				}
				else {
				}
			}

			cout << "\nName: ";
			cin >> add;
			cout << "\nType: ";
			cin >> detailType;
			cout << "\nCost: ";
			cin >> detailCost;

			//Finds the next empty slot available to put add[]
			for (j = 0; j < size; j++) {
				if (strlen(billReport[j]) == 0) {
					break;
				}
				else {
				}
			}
			//We  should assume that j is the same for the description array too

			//Do some string operations
			strcat_s(billReport[j], add);
			strcat_s(prefixType, detailType);

			strcat_s(prefixCost, detailCost);
			//Gonna see how far we can take this
			strcat_s(prefixType, prefixCost); //we might not need the detail array
			strcat_s(description[j], prefixType);

			cout << endl;
			for (i = 0; i < size; i++) {
				if (strlen(billReport[i]) != 0) {
					cout << billReport[i] << endl;
					cout << description[i] << endl;
				}
				else {
				}
			}
			break;
		case 2:
//This Function was supposed to EDIT item details but because I made a big description array instead of seperating it into small arrays like type and cost
			//This will just print out the list
			break;
			//WILL COME BACK TO THIS ONE
		case 3:
			//This will just print out the list
			cout << endl;
			for (i = 0; i < size; i++) {
				if (strlen(billReport[i]) != 0) {
					cout << billReport[i] << endl;
				}
			}

			cout << "Which item would you like to delete: ";
			cin >> subtract;

			for (i = 0; i < size; i++) {
				if (!strcmp(billReport[i], subtract) ) {
					cout << "Deleting: " << billReport[i] << endl;
					strcpy_s(billReport[i], "");
					strcpy_s(description[i], "");
					break; 
				}
			}
			break;
		case 4:
			goto start;
			break;
			//CASE 4 IMPLEMENT AFTER MAKING THSI PROGRAM LOOP
		default:
			break;
		}

		cout << endl;
		cout << "\nPress the '\\' key to go back OR '/' to continue editing: ";
		cin >> button;
		if (button == '\\') {
			goto start;
		}
		else if (button == '/') {
			goto bE;
		}
		break;
	case 3:
		cout << endl;
		for (i = 0; i < size; i++) {
			if (strlen(billReport[i]) != 0) {
				cout << billReport[i] << endl;
				cout << description[i] << endl;
			}
			else {
			}
		}
		cout << "\nPress the '\\' key to go back: ";
		cin >> button;
		if (button == '\\') {
			goto start;
		}
		break;
	case 4:
		cout << "Press Enter again to Exit" ; //LET FIX THIS
		//exit;
		break;
	default:
		cout << "Please choose a number between 1 and 4";
		break;
	}

}

//We can probably simplify the code by merging the subtract and add variables into 1

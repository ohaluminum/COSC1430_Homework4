#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "merchant.h"

using namespace std;

int main()
{
	//1) Create two arrays: one of antique objects and one of integers to represent the quantity of antique
	Antique *object_ptr;
	int *quantity_ptr;
	
	//2) Read from standard input the name of the file that stores the initial status of the Merchant's stock
	string filename;
	cin >> filename;

	int numOfAntique = 0;
	string line;

	ifstream inFS1(filename);
	if (inFS1.is_open())
	{
		while (getline(inFS1, line))
		{
			numOfAntique++;
		}
	}

	inFS1.close();

	object_ptr = new Antique[numOfAntique];
	quantity_ptr = new int[numOfAntique];

	//3) Read the content of the file into the array of Antique objects and quantities. The file format is as follows:
	//<Antique 1 name>, <Antique 1 price>, <Antique 1 quantity>
	//<Antique 2 name>, <Antique 2 price>, <Antique 2 quantitiy>
	//...
	//<Antique 10 name>, <Antique 10 price>, <Antique 10 quantitiy>

	char delimiter;
	string tempName;
	float tempPrice_float;
	int tempQuantity_int;
	string newline;

	ifstream inFS2(filename);

	if (inFS2.is_open())
	{
		for (int i = 0; i < numOfAntique; i++)
		{
			getline(inFS2, tempName, ',');
			inFS2 >> tempPrice_float >> delimiter >> tempQuantity_int;

			object_ptr[i].setName(tempName);
			object_ptr[i].setPrice(tempPrice_float);
			quantity_ptr[i] = tempQuantity_int;

			getline(inFS2, newline);
			/*
			 *Use getline() instead of ignore()
			 *The instructor's response:
			 *The default getline() function will read a line until a line breaker is reached, as you already know.
			 *ignore() is to ignore or clear characters from the input buffer.  
			 *I suspect for the second txt file, there maybe an extra line breaker in front of each line starting from the second line of antiques. 
			 *Recall that you use getline(inFS2, tempName, ','); to read the antique name, which will not stop reading until it sees a ',' not a line breaker.
			 */
		}
		
		/*
		 *inFS leaves the newline character in the stream.
		 *Adding inFS.ignore() to the next line clears/ignores the newline from the stream.
		 */
	}
	else
	{
		std::cout << "Error! File not found." << endl << endl;
	}

	inFS2.close();

	//4) Use the two arrays as arguments to create a Merchant object.
	Merchant trade(object_ptr, quantity_ptr, numOfAntique);

	//5) - budget (float): variable used to store the amount of money the customer can spend. Take in user input for customer's budget like the following :
	float budget;
	cout << "Enter in budget: $";
	cin >> budget;

	ofstream outFS("log2.txt", ios::trunc);
	outFS.close();

	//6) Present the user with the following menu:
	while (1)
	{
		cout << "Make a selection: " << endl;
		cout << "1 - Haggle" << endl;
		cout << "2 - View menu" << endl;
		cout << "3 - Select an antique" << endl;
		cout << "4 - Leave" << endl << endl;

		int userChoise;
		cin >> userChoise;

		/*
		 *If the user enters either 1-4, it will call the corresponding member functions of Merchant class (see below).
		 *If the user enters anything but 1-4, then it should output to the screen and return to the menu:
		 *Invalid option.
		 */

		switch (userChoise)
		{
		case 1:
			trade.haggle();
			break;

		case 2:
			trade.printMenu();
			break;

		case 3:
			trade.selectAntique(budget);
			break;

		case 4:
			trade.leave(budget);
			break;

		default:
			cout << "Invalid selection." << endl << endl;
			break;
		}
	}
	return 0;
}

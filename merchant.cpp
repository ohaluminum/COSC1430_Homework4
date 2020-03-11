#include <iostream>
#include <iomanip>
#include <fstream>

#include "merchant.h"

using namespace std;

/*
 *Merchant (constructor): the constructor takes as arguments an array of Antiques and an array of quantities
 *to use them to initialize antiques and quantities. revenue should be set to 0.
 */

Merchant::Merchant(Antique antiArr[], int quanArr[], int size)
{
    this->size = size;
    object = new Antique[size];
    quantities = new int[size];

    for (int i = 0; i < size; i++)
    {
        object[i] = antiArr[i];
        quantities[i] = quanArr[i];
    }

    delete [] antiArr;
    delete [] quanArr;

    revenue = 0.0;
    haggleTimes = 0;
}

/*
 *haggle: function that decreases each and every Antique object's price by 10%. It will print the following:
 *You have successfully haggled and everything is 10% off.
 *Customer cannot haggle more than once. If he tries to haggle more than once, it will print the following:
 *Sorry, you have already haggled.
 */

void Merchant::haggle()
{
    if (haggleTimes == 0)
    {
        for (int i = 0; i < size; i++)
        {
            object[i].setPrice(0.9f * object[i].getPrice());
        }

        cout << "You have successfully haggled and everything is 10% off." << endl << endl;
        haggleTimes++;
    }
    else
    {
        cout << "Sorry, you have already haggled." << endl << endl;
    }
}

/*
 *printMenu: function that prints the items available for sale in the following format:
 *1) <Antique name1>: $<price.2digits>
 *2) <Antique name2>: $<price.2digits>
 *...
 *10) <Antique name10>: $<price.2digits>
 */

void Merchant::printMenu()
{
    for (int i = 0; i < size; i++)
    {
        if (quantities[i] > 0)
        {
            cout << i + 1 << ") " << object[i].toString() << endl;
        }
    }

    cout << endl;
}

/*
 *selectAntique: this function handles item selection and sale. It begins by printing the message (and ending with a newline):
 *Enter antique number:
 *The antique number is read from standard input and stored. If the antique is not available (quantity = 0), print the following:

 *Sorry! Antique is out of stock.
 *If the user has an insufficient budget, print the following:

 *Insufficient funds.
 *Otherwise, if the sale was successful, decrease the user's budget to reflect the sale, add to revenue, and reduce the quantity of the item by one. Print the following to standard output:

 *Enjoy your <Antique.name>!
 *And append to a text file called "log2.txt" that acts as an itemized receipt like following:

 *Sold <Antique.name> for $<price.2digits>
 */

void Merchant::selectAntique(float& userBudget)
{
    cout << "Enter item number:" << endl;
    int antiqueNumber;
    cin >> antiqueNumber;

    if (quantities[antiqueNumber - 1] == 0)
    {
        cout << "Sorry! Antique is out of stock." << endl;
    }

    else if (object[antiqueNumber - 1].getPrice() > userBudget)
    {
        cout << "Insufficient funds." << endl << endl;
    }

    else
    {
        userBudget -= object[antiqueNumber - 1].getPrice();
        revenue += object[antiqueNumber - 1].getPrice();
        quantities[antiqueNumber - 1]--;

        cout << "Enjoy your " << object[antiqueNumber - 1].getName() << endl;

        //Open file with append mode
        ofstream outFS1("log2.txt", ios::app);

        if (outFS1.is_open())
        {
            outFS1 << "Sold " << object[antiqueNumber - 1].getName() << " for $" << fixed << setprecision(2) << object[antiqueNumber - 1].getPrice() << endl;
        }
        outFS1.close();
    }
}

/*
 *leave: this function terminates the program, and appends the budget and revenue to a text file called "log2.txt" at the end:
 *Total revenue: $<revenue.2digits>
 *Remaining budget: $<budget.2digits>
 */

void Merchant::leave(float userBudget)
{
    //Open file with append mode
    ofstream outFS2("log2.txt", ios::app);
    if (outFS2.is_open())
    {
        outFS2 << "Total revenue: $" << fixed << setprecision(2) << revenue << endl;
        outFS2 << "Remaining budget: $" << fixed << setprecision(2) << userBudget;
    }
    outFS2.close();

    cout << endl;

    exit(0);
}

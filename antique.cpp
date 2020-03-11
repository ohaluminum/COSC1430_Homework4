#include <string>
#include <sstream>
#include <iomanip>
#include "antique.h"

using namespace std;

Antique::Antique()
{
	name = "";
	price = 0.0;
}

void Antique::setName(string name)
{
	this->name = name;
}

void Antique::setPrice(float price)
{
	this->price = price;
}

string Antique::getName()
{
	return name;
}

float Antique::getPrice()
{
	return price;
}

string Antique::toString()
{
	string str;
	ostringstream outSS;

	outSS << name << ": $" << fixed << setprecision(2) << price;

	str = outSS.str();

	return str;
}

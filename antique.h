#pragma once

#ifndef ANTIQUE_H
#define ANTIQUE_H

#include <string>

using namespace std;

class Antique
{
public:
	Antique();
	void setName(string name);
	void setPrice(float price);
	string getName();
	float getPrice();
	string toString();

private:
	string name;
	float price;
};

#endif

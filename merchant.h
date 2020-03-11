#pragma once

#ifndef MERCHANT_H
#define MERCHANT_H

#include "antique.h"

using namespace std;

class Merchant
{
public:
	Merchant(Antique antiArr[], int quanArr[], int size);
	void haggle();
	void printMenu();
	void selectAntique(float& userBudget);
	void leave(float userBudget);
	

private:
	Antique *object;
	int *quantities;
	float revenue;
	int haggleTimes;
	int size;
};

#endif




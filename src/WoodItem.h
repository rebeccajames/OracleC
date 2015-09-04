/*
 * WoodItem.h
 *
 *  Created on: Aug 24, 2015
 *      Author: Esteban
 *  Edited on: Sept 2, 2015
 *      Editor: Rebecca James
 */


#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef WOODITEM_H_
#define WOODITEM_H_

using namespace std;

class WoodItem {


private:
	string type;
	double baseDeliveryTime;
	double price;

public:
	// Member functions declaration
	WoodItem();
	WoodItem(string woodType, double deliveryTime, double itemPrice);
	void SetWoodItem(string woodType);
	string GetType();
	double GetBaseDeliveryTime();
	double GetPrice();
	
};

#endif /* WOODITEM_H_ */

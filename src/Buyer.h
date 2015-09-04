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

#ifndef BUYER_H_
#define BUYER_H_

using namespace std;
;
class Buyer {

private:
	string name;
	string address;
	string date;

public:
	// Member functions declaration
	Buyer();
	Buyer(string buyerName, string buyerAddress, string buyerDate); 
	string GetName();
	string GetAddress();
	string GetDate();
	
};

#endif /* BUYER_H_ */

/*
 * Buyer.cpp
 *
 *  Created on: Sept 2, 2015
 *      Author: Rebecca James
 *
 */

#include "Buyer.h"
/*
 * Empty constructor
 */
Buyer::Buyer() 
{
	name = "";
	address = "";
	date = "";
}

/*
 * Constructor with parameters
 */
Buyer::Buyer(string buyerName, string buyerAddress, string buyerDate) 
{
	name = buyerName;
	address = buyerAddress;
	date = buyerDate;
}

string Buyer::GetName()
{
	return name;
}

string Buyer::GetAddress()
{
	return address;
}

string Buyer::GetDate()
{
	return date;
}
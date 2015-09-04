/*
 * WoodItem.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: USER
 *  Edited on: Sept 2, 2015
 * 		Editor: Rebecca James
 */

#include "WoodItem.h"
/*
 * Empty constructor
 */
WoodItem::WoodItem() 
{
	type = "";
	baseDeliveryTime = 0.0;
	price = 0.0;
}

/*
 * Constructor with parameters
 */
WoodItem::WoodItem(string woodType, double deliveryTime, double itemPrice) 
{
	type = woodType;
	baseDeliveryTime = deliveryTime;
	price = itemPrice;
}

void WoodItem::SetWoodItem(string woodType)
{
	type = woodType;
	if (type == "Cherry") 
	{
		baseDeliveryTime = 2.5;
		price = 5.95;
	}
	if (type == "Curly Maple")
	{
		baseDeliveryTime = 1.5;
		price = 6.00;
	}
	if (type == "Genuine Mahogany")
	{
		baseDeliveryTime = 3;
		price = 9.60;
	}
	if (type == "Wenge")
	{
		baseDeliveryTime = 5;
		price = 22.35;
	}
	if (type == "White Oak")
	{
		baseDeliveryTime = 2.3;
		price = 6.70;
	}
	if (type == "Sawdust")
	{
		baseDeliveryTime = 1;
		price = 1.5;
	}
}

string WoodItem::GetType()
{
	return type;
}

double WoodItem::GetBaseDeliveryTime()
{
	return baseDeliveryTime;
}

double WoodItem::GetPrice()
{
	return price;
}
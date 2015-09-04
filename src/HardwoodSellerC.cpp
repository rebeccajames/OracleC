//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
// Edited on   : Sept 2, 2015
// Editor      : Rebecca James
//============================================================================

#include <iostream>		//include I/O library std output
#include <fstream>		//include filestream library
#include <string>		//include string library
#include <sstream>	    //include stream class library to operate on strings
#include <vector>		//include vector data structure
#include "WoodItem.h"	//include WoodItem header file
#include "Buyer.h"		//include Buyer header file


using namespace std;

void readInputFile(string inputFilePath);
double deliveryTime();
double calCost();

int main(int argc, char* argv[]) {
	
	vector<string> lines1;
	vector<string> lines2;
	vector<Buyer> customer;
	string line;
	string inputFilePath = argv[1];
	int numlines = 0;
	stringstream ss;
	int ctr1 = 0;
	int ctr2 = 0;
	
//readInputFile(argv[1], lines1);
	ifstream infile;
	infile.open(inputFilePath.c_str());
	if (!infile) {
		cout << "Error opening file\n";
	}
		
    while (getline(infile, line))
    {	
		++numlines;
		if (numlines % 2 != 0 )
        lines1.push_back(line);
		if (numlines % 2 ==0 )
		lines2.push_back(line);
	}

//THIS SHOULD PROBABLY BE MOVED TO THE INIT LOOP THROUGH VECTOR AND PARSE INTO OBJECTS
//POSSIBLY MAKE THE READINPUTFILE METHOD CALL INIT METHOD
//Outputs the vector containg the customer information in a string
	for (vector<string>::iterator itr1 = lines1.begin(); itr1 != lines1.end(); itr1++)
	{
            cout << "Customer " << ++ctr1 << ":  " << *itr1 << endl;
	}	

//Outputs the vector containing the order information in a string
	for (vector<string>::iterator itr2 = lines2.begin(); itr2 != lines2.end(); itr2++)
	{
			cout << "Order " << ++ctr2 << ":  " << *itr2 << endl;
	}
//THIS WOULD BE THE END OF THE SECTION THAT GOES INTO THE INIT METHOD
/*
* Once each line is stored in the vector of strings.  The strings need to be parsed
* and each "token" or string between the delimiter (;) needs to be stored into the
* correct object.  The vector lines1 needs to have the string in each index parsed 
* into a vector of objects where - for example - lines1[0] has the string 
* Buyer1 Full1 Name1;1213 Munson Blvd, Tallahassee, FL 32305;08/20/2015
* the vector<Buyer> b b[0] would have 	b.name = Buyer1 Full1 Name1;
										b.address = 1213 Munson Blvd, Tallahassee, FL 32305;
										b.date = 08/20/2015;
* Once this is parsed - the vector lines2 needs to be parsed into a vector of WoodItem 
* objects and a variable quantity.  The date from the Buyer objects in the vector of buyers
* would have to be extracted to be used with the WoodItem vector to calculate the est
* delivery time.
* 
*/	
	infile.clear();	
	infile.close();
	
	return 0;
}

/*
 *
 * Method to initialize Vector of Buyers
 * 
*/
// THIS IS MESSSSSSSSSSSSSSSSSSSSSSED UUUUUPPPPPPPP
/*
vector<Buyer> initBuyer(vector<string> str)
{
	int numObjs = 0;
	vector<Buyer> b;
	stringstream parse(str);
	
	for (vector<string>::iterator itr3 = str.begin(); itr3 != str.end(); itr3++)
	{
		Buyer temp = new Buyer();
				
		while(str != ";")
		{
			while(!parse.fail())
				parse >> b[numObjs].temp.name >> b[numObjs].temp.address >> b[numObjs].temp.date;
				numObjs++;
		}		
	}
	return b;
}
*/

/*
 * Method to compute the deliveryTime
 */
double deliveryTime(WoodItem w, int amount) 
{
	double deliveryETA = 0.0;
	
	if (amount >= 1 && amount <= 100)
	{
		deliveryETA = w.GetBaseDeliveryTime();
	}
	if (amount >= 101 && amount <= 200)
	{
		deliveryETA = w.GetBaseDeliveryTime()*2;
	}
	if (amount >= 201 && amount <= 300)
	{
		deliveryETA = w.GetBaseDeliveryTime()*3;
	}
	if (amount >= 301 && amount <= 400)
	{
		deliveryETA = w.GetBaseDeliveryTime()*4;
	}
	if (amount >= 401 && amount <= 500)
	{
		deliveryETA = w.GetBaseDeliveryTime()*5;
	}
	if (amount >= 501 && amount <=1000)
	{
		deliveryETA = w.GetBaseDeliveryTime()*5.5;
	}
	return deliveryETA;
}

/*
 * Method to compute the total cost of purchase
 */
double calCost(WoodItem w, int amount) 
{
	double cost = 0.0; 
	cost = w.GetPrice() * amount;
	return cost;
}



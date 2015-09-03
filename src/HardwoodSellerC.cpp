//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
// Edited on   : Sept 2, 2015
// Editor      : Rebecca James
//============================================================================

//#include <boost/algorithm/string.hpp>  //include library for split() 
#include <iostream>		//include I/O library std output
#include <fstream>		//include filestream library
#include <string>		//include string library
#include <sstream>	    //include stream class library to operate on strings
#include <vector>		//include vector data structure
#include "WoodItem.h"	//include WoodItem header file
#include "Buyer.h"		//include Buyer header file


using namespace std;
//using namespace boost;

void readInputFile(string inputFilePath);
double deliveryTime();
double calCost();



int main(int argc, char* argv[]) {
	
	//vector<string> s;
	//vector<Buyer> b;
	//vector<WoodItem> w;
	
	readInputFile(argv[1]);
	/*cout
			<< "This is an empty main method"
			<< endl;
	*/
	return 0;
}

/*
 * Method to read the input file
 */
void readInputFile(string inputFilePath) {
	vector<string> lines1;
	vector<string> lines2;
    string line;
	int numlines = 0;
	//int dbleSize = 0;
	
	ifstream infile;
	infile.open(inputFilePath.c_str());
	
	if (!infile) {
		cout << "Error opening file\n";
		exit(1);
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
	for (vector<string>::iterator itr1 = lines1.begin(); itr1 != lines1.end(); itr1++)
	{
            cout << *itr1 << endl;
	}	

	for (vector<string>::iterator itr2 = lines2.begin(); itr2 != lines2.end(); itr2++)
	{
			cout << *itr2 << endl;
	}
//THIS WOULD BE THE END OF THE SECTION THAT GOES INTO THE INIT METHOD
	
	infile.clear();	
	infile.close();
	

}



/*
 *
 * Method to initialize Vector of Buyers
 * 
*/
// THIS IS FUUUUUUUCKKKKKKEEEDDDDD UPPPPPPPP
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
	
	if (amount >= 1 && <= 100)
	{
		deliveryETA = w.GetBaseDeliveryTime();
	}
	if (amount >= 101 && <= 200)
	{
		deliveryETA = w.GetBaseDeliveryTime()*2;
	}
	if (amount >= 201 && <= 300)
	{
		deliveryETA = w.GetBaseDeliveryTime()*3;
	}
	if (amount >= 301 && <= 400)
	{
		deliveryETA = w.GetBaseDeliveryTime()*4;
	}
	if (amount >= 401 && <= 500)
	{
		deliveryETA = w.GetBaseDeliveryTime()*5;
	}
	if (amount >= 501 && <=1000)
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



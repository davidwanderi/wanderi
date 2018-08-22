/*
 *  Created on: Jun 9, 2018
 *      
 */

#include "Gas.h"

using namespace std;

//***************************************************************
//    	GAS FEE CALCULATION
//****************************************************************
// This funtion takes care of int input
int Gas::gasChargeCalc(int a, int b)
{
	int sum;
	sum = a + b;
	return sum;// return the int sum of the addition

}
//This method takes care of the double inputs
double Gas::gasChargeCalc1(double a, double b)//changed the methods name to make it diferent from the one above
{
	double sum;
	sum = a + b;
	return sum;//return the double

}


void Gas::gasFeeCalculation()
{
	//declaring variables with
	double gallons, charge, total;
	//const int fee = 15;
	const double fee = 15;// changed the data type for this variable to match the methods
	int costUpTo6K = 2.35,
		costUpTo20K = 3.75,
		costOver20K = 6.00;

	system("cls");

   cout << "\n\n\n\tEnter the total number of gallons used, divided by 1000: ";
	cin >> gallons;

	if (gallons > 20){
//		charge = (gallons - 20) * costOver20K;
//		charge = charge + (14 * costUpTo20K);
//		charge = charge + (6 * costUpTo6K);
		charge = (gallons - 20) * costOver20K + (14 * costUpTo20K) +(6 * costUpTo6K);// minimize system resources by having all one line

	}
	else if (gallons > 6 && gallons <= 20){

//		charge = (gallons - 6) * costUpTo20K;
//		charge = charge + (6 * costUpTo6K);
		charge = (gallons - 6) * costUpTo20K  + (6 * costUpTo6K);// improved the code

	}
	else{

		charge = gallons * costUpTo6K;
	}

	total = gasChargeCalc1(charge,fee);//This methods accepts doubles and return double.
	cout << "\n\n\n\tYou have used " << gallons << " thousand gallons of water." << endl;
	cout << "\n\n\n\tYour total gas bill is $" << setprecision(2) << fixed << total;
   getch();
}









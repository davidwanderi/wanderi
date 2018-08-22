/*
 * Service.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: Curtis
 */

#include "Service.h"

using namespace std;
//function that create and provide information about an existing service
void Service::createService()
{
	cout<<"\nPlease Enter The Service Number ";//Getting user information about service number
	cin>>customer_number;
	cout<<"\nPlease Enter The Name of The Service ";
	cin>>name;
	cout<<"\nPlease Enter The Price of The Service ";
	cin>>serviceVar;
	cout<<"\nPlease Enter The Discount (%) ";
	cin>>discount;
 }
//method that displays service number,name and discount amount
void Service::showService()
{
	 cout<<"\nThe Service Number : "<<customer_number;
	 cout<<"\nThe Name of The Service : ";
	 puts(name);
	 cout<<"\nThe Price of The Service : "<<serviceVar;
	 cout<<"\nDiscount : "<<discount;
 }
//creating an array to hold service record
void Service::storeService(void)
{
	service_number = new int;
	service_buff = (char *)malloc(10);//alloocate a memory of size 10
	number_array = new int[10];//create an array of size 10

}

void Service::returnServiceNumber(void)
{
	int number = 0;
	//cout << INT_MAX;// This has potential of creating buffer overflow
	cout << number;
}







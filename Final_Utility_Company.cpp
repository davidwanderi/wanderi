/*
 * CS-405 Final Project
 *
 * Final_Utility_Company_System.cpp
 *
 *  
 * 
 */

//***************************************************************
//                   Final Project - Utility Company
//***************************************************************

#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include<conio.h>
#include "Login.h"
#include "Record.h"
#include "Service.h"
using namespace std;

Record record;

//This is the main class that supports the entire program
int main()
{
   char ch;

    do
    {
	  system("cls");
	  cout<<"\n\n\n\tMAIN MENU";
	  cout<<"\n\n\t01. CUSTOMER";
	  cout<<"\n\n\t02. ADMINISTRATOR";
	  cout<<"\n\n\t03. EXIT";
	  cout<<"\n\n\tPlease Select Your Option (1-3) ";
	  ch=getche();
	  switch(ch)// switch method that offers user interaction
	  {
		 case '1': system("cls");
			   record.placeOrder();//call the record method to display the order.
			   getch();
			   break;
		  case '2': record.adminMenu();//call the record method to display admin menu
			    break;
		  case '3':exit(0);// exit the program
		  default :cout<<"\a";
	}
    }while(ch!='3');
   return 0;
}








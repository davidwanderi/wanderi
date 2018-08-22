/*
 * Record.cpp
 *
 * 
 *    
 */
#define _CRT_SECURE_NO_DEPRECATE

#include "Login.h"
#include "Service.h"
#include "Record.h"
#include "Gas.h"

using namespace std;

//***************************************************************
//    	function to write in file
//****************************************************************

fstream fp;
Service serv;
Record recordMenu;
Login user;
Gas gasInfo;

void Record::writeStaticServiceArray(void) {
	int number;
	int array[10];//An array with a size of 10
	int i = 9;
	number = array[i];//this statement was not initialized
	//number = number; had to remove this extra line that had potential of causing int overflow
}



void Record::writeDynamicServiceArray(void) {
	int number;
	int *array = new int[10];
	int i = 9;
	number = array[i];// not initialized statement
	//number == number;// This was a comparison that would caused the program to return incorect values
	delete[] array;
}
// This method is used for creating new services.
void Record::writeService()
   {
    fp.open("Service.dat",ios::out|ios::app);
    serv.createService();
    fp.write((char*)&serv,sizeof(Service));
    fp.close();
    cout<<"\n\nThe Service Has Been Created ";
    getch();
   }


//***************************************************************
//    	function to read all records from file
//****************************************************************
//method that reads all the services available.
void Record::displayAll()
{
   system("cls");
   cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
   fp.open("Service.dat",ios::in);
   while(fp.read((char*)&serv,sizeof(Service)))
	{
	 serv.showService();
	 cout<<"\n\n====================================\n";
	 getch();
	 }
    fp.close();
    getch();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************

void Record::displayNumber()
{
	int *number = NULL;// instatiating number

	*number = 5; //This can easily be used to perform illegal functions.
}

struct service_object
{
	int value;
};

void Record::displayServiceItem(struct service_object *obj)//read from file
{
	if (obj == NULL)// if it is null get out of the loop
	{
		goto done;
	}

	obj->value = 1; //else value gets 1

done:
	obj->value = 2;// value gets 2
}


void Record::displayService(int n)
{
    int flag=0;
    fp.open("Service.dat",ios::in);
    while(fp.read((char*)&serv,sizeof(Service)))// reading from the file 
	{
	 if(serv.retsno()==n)
		{

       system("cls");
		 serv.showService();
		 flag=1;
		}
	}
    fp.close();
   if(flag==0)
   cout<<"\n\nrecord not exist";
   getch();
}


//***************************************************************
//    	function to display all Services Service list
//****************************************************************

void Record::serviceMenu()
{

     system("cls");
     fp.open("Service.dat",ios::in);
     if(!fp)
     {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       cout<<"\n\n\n Program is closing ....";
       getch();
       exit(0);
     }

     cout<<"\n\n\t\tService MENU\n\n";
     cout<<"====================================================\n";
     cout<<"P.NO.\t\tNAME\t\tPRICE\n";
     cout<<"====================================================\n";

     while(fp.read((char*)&serv,sizeof(Service)))
     {
         cout<<serv.retsno()<<"\t\t"<<serv.retname()<<"\t\t"<<serv.retService()<<endl;
     }
     fp.close();
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void Record::modifyService()
{
    int no,found=0;

    system("cls");
    recordMenu.serviceMenu();
    cout<<"\n\nTo Modify ";
    cout<<"\n\nPlease Enter The Service Number of The Service:\n";
    cin>>no;
    fp.open("Service.dat",ios::in|ios::out);
    while(fp.read((char*)&serv,sizeof(Service)) && found==0)
	   {
	    if(serv.retsno()==no)
		   {
		    serv.showService();
		    cout<<"\nPlease Enter The New Details of Service"<<endl;
		    serv.createService();
		  //  int pos=-1*sizeof(serv);// creates data overflow.
		    long long int pos=-1*sizeof(serv);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&serv,sizeof(Service));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}


//***************************************************************
//    	function to delete record of file
//****************************************************************

void Record::deleteServiceBuffer(void)
{
	// Alocates a single element.
	char *symbol = new char;
	char *buff = symbol;

	// Deletes array.
	delete[] buff;
}

void Record::deleteServiceCharacter(void)
{
	char *n = new char;
	char *m = (char *)malloc(1);

	free(n);
	delete m;
}
//method for deleting services
void Record::deleteService()
   {
    int no;

    system("cls");
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The Service no. of The Service You Want To Delete";
    cin>>no;
    fp.open("Service.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&serv,sizeof(Service)))
	{
	 if(serv.retsno()!=no)
		{
		 fp2.write((char*)&serv,sizeof(Service));
		 }
	 }
    fp2.close();
    fp.close();
    remove("Service.dat");
    rename("Temp.dat","Service.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
    }


//***************************************************************
//    	function to place order and generating bill for Services
//****************************************************************

   void Record::placeOrder()
   {
    int  order_arr[50],quan[50],c = 0;
    float amt,damt,total=0;
    char ch='Y';

    recordMenu.serviceMenu();
    cout<<"\n============================";
    cout<<"\n    PLACE YOUR ORDER";
    cout<<"\n============================\n";
    do{
	 cout<<"\n\nEnter The Service Number Of The Service : ";
	 cin>>order_arr[c];
	 cout<<"\nQuantity in number : ";
	 cin>>quan[c];
	 c++;
	 cout<<"\nDo You Want To Order Another Service ? (y/n)";
	 cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You For Placing The Order";getch();system("cls");
    cout<<"\n\n********************************INVOICE************************\n";
    cout<<"\nPr Number\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
    for(int x=0;x<=c;x++)//iterating the array to return the amount
	 {
		 fp.open("Service.dat",ios::in);
		 fp.read((char*)&serv,sizeof(Service));
		  while(!fp.eof())
			{
			if(serv.retsno()==order_arr[x])
				{
				 amt=serv.retService()*quan[x];
				 damt=amt-(amt*serv.retdis()/100);
				 cout<<"\n"<<order_arr[x]<<"\t"<<serv.retname()<<"\t"<<quan[x]<<"\t\t"<<serv.retService()<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			fp.read((char*)&serv,sizeof(Service));
			}

		 fp.close();
	 }
    cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
    getch();
    }

// Method that create and read from a file
   void Record::openFileAuthentication()
   {

   	  string input[10];

        fp.open("input.txt",ios::in);
        if(!fp)
        {
          cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
          cout<<"\n\n\n Program is closing ....";
          getch();
         // exit(0);
        }
   		string line = "";
   		int i = 0;

         while(getline(fp, line))
   	   {
   	      input[i] = line;
            i++;
   	   }
         openFileAuthentication();

         user.enterPassword();

         user.copyPassword();

         user.testUsernamePassword();

         user.isPasswordOK();

         user.copyUsername(input[0], input[1]);

         fp.close();

   }


   //***************************************************************
   //    	ADMINSTRATOR MENU FUNCTION
   //****************************************************************
// This provides valuable information to the user about available choices.
   void Record::adminMenu()
   {
// print out statements
     system("cls");
     char ch2;
     cout<<"\n\n\n\tADMIN MENU";
     cout<<"\n\n\t1.CREATE SERVICE";
     cout<<"\n\n\t2.DISPLAY ALL SERVICES";
     cout<<"\n\n\t3.QUERY ";
     cout<<"\n\n\t4.GAS SERVICE FEE ";
     cout<<"\n\n\t5.MODIFY SERVICE";
     cout<<"\n\n\t6.DELETE SERVICE";
     cout<<"\n\n\t7.VIEW SERVICE MENU";
     cout<<"\n\n\t8.BACK TO MAIN MENU";
     cout<<"\n\n\tPlease Enter Your Choice (1-8) ";
     ch2=getche();
     switch(ch2)
     {//switching between different statements as selected by user.
       case '1': system("cls");
   	      recordMenu.writeService();
   	      break;
       case '2': recordMenu.displayAll();break;
       case '3':
   	       int num;
   	       system("cls");
   	       cout<<"\n\n\tPlease Enter The Service Number ";
   	       cin>>num;
   	       recordMenu.displayService(num);
   	       break;
         case '4': gasInfo.gasFeeCalculation();
         break;
         case '5': recordMenu.modifyService();
         break;
         case '6': recordMenu.deleteService();
         break;
         case '7': recordMenu.serviceMenu();
   		 getch();
   		 break;
         //case '8': break;
         default:cout<<"\a";adminMenu();
      }
   }










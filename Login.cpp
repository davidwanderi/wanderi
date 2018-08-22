/*
 * Login.cpp
 *
 *  
 *   
 */

#include "Login.h"

using namespace std;
//User login function
void Login::enterPassword(void){

	puts("Enter 8 character password");
	gets(Password);//Reading from standard input 
}

void Login::copyUsername(string str1, string str2){
	strcpy(name, str1.c_str());//copy the str1 to name
	strcat(name, " = ");//concatenate = to name
	strcat(name, str2.c_str());// concatenate strr to name
	cout << name;//returns the result

}

int Login::copyPassword(){
	strcpy(a, "copypassword");// copy "copypassword" to a
	strcpy(b, "copypassword");// copy "copypassword" to b
	strcpy(c, a);// copy the values of a to c
	strcat(c, b);// conacatenate b to c
	printf("a = %s\n", a);// printing the values of a
	return 0;

}

void Login::testUsernamePassword(void) {
	string arg1 = "Test Username and Password.";

	while (arg1[i] != '\0') {
		buff[i] = arg1[i];//reading the array to make sure the values are matching
		i++;
	}
	buff[i] = '\0';
	printf("buff=%s\n", buff);

}

void Login::isPasswordOK(void) {

	puts("Enter Password");

	gets(passwordCheck);
	PwStatus = (strcmp(passwordCheck, "goodpass") == 0);//compares the password against the known good password
	if (PwStatus == false) {
		puts("Access Denied");// deny acess if they dont match
	}
	else {
		puts("Access Granted");//otherwise grant access
	}

}






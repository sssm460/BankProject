// Author: Sussie Manovapillai
// Date: 12-12-2020
// Description: This is the account class function definition file. 
//		After making the constructors and the destructor, there
//		will be sets and gets for the private information of
//		the customer. Then, a series of basic functions of a bank
//		will be implemented such as deposit, withdraw, etc.
//	             

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "account.h"

extern account currAcc;

using namespace std;

//destructor
account::~account(){
	accountList.clear();
}

//default constructor
account::account(){
	firstName = "None";
	lastName = "None";
	ID = 0;
	accountNumber = 0;
	routingNumber = 0;
	currBalance = 0.00;
}
//parameterized constructor
account::account(string f,string n,int i,int a,int r,float b){
	firstName = f;
	lastName = n;
	ID = i;
	accountNumber = a;
	routingNumber = r;
	currBalance = b; 
}
//setting the data
void account::setFirName(string f){
	firstName = f;
}
void account::setLasName(string n){
	lastName = n;
}
void account::setID(int i){
	ID = i;
}
void account::setAccNum(int a){
	accountNumber = a;
}
void account::setRouNum(int r){
	routingNumber = r;
}
void account::setCurrBal(float b){
	currBalance = b;
}

//getting the data
string account::getFirName(){
	return firstName;
}
string account::getLasName(){
	return lastName;
}
int account::getID(){
	return ID;
}
int account::getAccNum(){
	return accountNumber;
}
int account::getRouNum(){
	return routingNumber;
}
float account::getCurrBal(){
	return currBalance;
}

//addAccount() asks the customer their first and last name and then
//gives them their ID, account number, and routing number. Then their
//account is added to the vector of account objects.
void account::addAccount(){
	string givenFirName, givenLasName;
	int givenID,givenAccNum,givenRouNum;
	float currBal = 0.00;

	cout << "Enter first name: " << endl;
	getline(cin,givenFirName);

	cout << "Enter last name: " << endl;
	getline(cin,givenLasName);

	//randomize ID,account number, and routing number
	cout << "Your information:" << endl;
	givenID = rand() % 10 + 1;
	cout << "ID: " << givenID << endl;

	givenAccNum = rand() % 16859535; 
	cout << "Account Number: " << givenAccNum << endl;

	givenRouNum = rand() % 19725185;
	cout << "Routing Number: " << givenRouNum << endl;

	account currAccount(givenFirName,givenLasName,givenID,givenAccNum,givenRouNum,currBal);
	accountList.push_back(currAccount);
}

//loadAccount() loads the customers acocunt information to a file so that 
//one can look back at the file.
void account::loadAccount(){
	//load account information to a file
	ifstream file;
	int i,size,givenID,givenAccNum,givenRouNum;
	float givenCurrBal;
	string givenFirName,givenLasName;

	//try to open file
	file.open("accounts.dat");
	//read in number of accounts
	for(i = 0; i < accountList.size(); i++){
		//read in account info per line
		file >> givenFirName >> givenLasName >> givenID >> givenAccNum >> givenRouNum >> givenCurrBal;
		//store each account object into the vector
		account currAccount(givenFirName,givenLasName,givenID,givenAccNum,givenRouNum,givenCurrBal);
		accountList.push_back(currAccount);
	}
	//close file
	file.close();
}

//storeAccount() stores the customer information in a line seperated by spaces. 
void account::storeAccount(){
	//store account information to a file
	ofstream fileOut;
	//open data file
	fileOut.open("accounts.dat");

	for(int i = 0; i < accountList.size(); ++i){
		//output information for each account
		fileOut <<
		       //	firstName << " " << lastName << " " << ID << " " << accountNumber << " " << 
			//routingNumber << " " << currBalance << endl;
		       	accountList[i].getFirName() << " " << accountList[i].getLasName() << " " <<
			accountList[i].getID() << " " << accountList[i].getAccNum() << " " <<
			accountList[i].getRouNum() << " " << currBalance << endl;
	}
	//close file
	fileOut.close();
}

//depositAcc() adds money to customers account. 
void account::depositAccount(){
	float givenAmount;

	//ask customer how much to add
	cout << "Enter deposit amount: " << endl;
	cin >> givenAmount;

	currBalance += givenAmount;
}

//withdrawAcc() withdraws money if the customer has enough funds to do so.
void account::withdrawAccount(){
	float givenAmount;

	//ask customer how much to add
	cout << "Enter withdraw amount: " << endl;
	cin >> givenAmount;

	if(currBalance >= givenAmount){
		currBalance = currBalance - givenAmount;
	}else cout << "Cannot withdraw amount. Not enough in bank." << endl;
}

//printAccBal() prints out the customers current balance
void account::printAccBal(){
	cout << "Current Account Balance: " << currBalance << endl; 
}

//deleteAcc() deletes a customers account if custoemr gives correct ID.
void account::deleteAccount(){
	string givenName;
	int i = findAccountPlace(givenName);
	accountList.erase(accountList.begin() + i);
	cout << "Account has been erased." << endl;
}

//below are all of the helper functions

//findAccountPlace() will return the place in the vector where that
//customer is to help find the customer fast. 
int account::findAccountPlace(string givenName){
	for(int i = 0; i < accountList.size(); ++i){
		if(accountList[i].getFirName() == givenName){
			return i;
		}
	}
}

// Author: Sussie Manovapillai
// Date: 12-12-2020
// Description: This a a bank system program that includes many basic functions 
//              such as add,load and store account. As well desposit,withdraw,
//              print account balance, and the abilty to delete an account. 
//              This program also utilizes classes,obejcts,
//              vectors, and multiple files.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "account.h"

using namespace std;

//an instance of an account
account currAcc; 

int main()
{
    int choice = -4;
    
    //load in account information
    currAcc.loadAccount();

    cout << "Welcome to the bank!" << endl;
   
    while (choice != 6)
    {
    cout << "1 ~ Make a new account" << endl
         << "2 ~ Deposit Money" << endl;
    cout << "3 ~ Withdraw Money" << endl
         << "4 ~ View Current Balance" << endl;
    cout << "5 ~ Close an Account" << endl
         << "6 ~ Exit" << endl;

    cout << "Please enter your choice: " << endl;
    cin >> choice;
    cin.ignore();

        switch (choice)
        {
        case 1:
            currAcc.addAccount();
            break;
        case 2:
            currAcc.depositAccount();
            break;
        case 3:
            currAcc.withdrawAccount();
            break;
        case 4:
            currAcc.printAccBal();
            break;
        case 5:
            currAcc.deleteAccount();
            break;
	case 6:
	    cout << "Thank you have a nice day!" << endl;
	    exit; 
        }
    } 
    
    //store all of the account information
    currAcc.storeAccount();

    return 0;
}


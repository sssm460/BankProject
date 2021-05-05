// Author: Sussie Manovapillai
// Date: 12-12-2020
// Description: This is the header file for data of a single account
// 		which will be used to make multiple accounts and store them
// 		in a vector.

#include <string> 
#include <vector>
using namespace std;

class account{
    public:
        account(); //default constructor
        account(string,string,int,int,int,float);//parametrized constructor
	~account();//destructor

        void setFirName(string f);
        void setLasName(string n);
        void setID(int i);
        void setAccNum(int a);
        void setRouNum(int r);
        void setCurrBal(float b);

        string getFirName();
        string getLasName();
        int getID();
        int getAccNum();
        int getRouNum();
        float getCurrBal();

	 //basic functions
        void addAccount();
        void loadAccount();
        void storeAccount();
        void depositAccount();
        void withdrawAccount();
        void printAccBal();
        void deleteAccount();

        //helper functions that return information
        int findAccountPlace(string);
	
    private:
        string firstName;
        string lastName;
        int ID;
        int accountNumber;
        int routingNumber;
        float currBalance;

	vector<account> accountList;//a vector of account objects
};


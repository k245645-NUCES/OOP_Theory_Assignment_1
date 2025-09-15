/*Q1(1) Possible Objects and Class can be
1) Name, Bank Balance, IBAN, Email, Password will be member variables
2) Withdraw, Deposit and Show balance will be Getters & setters
3) Authenticate IBAN function will check for Unique IBAN Number in an array of classtype objects 
4) A function make account  will take Email and Password to make account and to use any of the functionality of (2) */ 

#include <iostream>
#include <string>
using namespace std;
class  DWS //Digital Wallet System
{
private:
    /* data */
    string Name;
    int id;
    string IBAN = "24K-" + id;

    long double Bank_Balance;
    
public:
     DWS( )  {cout<< "Enter Your Name: ";cin >> Name; cout << "Enter Your IBAN: ";cin >> id;};
     
    };

 

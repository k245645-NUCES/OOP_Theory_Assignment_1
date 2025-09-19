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
    string id;
    string IBAN = "24K-"+id;

    long double Bank_Balance = 100;
    
public:
    DWS(){} 
    DWS(DWS &c )  {c.Name = Name, c.id = id, c.IBAN = IBAN, c.Bank_Balance = Bank_Balance;}; //Deep Copy constructor 
     //Setters
     void set_Account(){cout << "Enter Your Name: "; cin >> Name; cout <<"Enter your id: "; cin >> id;}
     void add_funds(double fund){Bank_Balance += fund;}
     double withdraw_funds(float fund){Bank_Balance -= fund; return Bank_Balance;}
     // Getters
     double get_check_balance(){return Bank_Balance;}
     string get_name(){return Name;}
     string get_IBAN(){return IBAN +id;}};
// UML DIAGRAM NOT MADE YET
int main (){
    DWS obj1; 
    obj1.set_Account();
    cout << obj1.get_name() <<endl;
    cout << obj1.get_IBAN()<< endl;
     obj1.add_funds(400.5);
    cout << obj1.get_check_balance() <<" is your Bank Balance" << endl;
    return 0;}

 

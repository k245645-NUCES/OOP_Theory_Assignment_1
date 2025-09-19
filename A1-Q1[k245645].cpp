/*Q1(1) Possible Objects and Class can be
1) Name, Bank Balance, IBAN, Email, Password will be member variables
2) Withdraw, Deposit and Show balance will be Getters & setters
3) Authenticate IBAN function will check for Unique IBAN Number in an array of classtype objects 
4) A function make account  will take Email and Password to make account and to use any of the functionality of (2) */ 

#include <iostream>
#include <string>
#include <vector>
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
    DWS(){} // default constructor
    DWS( const DWS  &c )  {Name = c.Name, id = c.id, IBAN = c.IBAN, Bank_Balance = c.Bank_Balance;}; //Deep Copy constructor 
     //Setters
     void set_Account(){cout << "Enter Your Name: "; cin >> Name; cout <<"Enter your id: "; cin >> id;}
     void add_funds(double fund){Bank_Balance += fund;}
     void withdraw_funds(float fund){Bank_Balance -= fund; }
     // Getters
     double get_check_balance(){return Bank_Balance;}
     string get_name(){return Name;}
     string get_IBAN(){return IBAN +id;}};
// UML DIAGRAM NOT MADE YET
class stocks{
    private:
    int Quantity_owned;
    public:
     string ticker_symbol, Company_name;
    float current_price; 
    stocks(){cout << "Enter Ticker symbol: "; cin >> ticker_symbol;
             cout << "Enter Company Name: "; cin >> Company_name;}
    // deep copy constructor made 
    stocks(  stocks  &c )  {Company_name = c.Company_name, ticker_symbol = c.ticker_symbol, current_price = c.current_price, Quantity_owned = c.Quantity_owned;}; //Deep Copy constructor 
   //getter
   
   
   double holding_value(){ 
        cout << "Enter current price: "; cin >> current_price;
        cout << "Enter Quantity Owned: "; cin >> Quantity_owned;
        return {Quantity_owned * current_price};}


};
class MFB //Micro-Finance Bank
{
private:
    /* data */
    int loan_id; string borrower_name; float loan_amount; float const interest_rate = 0.11;

public:
//default constructor
MFB(){cout << "Enter Loan ID: ";cin >> loan_id;
    cout << "Enter Borrower Name: "; cin >> borrower_name; cout << "Enter Loan_Amount: "; cin >> loan_amount;
}
//parameterized constructor
MFB(int param_loan_id, string param_borrower_name, float param_loan_amount, float param_interest_rate):loan_id(param_loan_id),
 borrower_name(param_borrower_name), loan_amount(param_loan_amount), interest_rate(param_interest_rate){}

//copy constructor
MFB(MFB const &b):loan_id(b.loan_id),
 borrower_name(b.borrower_name), loan_amount(b.loan_amount), interest_rate(b.interest_rate){}

double total_repayment(){return {loan_amount + (loan_amount*interest_rate)};}

};

int main (){
    // main code for DWS class
    DWS obj1; 
    obj1.set_Account();
    cout << obj1.get_name() <<endl;
    cout << obj1.get_IBAN()<< endl;
     obj1.add_funds(400.5);
    cout << obj1.get_check_balance() <<" is your Bank Balance" << endl;
    cout << "Now the Deep Copy Constructor will be called" << endl;
   DWS obj2(obj1); // Copy constructor called
    cout << obj2.get_name() <<endl;
    cout << obj2.get_IBAN()<< endl;
    cout << obj2.get_check_balance() <<" is your Bank Balance" << endl;
    
//main code for stock class
    stocks client1; //Object of stock portfolio
    cout << "The holding value is \n" << client1.holding_value() <<"Rs" << endl;
    // copy constructor called
    cout << "copy constructor called "<< endl;
    stocks client2(client1);
    cout << "The holding value is \n" << client2.holding_value() <<"Rs" << endl;
    
    // main code for MFB class
    MFB debt_client1;//default constructor called
    debt_client1.total_repayment();
    MFB debt_client2(245645,"Nofil",40000,0.11); // Parameter constructor called
    debt_client2.total_repayment();
    MFB debt_client3(debt_client2);// copy constructor called 
    debt_client3.total_repayment();
        return 0;}



 

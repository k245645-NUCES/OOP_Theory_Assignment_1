#include<iostream>
#include<string>
using namespace std;
class Book
{private: 
string Title, Author; int ISBN; float Price = 0.0,discounted_price = 0.0;
//Private Setters
void set_price_update(){float discount_rate;
cout << "Enter Discount Rate you want to offer to the Readers: "; cin >> discount_rate;
discounted_price = discount_rate*Price;}
public:
// default constructor
Book(){cout << "Enter Title of the Book: "; cin>> Title;
        cout << "Enter Author of the Book: "; cin >> Author;
        cout << "Enter ISBN of the Book: "; cin >> ISBN;
        cout << "Enter Price of the Book: "; cin >> Price;}
~Book(){cout <<"\nThe Object has been deleted"<< endl;}

//Getters    
double Get_updated_price(){set_price_update(); return discounted_price ;}
void display_info(){
    cout << "Title of the book is: "<< Title << endl;
    cout << "Author of the book is: "<< Author << endl;
    cout << "ISBN is: "<< ISBN << endl;
    cout << "Price of the book is: "<< Price << endl;

}
};
int main(){
    Book Library[2];
    cout<< "------------------Details of the Object are-------------------"<< endl;
    Library[1].display_info();
    cout << "Sale lagi huye hai kitabo per!!!, new price is: \n" <<Library[1].Get_updated_price();
    cout<< "\n------------------Details of the Object are-------------------"<< endl;
    Library[0].display_info();
    cout << "Sale lagi huye hai kitabo per!!!, new price is: \n" <<Library[0].Get_updated_price();
    Book Old_backup[2] = { Library[0], Library[1] }; // backup created using shallow copy constructor 


return 0;
};

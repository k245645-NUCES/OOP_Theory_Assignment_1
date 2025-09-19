#include<iostream>
#include<string>
using namespace std;
class Hospital
{
private:
    string Name;
    int patientID, age;
    double billAmount;
    // private setters
    void set_name(string name){Name = name;}
    void set_id(int id){patientID = id;}
    void set_age(int a){age = a;}
    void set_bill(double bill){billAmount = bill;}
public:
// default constructor    
Hospital(){cout << "Enter Patient Name: "; cin >> Name;
               cout << "Enter Patient ID: "; cin >> patientID;
               cout << "Enter Age: "; cin >> age;
               cout << "Enter Bill Amount: "; cin >> billAmount;}
//deep copy constructor
Hospital( const Hospital  &c )  {Name = c.Name, patientID = c.patientID, age = c.age, billAmount = c.billAmount;}; 
    //getters
    string get_name(){return Name;}
    int get_id(){return patientID;}
    int get_age(){return age;}
    double get_bill(){return billAmount;}
    //setters
    void set_patient_details(string name, int id, int a, double bill){
        set_name(name);
        set_id(id);
        set_age(a);
        set_bill(bill);};
    void display_info(){
        cout << "Patient Name: " << get_name() << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Age: " << age << endl;
        cout << "Bill Amount: " << billAmount << endl;};
    void set_treatment_charges(double charges){
        if(charges >= 0) billAmount += charges; else cout << "Invalid charges." << endl;}};
int main(){
    cout << "------------------------------Hospital Patient Info------------------------------" << endl;
    cout<< "Taking Info of Patient 1 through default constructor " << endl;
    Hospital patient1;
    //displaying patient info
    cout<<"setting new details for patient 1 using setter method"<< endl;
    patient1.set_patient_details("Nofil Ansari", 101, 45, 250.50);
    cout << "----------------------------------Displaying Patient 1 Info: ----------------------------" << endl;
    patient1.display_info();
    patient1.set_treatment_charges(500.75);
    cout << "Updated Bill Amount: " << patient1.get_bill() << endl;
    Hospital patient2 = patient1; // using deep copy constructor
    cout << "--------------------------------------Copied Patient Info:-------------------------------" << endl;
    patient2.display_info();
    return 0;};
  

#include <iostream>
#include <string>

using namespace std;

struct students {string name,department;int age, roll_no;};

class Transport {
private:
    students student1; string pick,drop; double fee = 500.00;bool card_activation = false;bool attendance = false;int tap_count = 0;

public:
    // Default constructor
    Transport() {
        cout << " ------------------------------Student Transport Registration------------------------------" << endl;
        cout << "Enter student name: ";cin >> student1.name;
        cout << "Enter student age: ";cin >> student1.age;
        cout << "Enter student department: ";cin >> student1.department;
        cout << "Enter student roll_no: ";cin >> student1.roll_no;
        cout << "Is transport card activated? (1 for yes, 0 for no): ";cin >> card_activation;
        if (card_activation) {
            cout << "Transport card is activated.\nEnter Pick Up Location: ";cin >> pick;
            cout << "Enter drop location: ";cin >> drop;
        } else {
            cout << "Transport card is not activated. SO enter fees first: ";cin >> fee;
        }
    }

    // Display student transport info
    void display_info() const {
        cout << "Student Name: " << student1.name << endl;
        cout << "Age: " << student1.age << endl;
        cout << "Department: " << student1.department << endl;
        cout << "Roll No: " << student1.roll_no << endl;
        cout << "Transport Card Activated: " << (card_activation ? "Yes" : "No") << endl;
        cout << "Transport Fee: $" << fee << endl;
        cout << "Pick Up Location: " << pick << endl;
        cout << "Drop Location: " << drop << endl;}
    // Simulate tapping the transport card on the bus to record attendance
    void tap_card() {
        if (!card_activation) {
            cout << "Cannot record attendance: transport card not activated for roll " << student1.roll_no << "." << endl;
            return;}
        attendance = true; ++tap_count;
        cout << "Tap recorded for " << student1.name << " (Roll " << student1.roll_no << "). Total taps: " << tap_count << endl;}
    // Print attendance summary for this student
    void show_attendance_record() const {
        cout << "Attendance for " << student1.name<< " (Roll " << student1.roll_no << "): "<< (attendance ? "Present" : "Absent")
         << ", Taps: " << tap_count << endl; }

    void update_route(const string& new_pick, const string& new_drop) {
        pick = new_pick; drop = new_drop;
        cout << "Route updated. New pick up: " << pick << ", New drop: " << drop << endl;}
    // Getters
    double get_fee() const { return fee; }
    string get_pickup() const { return pick; }
    string get_dropoff() const { return drop; }
    bool is_present() const { return attendance; }
    int get_tap_count() const { return tap_count; }
    // Reset attendance (e.g., at the end of a route or day)
    void reset_attendance() {
        attendance = false;tap_count = 0;
        cout << "Attendance reset for " << student1.name << " (Roll " << student1.roll_no << ")." << endl;}};
int main() {
    Transport student_transport[2];
    cout << "----------------------------------Displaying Student 1 Transport Info: ----------------------------" << endl;
    student_transport[0].display_info();
    student_transport[0].tap_card();
    student_transport[0].show_attendance_record();
    student_transport[0].update_route("NewLocationA", "NewLocationB");
    cout << "----------------------------------Displaying Student 2 Transport Info: ----------------------------" << endl;
    student_transport[1].display_info();
    student_transport[1].tap_card();
    student_transport[1].show_attendance_record();
    student_transport[1].reset_attendance();
    return 0;}

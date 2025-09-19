#include <iostream>
#include <string>
using namespace std;
class MovieShow
{
private:
    string showId;
    string movieTitle;
    int screenNo;       // 1..10
    int totalSeats;
    int availableSeats;

public:
    MovieShow()
        : showId(""), movieTitle(""), screenNo(1), totalSeats(0), availableSeats(0) {}

    //getters
    string get_id(){return showId;}
    string get_movie_title(){return movieTitle;}
    int get_screenNo(){return screenNo;}
    int get_totalseats(){return totalSeats;}
    int get_available(){return availableSeats;}
    //setters
    void set_showId(string id){showId = id;}
    void set_movieTitle(string title){movieTitle = title;}
    void set_screenNo(int screen){if(screen >=1 && screen <=10) screenNo = screen;}
    void set_totalSeats(int seats){totalSeats = seats; availableSeats = seats;}
    void set_availableSeats(int seats){availableSeats = seats;} 
    void reserve_seats(int n ){
        if(n <= availableSeats){
            availableSeats -= n;
            cout << n << " seats reserved successfully." << endl;
        } else {
            cout << "Not enough available seats." << endl;
        }}
    void cancel(int n){
        if(n <= (totalSeats - availableSeats)){
            availableSeats += n;
            cout << n << " seats cancelled successfully." << endl;
        } else {
            cout << "Cannot cancel more seats than reserved." << endl;
        }   }

    void display_info(){
        cout << "Show ID: " << showId << endl;
        cout << "Movie Title: " << movieTitle << endl;
        cout << "Screen Number: " << screenNo << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Available Seats: " << availableSeats << endl;};
    void print_summary(){cout << "Movie: " << movieTitle << " | Show ID: " << showId << " | Screen: " << screenNo << " | Available Seats: " << availableSeats << endl;
}};
int main(){
    MovieShow shows[2];
    //setters called
    shows[0].set_showId("S001");
    shows[0].set_movieTitle("Inception");
    shows[0].set_screenNo(5);
    shows[0].set_totalSeats(100);
    //getters called
    cout << "Show ID: " << shows[0].get_id() << endl;
    cout << "Movie Title: " << shows[0].get_movie_title() << endl;
    cout << "Screen Number: " << shows[0].get_screenNo() << endl;
    cout << "Total Seats: " << shows[0].get_totalseats() << endl;
    cout << "Available Seats: " << shows[0].get_available() << endl;

    //reserve seats
    shows[1].set_showId("S002");
    shows[1].set_movieTitle("The Matrix");  
    shows[1].set_screenNo(3);
    shows[1].set_totalSeats(80);
    shows[1].reserve_seats(30);
    cout << "Available Seats after reservation: " << shows[1].get_available() << endl;
    //cancel seats
    shows[1].cancel(10);
    cout << "Available Seats after cancellation: " << shows[1].get_available() << endl;
    //display info
    cout << "-----------------------Displaying Show Information of shows[0]:----------------------" << endl;
    shows[0].display_info();
     cout << "-----------------------Displaying Show Information of shows[1]:----------------------" << endl;
    shows[1].display_info();
    //print summary
    cout << "-----------------------Printing Summary of shows[0]:----------------------" << endl;
    shows[0].print_summary();
    cout << "-----------------------Printing Summary of shows[1]:----------------------" << endl;
    shows[1].print_summary();
return 0;
}

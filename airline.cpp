#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;


struct Flight {
    string flightID;
    string departure;
    string to;
    string date;
    string time;
    string type;
    double ticket;
    int totalseats;
    int seats;
};

//global
int count = 0;
Flight flights[100];
void saveFlight() {
    ofstream file("flights.txt");
    
    for(int i=0 ; i<count ; i++) {
        file << flights[i].flightID<< " "<< flights[i].departure<< " "<< flights[i].to<< " " << flights[i].date<< " "
             << flights[i].time<< " "<< flights[i].ticket<< " "<< flights[i].type<< " "<< flights[i].totalseats << " "
			 << flights[i].seats<< endl;
    }
    
    file.close();
}
void header(){

cout<< "====================================================================================="<<endl<<endl;
cout<< "                     AL - Amin International Airports"<<endl<<endl;
cout<< "====================================================================================="<<endl<<endl;

}
void passenger();

void employee();
// Function to load flights from file
void loadFlights() {
    ifstream file("flights.txt");
    
    if(!file) {
        return;  // File doesn't exist yet
    }
    
    count = 0;
    while(file >> flights[count].flightID) {
        file >> flights[count].departure;
        file >> flights[count].to;
        file >> flights[count].date;
        file >> flights[count].time;
        file >> flights[count].ticket;
        file >> flights[count].type;
        file >> flights[count].totalseats;
        file >> flights[count].seats;
        count++;
    }
    
    file.close();
}

void display(){
	if(count == 0)
	{
		cout<< "No Flights are Avilable...!";
		return;
	}
	
	cout<< "  =====   All Flights   =====  "<<endl;
	for( int i=0 ; i<count ; i++)
	{
		 cout << "Flight " << (i+1)<< endl;
        cout << "Flight ID: "<< flights[i].flightID<< endl;
        cout << "From: "<< flights[i].departure << " To: "<< flights[i].to << endl;
        cout << "Date: "<< flights[i].date << " Time: "<< flights[i].time << endl;
        cout << "Type: "<< flights[i].type<< endl;
        cout << "Price: Rs."<< flights[i].ticket<< endl;
        cout << "Total Seats: "<< flights[i].totalseats<< endl;
        cout << "Available Seats: "<< flights[i].seats<< endl;
        cout << "--------------------------------------\n";
        
	}

   
}



void Add(){
	
if(count >= 100)
{
	cout<<"Data Base is Full...!";
	return;
}
	cout<< "===  Add Flight  ==="<< endl;
	cout<< "Enter Flight Id: ";  cin>> flights[count].flightID;
	cout<< "Enter Departuer Place: ";  cin>> flights[count].departure;
	cout<< "Enter Destination: ";  cin>> flights[count].to;
	cout<< "Enter Flight Date: ";  cin>> flights[count].date;
	cout<< "Enter Flight Time: ";  cin>> flights[count].time;
	cout<< "Enter Flight Ticket: ";  cin>> flights[count].ticket;
	cout<< "Enter No. of Seats ";  cin>> flights[count].totalseats;
	cout<< "Enter the Class of Flight: ";  cin>> flights[count].type;
	flights[count].seats = flights[count].totalseats;
	
	count++;
	saveFlight();
	cout<< "Data Added Successfully...!"<<endl;

    cout<< "Press '0' to Quit this Menu: ";
    int ky;
    cin>> ky;
    if ((ky == 0))
    {
        system("cls");
        employee();
    }
    else 
    ky = 'c';
	} 



void remove(){
	display();
	
if(count == 0)
{
	cout<< "NO Flight To Delete...!";
	return;
}
string target;
int index = -1;
cout <<"Enter the Flight Id of Flight You Want to Delete: "; cin>>target;
	for(int i=0 ; i<count ; i++)
{
	if( flights[i].flightID == target )
	{
		index = i;
		break;
	}
	
}
if( index == -1)
{
	cout<< "No Such Flight Found...!";
	return;
}
	for(int i = index; i < count - 1; i++)
    {
        flights[i] = flights[i + 1];
    }
    
    count--;  // Decrease the total count
    saveFlight();  // Save to file
    cout<< "Flight deleted successfully!"<< endl;

    cout<< "Press Q to Quit to menu: ";
    char ky;
    cin>> ky;
    if ((ky == 'Q') || (ky == 'q'))
    {
        system("cls");
        employee();
    }
    else
     ky = 'c';
}
void ticket(Flight f, string passengerName) {
    // Create simple booking ID
    string bookingID = "BK001";
    
    // Create filename
    string filename = "Ticket_" + f.flightID + ".txt";
    
    // Open file
    ofstream file(filename);
    
    // Write ticket details
    file << "========================================\n";
    file << "         FLIGHT TICKET                  \n";
    file << "========================================\n";
    file << "Booking ID: " << bookingID <<endl;
    file << "Passenger Name: " << passengerName <<endl;
    file << "Flight ID: " << f.flightID <<endl;
    file << "From: " << f.departure <<endl;
    file << "To: " << f.to <<endl;
    file << "Date: " << f.date <<endl;
    file << "Time: " << f.time <<endl;
    file << "Class: " << f.type <<endl;
    file << "Price: Rs." << f.ticket <<endl;
    file << "========================================\n";
    file << "Thank you for choosing our airline!\n";
    file << "========================================\n";


    
    file.close();
    
    cout << "Ticket saved as: " << filename << endl;
}

void book() {
    display();
    
    if(count == 0) {
        return;
    }
    
    string flightID, passengerName;
    cout << "\nEnter Flight ID to book: ";
    cin >> flightID;
    
    // Find the flight
    int index = -1;
    for(int i = 0; i < count; i++) {
        if(flights[i].flightID == flightID) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        cout << "Flight not found!" << endl;
        return;
    }
    
    if(flights[index].seats <= 0) {
        cout << "No seats available!" << endl;
        return;
    }
    
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, passengerName);
    
    // Decrease available seats
    flights[index].seats--;
    saveFlight();
    
    // Generate ticket
    ticket(flights[index], passengerName);
    
    cout << "\nBooking Successful! Ticket has been generated.\n";

    cout<< "Press 'Q' to quit to menu: ";
    char ky;
    cin>> ky;
    if((ky == 'Q') || (ky == 'q'))
    {
        system("cls");
        passenger();
        
    }
else ky = 'c';
}

void passenger() {
    int choice;
    
    while(true) {
        cout << "\n  =====  PASSENGER MENU  ======  "<<endl;
        cout << "1. Display All Flights\n";
        cout << "2. Book Flight\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if(choice == 1) {
            system("cls");
            header();
            display();
             cout<<"\n Press Q to Quit: ";
    char ky;
    cin>> ky;
    if((ky == 'q') || (ky == 'Q'))
    {
        system ("cls");
        header();
        passenger();
    }

        }
        else if(choice == 2) {
            system("cls");
            book();
        }
        else if(choice == 3) {
            system("cls");
            return;
              
        }
        else {
            cout << "Invalid choice!\n";
        }
    }}
    
    void employee() {
    int choice;
    
    while(true) {
        cout << "\n--- EMPLOYEE MENU ---\n";
        cout << "1. Add Flight\n";
        cout << "2. Delete Flight\n";
        cout << "3. Display All Flights\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if(choice == 1) {
            system("cls");
            header();
            Add();
        }
        else if(choice == 2) {
            system("cls");
            header();
            remove();
        }
        else if(choice == 3) {
           system("cls");
           header();
            display();
             cout<<"\n Press Q to Quit: ";
    char ky;
cin>> ky;
             if((ky == 'q') || (ky == 'Q'))
             {
                system ("cls");
                employee();
              }
              else ky = 'c';
        }
        else if(choice == 4) {
            
            system("cls");
        break;
        }
        else {
            cout << "Invalid choice...!";
        }
    }
}

void employeeLogin(){
    system("cls");
    cout<<"  ===== Login =====  "<<endl;
    cout<<"\n Enter Password: ";
    string password;
    cin>>password;

    if ((password == "amin") || (password == "Amin") || (password == "AMIN" ))
    {
        system("cls");
        employee();
    }
    else
   {
     system("cls");
    cout<<"Invalid Input...!"<<endl;
   }

}

int main() {
    loadFlights();  // Load flights at start
    
    int choice;
    
    while(true) {
        header();
        cout << "1. Passenger\n";
        cout << "2. Employee\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if(choice == 1) {
            system("cls");
            header();
             passenger();
        }
        else if(choice == 2) {
           
            system("cls");
            header();
           employeeLogin();
           
        }
        else if(choice == 3) {
            break;  // Exit program
        }
        else {
            cout << "Invalid choice! Try again.";
        }
    }
    
    return 0;
}


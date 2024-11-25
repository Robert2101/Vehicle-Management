#include <iostream>
#include <string>
using namespace std;

static int p = 0; // Bus count
static int q = 0; // Car count

class Vehicle
{
public:
    virtual void setupVehicle(string, string, string, string = "", string = "", string = "") = 0;
};

class Bus : public Vehicle
{
    string busn, driver, arrival, depart, from, to;
    string seat[8][4]; // 32 seats arranged in 8x4 grid

public:
    static Bus bus[10]; // Array of 10 buses
    void setupVehicle(string b, string d, string arr, string dep, string f, string t) override;
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
};

Bus Bus::bus[10]; // Static array definition

void vline(char ch, string color = "\033[34m") // Default blue color
{
    cout << color;
    for (int i = 80; i > 0; i--)
    {
        cout << ch;
    }
    cout << "\033[0m"; // Reset color
    cout << endl;
}

void Bus::setupVehicle(string b, string d, string arr, string dep, string f, string t)
{
    busn = b;
    driver = d;
    arrival = arr;
    depart = dep;
    from = f;
    to = t;
    empty(); // Initialize all seats as empty
    p++;
}

void Bus::allotment()
{
    int seat_num;
    string number;

    cout << "Enter Bus Number: ";
    cin >> number;

    int n;
    for (n = 0; n < p; n++)
    {
        if (bus[n].busn == number)
        {
            break;
        }
    }

    if (n >= p)
    {
        cout << "Enter a proper bus number!" << endl;
        return;
    }

    cout << "Seat Number: ";
    cin >> seat_num;

    if (seat_num > 32 || seat_num < 1)
    {
        cout << "Exception: There are only 32 seats available in this bus" << endl;
    }
    else
    {
        if (bus[n].seat[(seat_num - 1) / 4][(seat_num - 1) % 4] == "Empty")
        {
            cout << "Enter Passenger's Name: " << endl;
            cin.ignore();
            getline(cin, bus[n].seat[(seat_num - 1) / 4][(seat_num - 1) % 4]);
            cout << "\033[1;92m***Successfully Booked***\033[0m";
        }
        else
        {
            cout << "This seat is already reserved." << endl;
        }
    }
}

void Bus::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            seat[i][j] = "Empty";
        }
    }
}

void Bus::show()
{
    string number;
    cout << "\033[33mEnter Bus No.: \033[0m"; // Yellow prompt
    cin >> number;

    int n;
    for (n = 0; n < p; n++)
    {
        if (bus[n].busn == number)
        {
            break;
        }
    }

    if (n >= p)
    {
        cout << "\033[31mEnter a proper bus number!\033[0m" << endl; // Red for error
        return;
    }

    vline('*', "\033[36m");                                         // Cyan divider
    cout << "\033[1;35mBus Number: \033[0m" << bus[n].busn << endl; // Magenta bold
    cout << "\033[1;32mDriver: \033[0m" << bus[n].driver << endl;
    cout << "\033[1;36mArrival Time: \033[0m" << bus[n].arrival
         << "\t\033[1;36mDeparture Time: \033[0m" << bus[n].depart << endl;
    cout << "\033[1;33mFrom: \033[0m" << bus[n].from << "\t\033[1;33mTo: \033[0m" << bus[n].to << endl;
    vline('*', "\033[36m");

    bus[n].position(n);

    int a = 1;
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (bus[n].seat[i][j] != "Empty")
    //         {
    //             cout << "\033[31mThe seat no. " << a << " is reserved for " << bus[n].seat[i][j] << "\033[0m" << endl; // Red
    //         }
    //         else
    //         {
    //             cout << "\033[32mThe seat no. " << a << " is available.\033[0m" << endl; // Green
    //         }
    //         a++;
    //     }
    // }
}
void Bus::position(int l)
{
    int s = 0, empty_seats = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << endl;
        for (int j = 0; j < 4; j++)
        {
            s++;
            cout.width(5);
            cout.fill(' ');
            cout << s << ".";
            cout.width(10);
            cout.fill(' ');

            // Display seat status
            if (bus[l].seat[i][j] == "Empty")
            {
                cout << "\033[32m" << bus[l].seat[i][j] << "\033[0m"; // Green for empty
                empty_seats++;
            }
            else
            {
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << endl
         << "No. of empty seats: " << empty_seats << endl;
}

void Bus::avail()
{
    for (int n = 0; n < p; n++)
    {
        vline('*');
        cout << "Bus Number: " << bus[n].busn << endl;
        cout << "Driver: " << bus[n].driver << endl;
        cout << "Arrival Time: " << bus[n].arrival << "\tDeparture Time: " << bus[n].depart << endl;
        cout << "From: " << bus[n].from << "\tTo: " << bus[n].to << endl;
        vline('*');
        vline('_');
    }
}

class Car : public Vehicle
{
    string carNumber, customerName; // Added customer name to store reservation info

public:
    static Car car[10];

    void setupVehicle(string number, string = "", string = "", string = "", string = "", string = "") override
    {
        carNumber = number;
        customerName = "Empty"; // Initialize as empty
        q++;
    }

    void bookCar();
    void showCar();
};

Car Car::car[10]; // Static array definition

void Car::bookCar()
{
    string number, customer;
    cout << "Enter Car Number: ";
    cin >> number;

    int n;
    for (n = 0; n < q; n++)
    {
        if (car[n].carNumber == number)
        {
            break;
        }
    }

    if (n >= q)
    {
        cout << "Car not found. Enter a proper car number!" << endl;
        return;
    }

    if (car[n].customerName != "Empty")
    {
        cout << "This car is already reserved by " << car[n].customerName << "." << endl;
        return;
    }

    cout << "Enter Customer's Name: ";
    cin >> customer;
    car[n].customerName = customer; // Assign customer name to the car
    cout << "\033[1;92mCar " << car[n].carNumber << " has been successfully booked for " << customer << ".\033[0m" << endl;
}

void Car::showCar()
{
    for (int i = 0; i < q; i++)
    {
        vline('_', "\033[36m"); // Cyan divider
        cout << "\033[1;35mCar Number: \033[0m" << car[i].carNumber << endl;

        if (car[i].customerName == "Empty")
        {
            cout << "\033[42m\033[30mStatus: Available\033[0m" << endl; // Green background
        }
        else
        {
            cout << "\033[41m\033[30mStatus: Booked by " << car[i].customerName << "\033[0m" << endl; // Red background
        }
    }
}

class Bike : public Vehicle
{
    string bikeNumber, customerName; // Store bike number and customer info

public:
    static Bike bike[10];

    void setupVehicle(string number, string = "", string = "", string = "", string = "", string = "") override
    {
        bikeNumber = number;
        customerName = "Empty"; // Initialize as empty
    }

    void bookBike();
    void showBike();
};

Bike Bike::bike[10]; // Static array definition

void Bike::bookBike()
{
    string number, customer;
    cout << "Enter Bike Number: ";
    cin >> number;

    int n;
    for (n = 0; n < 10; n++)
    {
        if (bike[n].bikeNumber == number)
        {
            break;
        }
    }

    if (n >= 10 || bike[n].bikeNumber.empty())
    {
        cout << "\033[31mBike not found. Enter a proper bike number!\033[0m" << endl;
        return;
    }

    if (bike[n].customerName != "Empty")
    {
        cout << "\033[33mThis bike is already reserved by " << bike[n].customerName << ".\033[0m" << endl; 
        return;
    }

    cout << "Enter Customer's Name: ";
    cin >> customer;
    bike[n].customerName = customer;                                                                                           
    cout << "\033[1;92mBike " << bike[n].bikeNumber << " has been successfully booked for " << customer << ".\033[0m" << endl; 
}

void Bike::showBike()
{
    for (int i = 0; i < 10; i++)
    {
        if (bike[i].bikeNumber.empty())
        {
            continue;
        }

        vline('_', "\033[36m"); 
        cout << "\033[1;35mBike Number: \033[0m" << bike[i].bikeNumber << endl;

        if (bike[i].customerName == "Empty")
        {
            cout << "\033[42m\033[30mStatus: Available\033[0m" << endl; 
        }
        else
        {
            cout << "\033[41m\033[30mStatus: Booked by " << bike[i].customerName << "\033[0m" << endl; 
        }
    }
}
int main()
{

    Bus::bus[0].setupVehicle("KA01", "John", "08:00 AM", "02:00 PM", "Bangalore", "Chennai");
    Bus::bus[1].setupVehicle("KA02", "Mark", "09:00 AM", "03:00 PM", "Hyderabad", "Delhi");
    Bus::bus[2].setupVehicle("KA03", "Steve", "10:00 AM", "04:00 PM", "Chennai", "Mumbai");
    Bus::bus[3].setupVehicle("KA04", "Paul", "11:00 AM", "05:00 PM", "Delhi", "Bangalore");
    Bus::bus[4].setupVehicle("KA05", "Alice", "12:00 PM", "06:00 PM", "Pune", "Chennai");
    Bus::bus[5].setupVehicle("KA06", "Rita", "01:00 PM", "07:00 PM", "Kolkata", "Mumbai");
    Bus::bus[6].setupVehicle("KA07", "Sam", "02:00 PM", "08:00 PM", "Chennai", "Hyderabad");

    Car::car[0].setupVehicle("CAR001", "Alex", "9876543210");
    Car::car[1].setupVehicle("CAR002", "Blake", "8765432109");
    Car::car[2].setupVehicle("CAR003", "Charlie", "7654321098");
    Car::car[3].setupVehicle("CAR004", "David", "6543210987");
    Car::car[4].setupVehicle("CAR005", "Eva", "5432109876");
    Car::car[5].setupVehicle("CAR006", "Felix", "4321098765");
    Car::car[6].setupVehicle("CAR007", "Grace", "3210987654");

    Bike::bike[0].setupVehicle("BIKE001");
    Bike::bike[1].setupVehicle("BIKE002");
    Bike::bike[2].setupVehicle("BIKE003");
    Bike::bike[3].setupVehicle("BIKE004");
    Bike::bike[4].setupVehicle("BIKE005");
    Bike::bike[5].setupVehicle("BIKE006");
    Bike::bike[6].setupVehicle("BIKE007");

    int choice;

    while (true)
    {
        cout << endl
             << "\033[1;96m*** Welcome to URS Reservation System ***\033[0m" << endl; 
        cout << "\033[1;96m1. Reserve Bus Seat\033[0m\n"
             << "\033[1;96m2. Show Bus Details\033[0m\n"
             << "\033[1;96m3. Available Buses\033[0m\n"
             << "\033[1;96m4. Reserve a Car\033[0m\n"
             << "\033[1;96m5. Show Car Details\033[0m\n"
             << "\033[1;96m6. Reserve a Bike\033[0m\n"
             << "\033[1;96m7. Show Bike Details\033[0m\n"
             << "\033[1;96m8. Exit\033[0m" << endl; 
        cout << "\033[1;96mEnter your choice: \033[0m";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;31mInvalid input! Please enter a number.\033[0m" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            Bus::bus[0].allotment();
            break;
        case 2:
            Bus::bus[0].show();
            break;
        case 3:
            Bus::bus[0].avail();
            break;
        case 4:
            Car::car[0].bookCar();
            break;
        case 5:
            Car::car[0].showCar();
            break;
        case 6:
            Bike::bike[0].bookBike();
            break;
        case 7:
            Bike::bike[0].showBike();
            break;
        case 8:
            cout << "\033[1;92mThank you for using the URS Reservation System. Goodbye!\033[0m" << endl;
            exit(0);
        default:
            cout << "\033[1;33mInvalid choice! Please enter a number between 1 and 6.\033[0m" << endl; 
        }
    }

    return 0;
}
#include<iostream>
#include <string>
#include <conio.h>
#include <iomanip>

#define max 100
using namespace std;

static int count = 0;

void check_pass();

void welcome() {
	system("color 5b");
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t-----------------------------";
	cout << "\n\t\t\t\t\t---Hotel Management System---";
	cout << "\n\t\t\t\t\t-----------------------------\n";
	cout << "\n\t\t\t\t\tGroup Members...";
	cout << "\n\t\t\t\t\t->Mubahil Ahmad";
	cout << "\n\t\t\t\t\t->Ahsan Ahmed";
	cout << "\n\t\t\t\t\t->Syed Ali Zain";
	cout << "\n\t\t\t\t\t->Hadia Abbas";
	cout << "\n\t\t\t\t\t->Salwa Shahid Farooqi";

	cout << "\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	check_pass();

}

template <typename T>
void input_validation(T& value) {

	while (!cin.good()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nERROR! Faulty value...";
		cout << "\nEnter again: ";
		cin >> value;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

template <typename U>
bool check_legnth(U& num, U digit) {
	U count, cal, copy;
jump:
	copy = num;
	cal = 0;
	while (copy > 0) {
		copy /= 10;
		++cal;
	}
	while (cal != digit) {
		return false;
		goto jump;
	}
	return true;
}

//Class Customer
class customer_details
{
	int booking_id;
	string name;
	string city;
	int age;
	char gender;
	long long int phone_number;
	int total_days;
	int advance_payment;

public:
	customer_details() {
		booking_id = 0;
		name = "?";
		city = "?";
		age = 0;
		gender = '?';
		phone_number = 0;
		advance_payment = 0;
	}

	void set_values(int booking_id, string name, int age, char gender, long long int phone_number, string city, int total_days, int advance_payment);

	int get_bookingID() {
		return booking_id;
	}
	string get_name() {
		return name;
	}
	string get_city() {
		return city;
	}
	int get_age() {
		return age;
	}
	char get_gender() {
		return gender;
	}
	long long int get_number() {
		return phone_number;
	}

	int get_days() {
		return total_days;
	}

	int get_advancePayment() {
		return advance_payment;
	}
};

void customer_details::set_values(int booking_id, string name, int age, char gender, long long int phone_number, string city, int total_days, int advance_payment) {
	this->booking_id = booking_id;
	this->name = name;
	this->city = city;
	this->age = age;
	this->gender = gender;
	this->phone_number = phone_number;
	this->total_days = total_days;
	this->advance_payment = advance_payment;
}

class Room
{

public:
	customer_details cust;  //composition

	int room_number;
	char comfort_type;
	char room_size;
	char air_conditioning;
	int rent;
	bool availability;

	Room add_room(int);
	void search_room(int);
	void display_room(Room);
};

Room rooms[max];

Room Room::add_room(int room_number)
{
	Room room;
	room.room_number = room_number;
	bool flag = 1;

	cout << "\nAir Conditioning\n> Available (Y)\n> Unavailable (N)\n>: ";
	cin >> room.air_conditioning;
	input_validation(room.air_conditioning);
	while (flag)
	{
		if ((room.air_conditioning == 'Y' || room.air_conditioning == 'N') || (room.air_conditioning == 'y' || room.air_conditioning == 'n')) {
			flag = 0;
		}
		else {
			cout << "Enter correct value: ";
			cin >> room.air_conditioning;
			input_validation(room.air_conditioning);
			flag = 1;
		}
	}

	flag = 1;
	cout << "\nComfort type\n> Supreme (S)\n> Normal (N)\n>:";
	cin >> room.comfort_type;
	input_validation(room.comfort_type);
	while (flag)
	{
		if ((room.comfort_type == 'S' || room.comfort_type == 'N') || (room.comfort_type == 's' || room.comfort_type == 'n')) {
			flag = 0;
		}
		else {
			cout << "Enter correct value: ";
			cin >> room.comfort_type;
			input_validation(room.comfort_type);
			flag = 1;
		}
	}

	flag = 1;
	cout << "\nRoom size\n> Double (D)\n> Single (S)\n>:";
	cin >> room.room_size;
	input_validation(room.room_size);
	while (flag)
	{
		if ((room.room_size == 'D' || room.room_size == 'S') || (room.room_size == 'd' || room.room_size == 's')) {
			flag = 0;
		}
		else {
			cout << "Enter correct value: ";
			cin >> room.room_size;
			input_validation(room.room_size);
			flag = 1;
		}
	}

	cout << "\nDaily Rent : ";
	cin >> room.rent;
	input_validation(room.rent);
	while (room.rent <= 0) {
		cout << "\nEnter a positive value: ";
		cin >> room.rent;
		input_validation(room.rent);
	}

	room.availability = 0;

	cout << "\nRoom Added Successfully!";
	cout << "\nPress ENTER to continue...";
	getch();
	return room;
}

void Room::search_room(int room_number)
{
	bool found = 0;
	int i;
	for (i = 0; i < count; i++)
	{
		if (rooms[i].room_number == room_number)
		{
			found = 1;
			break;
		}
	}
	if (found)
	{
		cout << "\nRoom Details";
		cout << "\n----------------------\n";
		if (rooms[i].availability == 1)
		{
			cout << "\nRoom is Reserved!";
		}
		else
		{
			cout << "\nRoom is Available!";
		}
		display_room(rooms[i]);
		getch();
	}
	else
	{
		cout << "\nRoom not found.";
		cout << "\nPress ENTER to continue...";
		getch();
	}
}

void Room::display_room(Room tempRoom)
{
	cout << "\n\nRoom Number: " << setw(10) << tempRoom.room_number;
	cout << "\nAir Conditioning: ";
	if (tempRoom.air_conditioning == 'Y' || tempRoom.air_conditioning == 'y') {
		cout << setw(11) << "Available";
	}
	else {
		cout << setw(13) << "Unavailable";
	}
	cout << "\nRoom Comfort: ";
	if (tempRoom.comfort_type == 'S' || tempRoom.comfort_type == 's') {
		cout << setw(13) << "Supreme";
	}
	else {
		cout << setw(12) << "Normal";
	}
	cout << "\nRoom Size: ";
	if (tempRoom.room_size == 'D' || tempRoom.room_size == 'd') {
		cout << setw(19) << "Double Bed";
	}
	else {
		cout << setw(19) << "Single bed";
	}
	cout << "\nDaily Rent: " << setw(11) << tempRoom.rent;
	cout << "\n\nPress ENTER to continue...";
}

//hotel management class
class Management :protected Room
{
public:
	void check_in();
	void availabe_rooms();
	void search_customer(int);
	void check_out(int);
	void customers_summary();
};

void Management::customers_summary() {

	for (int i = 0; i < count; i++)
	{
		if (rooms[i].availability == 1)
		{
			system("cls");
			cout << "\n   -----------------------";
			cout << "\n   ---Customers Summary---";
			cout << "\n   -----------------------\n\n";

			cout << "\nBooking ID: " << setw(10) << rooms[i].cust.get_bookingID();
			cout << "\nRoom Number: " << setw(7) << rooms[i].room_number;
			cout << "\nName: " << setw(24) << rooms[i].cust.get_name();
			cout << "\nAge: " << setw(14) << rooms[i].cust.get_age();
			cout << "\nGender: ";
			if (rooms[i].cust.get_gender() == 'F' || rooms[i].cust.get_gender() == 'f') {
				cout << setw(15) << "Female";
			}
			else if (rooms[i].cust.get_gender() == 'M' || rooms[i].cust.get_gender() == 'm') {
				cout << setw(13) << "Male";
			}
			else {
				cout << setw(22) << "Not Specified";
			}
			cout << "\nPhone Number: " << setw(13) << rooms[i].cust.get_number();
			cout << "\nCity: " << setw(17) << rooms[i].cust.get_city();
			cout << "\nDays of stay: " << setw(4) << rooms[i].cust.get_days();
			cout << "\n\nAdvance Payment: " << setw(3) << rooms[i].cust.get_advancePayment();
			cout << "\n--------------------------";
			cout << "\n\nPress ENTER to continue...\n\n";
			getch();
		}
		else {
			cout << "\nNo Guest in Hotel!!";
			cout << "\nPress ENTER to continue...";
			getch();
		}
	}

}

//hotel management reservation of room
void Management::check_in()
{
	int i, j, roomNumber, cal, payment;
	bool found = 0, flag;

	Room room;

	int booking_id, total_days, advance_payment, age;
	string name, city;
	char gender;
	long long int phone_number, copy;


	cout << "Enter Room number : ";
	cin >> roomNumber;
	input_validation(roomNumber);
	while (!check_legnth(roomNumber, 3)) {
		cout << "Enter 3-Digit room number: ";
		cin >> roomNumber;
		input_validation(roomNumber);
	}

	for (i = 0; i < count; i++)
	{
		if (rooms[i].room_number == roomNumber)
		{
			found = 1;
			break;
		}
	}
	if (!found) {
		cout << "Room does not exist\n";
		system("pause");
		return;
	}
	else if (found)
	{
		if (rooms[i].availability == 1)
		{
			cout << "\nRoom is already Booked";
			cout << "\nPress ENTER to continue...";
			getch();
			return;
		}


		cout << "\nEnter booking ID: ";
		cin >> booking_id;
		input_validation(booking_id);
		while (!check_legnth(booking_id, 5)) {
			cout << "Enter 5-Digit booking ID: ";
			cin >> booking_id;
			input_validation(booking_id);
		}

		found = 0;
		for (j = 0; j < count; j++) {
			if (rooms[j].cust.get_bookingID() == booking_id) {
				found = 1;
				break;
			}
		}
		if (found) {
			cout << "\nBooking id already exist";
			cout << "\npress ENTER to continue...";
			getch();
			return;
		}
		else {
			cout << "\nEnter Name: ";
			getline(cin, name);

			while ((name <= "A" || name >= "Z") && (name <= "a" || name >= "z"))
			{
				cout << "Enter the name again:";
				getline(cin, name);
			}

			cout << "\nEnter age: ";
			cin >> age;
			input_validation(age);
			while (age <= 0 || age >= 114) {
				cout << "\nAre you in your senses...???";
				cout << "\nEnter a reasonable age: ";
				cin >> age;
				input_validation(age);
			}
			flag = 1;
			cout << "\nEnter gender\n>Male (M)\n>Female (F)\n>Not Specified (N)\n>: ";
			cin >> gender;
			while (flag)
			{
				if ((gender == 'F' || gender == 'f') || (gender == 'M' || gender == 'm') || (gender == 'N' || gender == 'n')) {
					flag = 0;
				}
				else {
					cout << "Enter correct value: ";
					cin >> gender;
					flag = 1;
				}
			}

			cout << "\nEnter Phone Number: ";
			cin >> phone_number;
			input_validation(phone_number);
		jump1:
			copy = phone_number;
			cal = 0;
			while (copy > 0) {
				copy /= 10;
				++cal;
			}
			while (cal != 10) {
				cout << "Enter 11-Digit phone number: ";
				cin >> phone_number;
				input_validation(phone_number);
				goto jump1;
			}

			cout << "\nEnter city: ";
			cin >> city;
			while ((city <= "A" || city >= "Z") && (city <= "a" || city >= "z"))
			{
				cout << "Enter the city again:";
				cin >> city;
			}

			cout << "\nEnter total days of stay: ";
			cin >> total_days;
			input_validation(total_days);
			while (total_days <= 0 || total_days >= 99) {
				cout << "Enter a value between 0-99: ";
				cin >> total_days;
				input_validation(total_days);
			}

			cout << "\nEnter Advance Payment: ";
			cin >> advance_payment;
			input_validation(advance_payment);

			payment = total_days * rooms[i].rent;

			while (advance_payment <= 0 || advance_payment > payment) {
				if (advance_payment <= 0) {
					cout << "\nEnter a value greater than zero: ";
				}
				else if (advance_payment > payment) {
					cout << "\nDo not accept greater amount than total bill = " << payment;
					cout << "\nEnter again: ";
				}
				cin >> advance_payment;
				input_validation(advance_payment);
			}
			rooms[i].availability = 1;

			rooms[i].cust.set_values(booking_id, name, age, gender, phone_number, city, total_days, advance_payment);

			cout << "\nCustomer Checked-In Successfully..";
			cout << "\nPress ENTER to continue...";
			getch();
		}


	}
}

//hotel management shows available rooms
void Management::availabe_rooms()
{
	int i;
	bool found = 0;
	for (i = 0; i < count; i++)
	{
		if (rooms[i].availability == 0)
		{
			display_room(rooms[i]);
			cout << "\n--------------------------";
			found = 1;
			getch();
		}
	}
	if (!found)
	{
		cout << "\nAll rooms are reserved";
		cout << "\nPress ENTER to continue...";
		getch();
	}
}

//hotel management shows all persons that have booked room
void Management::search_customer(int bookingID)
{
	int i;
	bool found = 0;
	for (i = 0; i < count; i++)
	{
		if (rooms[i].availability == 1 && rooms[i].cust.get_bookingID() == bookingID)
		{
			system("cls");
			cout << "\n   ---------------------";
			cout << "\n   ---Search Customer---";
			cout << "\n   ---------------------\n\n";
			cout << "\nBooking ID: " << setw(10) << rooms[i].cust.get_bookingID();
			cout << "\nRoom Number: " << setw(7) << rooms[i].room_number;
			cout << "\nCustomer Name: " << setw(15) << rooms[i].cust.get_name();
			cout << "\nPhone Number: " << setw(13) << rooms[i].cust.get_number();

			found = 1;
			cout << "\n\nPress ENTER to continue...";
			getch();
		}
	}
	if (!found)
	{
		cout << "\nPerson not found.";
		cout << "\nPress ENTER to continue...";
		getch();
	}
}

//hotel managemt generates the bill of the expenses
void Management::check_out(int roomNumber)
{
	int i;
	bool found = 0, flag = 0;
	float billAmount = 0;
	for (i = 0; i < count; i++)
	{
		if (rooms[i].availability == 1 && rooms[i].room_number == roomNumber)
		{
			found = 1;
			break;
		}
	}
	if (found)
	{

		billAmount = rooms[i].cust.get_days() * rooms[i].rent;

		cout << "\nCheck Out Details";
		cout << "\n-----------------\n";
		cout << "\nRoom Number : " << setw(8) << rooms[i].room_number;
		cout << "\nBooking ID: " << setw(12) << rooms[i].cust.get_bookingID();
		cout << "\nCustomer Name:    " << setw(12) << rooms[i].cust.get_name();
		cout << "\nDays of stay: " << setw(6) << rooms[i].cust.get_days();
		cout << "\nAdvance Paid: " << setw(8) << rooms[i].cust.get_advancePayment() << "/-";
		cout << "\nDaily Rent: " << setw(10) << rooms[i].rent << "/-";
		cout << "\nTotal Charges: " << setw(8) << billAmount << "/-";
		cout << "\n\n***Total Payable: " << setw(5) << billAmount - rooms[i].cust.get_advancePayment() << "/- only";

		rooms[i].availability = 0;
		cout << "\n\nWe were honoured to serve you!";
		cout << "\nPress ENTER to continue...";
		getch();
	}
	else {
		cout << "\nNo guest in this room.";
		cout << "\npress ENTER to continue...";
		getch();
	}
}

//managing rooms (adding and searching available rooms)
void room_management()
{
	Room room;
	int option, i, roomNumber, flag = 0;
	do
	{
		system("cls");
		cout << "\n   -----------------------------";
		cout << "\n   ---Room Management Section---";
		cout << "\n   -----------------------------\n\n";
		cout << " 1-Add Room\n";
		cout << " 2-Search Room\n";
		cout << " 3-Back to Main Menu\n";
		cout << " Enter Option: ";
		cin >> option;
		input_validation(option);
		cout << endl;

		//switch statement
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\n   -----------------------------";
			cout << "\n   ---Room Management Section---";
			cout << "\n   -----------------------------\n\n";
			cout << "Enter Room Number: ";
			cin >> roomNumber;
			input_validation(roomNumber);
			while (!check_legnth(roomNumber, 3)) {
				cout << "Enter 3-Digit room number: ";
				cin >> roomNumber;
				input_validation(roomNumber);
			}

			for (i = 0; i < count; i++)
			{
				if (rooms[i].room_number == roomNumber)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				cout << "\nRoom number already exist.\npress ENTER to continue...";
				flag = 0;
				getch();
			}
			else
			{
				rooms[count] = room.add_room(roomNumber);
				++count;
			}
			break;
		case 2:
			system("cls");
			cout << "\n   -----------------------------";
			cout << "\n   ---Room Management Section---";
			cout << "\n   -----------------------------\n\n";
			cout << "Enter room number: ";
			cin >> roomNumber;
			input_validation(roomNumber);
			while (!check_legnth(roomNumber, 3)) {
				cout << "Enter 3-Digit room number: ";
				cin >> roomNumber;
				input_validation(roomNumber);
			}

			room.search_room(roomNumber);
			break;
		case 3:
			//when user will press enter it will go back to main menu
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (option != 3);
}

void main_menu()
{
	system("color 5b");
	Management m;
	int choice, roomNumber, bookingID;

	while (true) {
		system("cls");
		cout << "\n   ---------------";
		cout << "\n   ---Main Menu---";
		cout << "\n   ---------------\n\n";
		cout << " 1-Manage Rooms\n";
		cout << " 2-Check-In\n";
		cout << " 3-Check-Out\n";
		cout << " 4-Availabe Rooms\n";
		cout << " 5-Search Customer\n";
		cout << " 6-Customers Summary\n";
		cout << " 7-Exit\n";
		cout << " Enter option: ";
		cin >> choice;
		input_validation(choice);
		cout << endl;

		switch (choice) {
		case 1:
			room_management();
			break;

		case 2:

			choice = 0;
			do {
				system("cls");
				cout << "\n   ----------------------";
				cout << "\n   ---Check In Section---";
				cout << "\n   ----------------------\n\n";
				cout << "\n 1-Continue";
				cout << "\n 0-Back to Main Menu";
				cout << "\n Enter option: ";
				cin >> choice;
				input_validation(choice);

				if (choice == 1) {
					if (count == 0) {
						cout << "\nRoom data is not availabe.\nPlease add room first";
						cout << "\npress ENTER to continue...";
						getch();
						break;
					}
					else {
						system("cls");
						cout << "\n   ----------------------";
						cout << "\n   ---Check In Section---";
						cout << "\n   ----------------------\n\n";
						m.check_in();
					}
				}
			} while (choice != 0);

			break;
		case 3:
			choice = 0;
			do {
				system("cls");
				cout << "\n   -----------------------";
				cout << "\n   ---Check Out Section---";
				cout << "\n   -----------------------\n\n";
				cout << "\n 1-Continue";
				cout << "\n 0-Back to Main Menu";
				cout << "\n Enter option: ";
				cin >> choice;
				input_validation(choice);
				if (choice == 1) {
					if (count == 0) {
						cout << "\nRoom data is not availabe.\nPlease add room first";
						cout << "\nPress ENTER to continue...";
						getch();
						break;
					}
					else {
						system("cls");
						cout << "\n   -----------------------";
						cout << "\n   ---Check Out Section---";
						cout << "\n   -----------------------\n\n";
						cout << "Enter room number: ";
						cin >> roomNumber;
						input_validation(roomNumber);
						while (!check_legnth(roomNumber, 3)) {
							cout << "Enter 3-Digit room number: ";
							cin >> roomNumber;
							input_validation(roomNumber);
						}
						m.check_out(roomNumber);
					}
				}
			} while (choice != 0);

			break;
		case 4:
			choice = 0;
			do {
				system("cls");
				cout << "\n   ---------------------";
				cout << "\n   ---Available Rooms---";
				cout << "\n   ---------------------\n\n";
				cout << "\n 1-Continue";
				cout << "\n 0-Back to Main Menu";
				cout << "\n Enter option: ";
				cin >> choice;
				input_validation(choice);
				if (choice == 1) {
					if (count == 0) {
						cout << "\nRoom data is not availabe.\nPlease add room first";
						cout << "\nPress ENTER to continue...";
						getch();
					}
					else {
						system("cls");
						cout << "\n   ---------------------";
						cout << "\n   ---Available Rooms---";
						cout << "\n   ---------------------\n\n";
						m.availabe_rooms();
					}
				}
			} while (choice != 0);
			break;

		case 5:
			choice = 0;
			do {
				system("cls");
				cout << "\n   ---------------------";
				cout << "\n   ---Search Customer---";
				cout << "\n   ---------------------\n\n";
				cout << "\n 1-Continue";
				cout << "\n 0-Back to Main Menu";
				cout << "\n Enter option: ";
				cin >> choice;
				input_validation(choice);
				if (choice == 1) {

					if (count == 0) {
						cout << "\nRoom data is not availabe.\nPlease add room first";
						cout << "\nPress ENTER to continue...";
						getch();
					}
					else {

						cout << "\nEnter the booking ID: ";
						cin >> bookingID;
						input_validation(bookingID);
						while (!check_legnth(bookingID, 5)) {
							cout << "Enter 5-Digit booking ID: ";
							cin >> bookingID;
							input_validation(bookingID);
						}
						m.search_customer(bookingID);
					}
				}
			} while (choice != 0);

			break;
		case 6:
			choice = 0;
			do {
				system("cls");
				cout << "\n   -----------------------";
				cout << "\n   ---Customers Summary---";
				cout << "\n   -----------------------\n\n";
				cout << "\n 1-Continue";
				cout << "\n 0-Back to Main Menu";
				cout << "\n Enter option: ";
				cin >> choice;
				input_validation(choice);
				if (choice == 1) {

					if (count == 0) {
						cout << "\nRoom data is not availabe.\nPlease add room first";
						cout << "\nPress ENTER to continue...";
						getch();
					}
					else {
						system("cls");
						cout << "\n   -----------------------";
						cout << "\n   ---Customers Summary---";
						cout << "\n   -----------------------\n\n";
						m.customers_summary();
					}
				}
			} while (choice != 0);

			break;
		case 7:
			choice = 0;
			do {
				system("cls");
				cout << "\n   ----------------";
				cout << "\n   ---Exit Panel---";
				cout << "\n   ----------------\n\n";
				cout << "\n 1-Exit";
				cout << "\n 0-Back to Main Menu";
				cout << "\n Enter option: ";
				cin >> choice;
				input_validation(choice);
				if (choice == 1) {
					cout << "\nThank you for using the program.\nSigning off...";
					exit(0);
				}
			} while (choice != 0);
		default:
			cout << "Enter correct option\n";
			break;
		}
	}
	getch();
}

void check_pass() {
	system("color 5b");
	string userName;
	string userPassword;
	int loginAttempt = 0;

	while (loginAttempt < 3)
	{

		system("color 5b");
		system("cls");

		cout << "\n   -------------------";
		cout << "\n   ---Login Section---";
		cout << "\n   -------------------\n\n";

		cout << "Please enter your username: ";
		cin >> userName;
		while ((userName < "A" || userName > "Z") && (userName < "a" || userName > "z")) {
			cout << "\nInvalid format...";
			cout << "\nEnter again: ";
			cin >> userName;
		}
		cout << "\nPlease enter your user password: ";
		cin >> userPassword;
		int len = userPassword.length();
		system("cls");
		cout << "\n   -------------------";
		cout << "\n   ---Login Section---";
		cout << "\n   -------------------\n\n";
		cout << "Please enter your username: " << userName << endl;
		cout << "Please enter your user password: ";
		for (int i = 0; i < len; i++) {
			cout << "*";
		}cout << endl;
		if (userName == "Ahsan" && userPassword == "1234")
		{
			system("color 2f");

			cout << "\nAccess Granted.";
			cout << "\n\nWelcome Ahsan!\n\n";
			system("pause");
			main_menu();
			break;
		}
		else if (userName == "Mubahil" && userPassword == "12345")
		{
			system("color 2f");

			cout << "\nAccess Granted.";
			cout << "\n\nWelcome Mubahil!\n\n";
			system("pause");
			main_menu();
			break;
		}
		else if (userName == "Syed" && userPassword == "123456")
		{
			system("color 2f");

			cout << "\nAccess Granted.";
			cout << "\n\nWelcome Zain!\n\n";
			system("pause");
			main_menu();
			break;
		}
		else if (userName == "Salwa" && userPassword == "1234567")
		{
			system("color 2f");

			cout << "\nAccess Granted.";
			cout << "\n\nWelcome Salwa!\n\n";
			system("pause");
			main_menu();
			break;
		}
		else if (userName == "Hadia" && userPassword == "12345678")
		{
			system("color 2f");
			cout << "\nAccess Granted.";
			cout << "\n\nWelcome Hadia!\n\n";
			system("pause");
			main_menu();
			break;
		}
		else
		{
			loginAttempt++;
			system("color 4f");
			cout << "\nInvalid login attempt! \nPlease try again.\n" << '\n';
			cout << "Tries left: " << 3 - loginAttempt << '\n';
			cout << "\nPress ANY KEY to continue...";
			getche();

			if (loginAttempt == 3)
			{
				cout << "Too many login attempts! The program is terminated.";
				exit(0);
			}
		}
	}

}

int main() {
	welcome();
}



#include<iostream>
#include "TicketsBooking.h"
using namespace std;

int main()
{

	system("COLOR 0e");		//Color to change background
	Tickets Tickets1;
	int choice = 0;
	do
	{
		system("cls");
		cout << "\t\t\t    [Air-Line Management System] \n";
		cout << "\t\t==================================================\n\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "\t\t||\t1. Book a new Flight \t\t\t ||\n";
		cout << "\t\t||\t2. Delete latest Booking\t\t ||\n";
		cout << "\t\t||\t3. Modify Booking List \t\t\t ||\n";
		cout << "\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout << "\t\t||\t5. Daily Summary of Ticket bookings \t ||\n";
		cout << "\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout << "\t\t--------------------------------------------------\n";
		cout << "Enter choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			Tickets1.bookingTicket();	//function add
			break;
		}		//end case 1


		case 2:
		{
			Tickets1.cancelTicket();	//function delete
			system("PAUSE");
			break;
		}		//end case 2

		case 3:
		{
			Tickets1.modifyBooking();	//function modify
			system("PAUSE");
			break;
		}		//end case 3

		case 4:
		{
			Tickets1.bookingList();	//function order
			system("PAUSE");
			break;
		}	//end case 4
		case 5:
		{
			Tickets1.bookingSummary();	//function daily_summary
			system("PAUSE");
			break;
		}	//end case 5
		case 6:
		{
			Tickets1.exit();	//function exit
			goto end;
			break;
		}	//end case 6


		default:
		{
			cout << "You enter invalid input\nre-enter the input\n" << endl;
			break;
		}//end defeault

		}//end Switch
	} while (choice != 6);//end do

end://goto
	cout << "sleep,thank you " << endl;
	system("PAUSE");
	

    
    return 0;
}
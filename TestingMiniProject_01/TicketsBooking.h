#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

class Tickets	//base class
{
public:

	void bookingTicket();//to  take_order
	void cancelTicket(); //to delete the order
	void modifyBooking(); //to modify the order
	void bookingList(); //to display the order_list
	void bookingSummary(); //to display daily_summary
	void exit();  //function to exit system
	Tickets();//constuctor

};

class Node {
public:
	Node* prev;
	Node* next;

	int ticketNUmber;
	string passengerName;
	string date;
	int numberOfSeats[10];
	string type = { "OTC" };
	int numTicketTypes, menu2[10];
	double cost[10];
	string airportNames[10] = {};
	double pricesOfTickets[10] = {};
	double total;

};

Node* startPtr = NULL;
Node* head = NULL;
Node* tail = NULL;

int G_receipt = 0;

Tickets::Tickets() {
	//costructor
}

void Tickets::bookingTicket() {
	system("cls");//clean the previous screen
	int choice = 0, quantity = 0, price = 0;

	cout << "\nAdd Details of the Ticket\n";
	cout << "_____________________________________ \n\n";
	cout << "[menu2]\n";

	//otc over the count -that can be use without the advise of speciallist
	cout << "**************************************************************************\n";
	cout << "Destination ID" << "\t" << "   \t\tDestination Name" << "           Prices for the tickets($)" << endl;
	cout << "**************************************************************************\n";
	cout << "001" << "\t" << "\t " << "\t\t" << "    New Delhi" << "				$ 301.00" << endl;
	cout << "002" << "\t" << "\t " << "\t\t" << "    Chicago" << "				$ 960.00" << endl;
	cout << "003" << "\t" << "\t " << "\t\t" << "    Tokyo" << "				$ 986.00" << endl;
	cout << "004" << "\t" << "\t " << "\t\t" << "    Orlando" << "				$ 694.00" << endl;
	cout << "005" << "\t" << "\t " << "\t\t" << "    Miami" << "	 			$ 595.00" << endl;
	cout << "006" << "\t" << "\t " << "\t\t" << "    Dubai" << " 				$ 411.00" << endl;
	cout << "007" << "\t" << "\t " << "\t\t" << "    Beijing" << "				$ 980.00" << endl;
	cout << "008" << "\t" << "\t " << "\t\t" << "    New York" << "				$ 1192.00" << endl;
	cout << "009" << "\t" << "\t " << "\t\t" << "    Wuhan" << "				$ 460.00" << endl;
	cout << "010" << "\t" << "\t " << "\t\t" << "    Istanbul" << "				$ 472.00" << endl;
	cout << " " << endl;

	Node* temp;
	temp = new Node;

	cout << "Type Ticket Number: " << ++G_receipt << endl;

	temp->ticketNUmber = G_receipt;

	cout << "Enter Date : ";
	cin >> temp->date;

	cout << "How many tickets you need to buy : " << endl;
	cout << "( Maximum is 10)" << endl;
	cin >> temp->numTicketTypes;

	if (temp->numTicketTypes > 10) {
		cout << "The flight types you booked are exceed the maximum cost of bookings !";
		system("pause");
	}
	else {
		for (int i = 0; i < temp->numTicketTypes; i++) {
			cout << "Please enter your selection : " << endl;
			cin >> temp->menu2[i];
			cout << "Destination Name: " << temp->airportNames[temp->menu2[i] - 1] << endl;
			cout << "How many destinations you want to reach: ";
			cin >> temp->numberOfSeats[i];
			temp->cost[i] = temp->numberOfSeats[i] * temp->pricesOfTickets[temp->menu2[i] - 1];
			cout << "The cost You need to pay is: " << temp->cost[i] << "$. " << endl;
			system("PAUSE");
		}
		cout << "===========================================================================" << endl;
		cout << "Your Ticket Has Booked Successfully" << endl;
		cout << "===========================================================================" << endl;
		cout << "Go to Reciept Menu to Pay and take The Bill" << endl;
		cout << "===========================================================================" << endl;
		system("PAUSE");//still in the window until user enter some key

		temp->next = NULL;
		if (startPtr != NULL)
		{
			temp->next = startPtr;
		}
		startPtr = temp;
		system("cls");//at the end clean the window
	}
}//End of function bookingTicket

void Tickets::bookingList() //function to display recipt
{
	system("cls");
	int num, num2;
	bool found;		//variable to search that given recipt is found or not

	Node* temp;

	temp = startPtr;
	found = false;

	cout << " Enter the Reciept Number To Print The Reciept\n";
	cin >> num2;
	cout << "\n";
	cout << "===========================================================================" << endl;
	cout << "\t\tHere is the Booking list\n";
	cout << "===========================================================================" << endl;

	if (temp == NULL) //Invalid recipt code
	{
		cout << "\t There is no order to show \n\t\t So The List is Empty\n\n\n";

	}
	while (temp != NULL && !found)
	{
		if (temp->ticketNUmber == num2)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
		if (found)	//print the receipt
		{
			cout << "Reciept Number : " << temp->ticketNUmber;
			cout << "\n";
			cout << "Customer Name: " << temp->passengerName << endl;

			cout << "Booking Date : " << temp->date << endl;

			cout << "_____________________________________________________________________________" << endl;

			cout << "===============================================================================" << endl;
			cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++===============" << endl;
			for (int i = 0; i < temp->numTicketTypes; i++)
			{
				cout << temp->type << "  \t\t";
				cout << temp->airportNames[temp->menu2[i] - 1] << "\t\t\t  ";
				cout << temp->numberOfSeats[i] << "\t\t";
				cout << temp->cost[i] << " $" << endl;
				cout << "_________________________________________________________________________________" << endl;
			}

			temp->total = temp->cost[0] + temp->cost[1] + temp->cost[2] + temp->cost[3] + temp->cost[4] + temp->cost[5] + temp->cost[6] + temp->cost[7]
				+ temp->cost[8] + temp->cost[9];
			cout << "Total cost is : " << temp->total << " $ ";
			cout << "\n";
			cout << "Type the exact cost You need to pay: ";
			cin >> num;

			cout << "\n";
			cout << "\n";
			cout << "Payment Done\nThank You\n";
			cout << "\n_______________________________________________________________________________\n";
		}


	}
} //End function bookingList

void Tickets::cancelTicket()	//function to delete_order
{
	system("cls");
	int i = 0, num = 0, count = 0;
	cout << "Enter the data you want to delete \n";
	cin >> num;
	Node* q;
	Node* temp;
	bool found;

	if (startPtr == NULL)
		cerr << "Can not delete from an empty list.\n";
	else
	{
		if (startPtr->ticketNUmber == num)
		{
			q = startPtr;
			startPtr = startPtr->next;
			count--;
			if (startPtr == NULL)
				tail = NULL;
			delete q;
			cout << "The Reciept is Deleted Successfully" << endl;
		}
		else
		{
			found = false;
			temp = startPtr;
			q = startPtr->next;

			while ((!found) && (q != NULL))
			{
				if (q->ticketNUmber != num)
				{
					temp = q;
					q = q->next;
				}
				else
					found = true;
			}

			if (found)
			{
				temp->next = q->next;
				count--;

				if (tail == q)
					tail = temp;
				delete q;
				cout << "The Reciept is Deleted Successfully" << endl;
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}	//End function of delete_order

void Tickets ::modifyBooking()	//function to modify a given order
{
	system("cls");
	int Modify_num;
	bool found;
	found = false;
	Node* temp;
	temp = startPtr;
	cout << "Enter Receipt Number To Modify: ";
	cin >> Modify_num;
	if (temp == NULL && Modify_num == 0)
	{
		cout << "NO RECORD TO MODIFY..!" << endl;
	}

	else
	{
		while (temp != NULL && !found)
		{
			if (temp->ticketNUmber == Modify_num)
			{
				found = true;
			}
			else
			{
				temp = temp->next;
			}
			if (found)
			{
				cout << "Change  Order Number: ";
				cin >> temp->ticketNUmber;
				cout << "Change Customer Name: ";
				cin >> temp->passengerName;
				cout << "Change Date : ";
				cin >> temp->date;
				cout << "How many New Medicine would you like to Change:" << endl;
				cout << "( Maximum is 10 order for each transaction ) \n";
				cout << "  ";
				cin >> temp->numTicketTypes;
				if (temp->numTicketTypes > 10)
				{
					cout << "The Medicine you order is exceed the maximum cost of order !";
					system("pause");
				}
				else {
					for (int i = 0; i < temp->numTicketTypes; i++)
					{

						cout << "Please enter your selection to Change: " << endl;
						cin >> temp->menu2[i];
						cout << "Change Medicine Name: " << temp->airportNames[temp->menu2[i] - 1] << endl;
						cout << "How many New medicine do you want: ";
						cin >> temp->numberOfSeats[i];
						temp->cost[i] = temp->numberOfSeats[i] * temp->pricesOfTickets[temp->menu2[i] - 1];
						cout << "The cost You need to pay After Modify  is: " << temp->cost[i] << " $" << endl;
						system("PAUSE");
					}
					temp = temp->next;
					system("cls");

				}

				cout << "RECORD MODIFIED....!" << endl;
			}
			else
			{
				if (temp != NULL && temp->ticketNUmber != Modify_num)
				{
					cout << "Invalid Reciept Number...!" << endl;
				}
			}
		}
	}
}		//End modify function

void Tickets ::bookingSummary()		//Function to display Daily Summary
{
	//int  num;
	system("cls");//clear the window
	Node* temp;

	temp = startPtr;


	if (temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\tThere is no Bookings to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout << "\n";
		cout << "===========================================================================" << endl;
		cout << " \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout << "===========================================================================" << endl;

		while (temp != NULL)
		{

			cout << "Reciept Number : " << temp->ticketNUmber;
			cout << "\n";
			cout << "Customer Name: " << temp->passengerName << endl;

			cout << "Order Date : " << temp->date << endl;

			cout << "----------------------------------------------------------------------------" << endl;

			cout << "==========================================================================" << endl;
			cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
			cout << "=======++==================++================++===============++==========" << endl;
			for (int i = 0; i < temp->numTicketTypes; i++)
			{
				cout << temp->type << "   \t\t";
				cout << temp->airportNames[temp->menu2[i] - 1] << " \t\t";
				cout << temp->numberOfSeats[i] << " \t\t";
				cout << temp->cost[i] << " $" << endl;
				cout << "----------------------------------------------------------------------------" << endl;
			}

			temp->total = temp->cost[0] + temp->cost[1] + temp->cost[2] + temp->cost[3] + temp->cost[4] + temp->cost[5] + temp->cost[6] + temp->cost[7]
				+ temp->cost[8] + temp->cost[9];
			cout << "Total Bill is : " << temp->total << " $";

			cout << "\n";
			cout << "\n";
			cout << "\n-----------------------------------------------------------------------------\n";

			temp = temp->next;
		}
	}
}		//End daily summary
void Tickets ::exit() //Function to exit
{
	cout << "\nYou choose to exit.\n" << endl;
}	//end function exit

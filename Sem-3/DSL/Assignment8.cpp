/*
	Samarth (21142 F1-batch)
	DSL Assignment-8

	Problem Statement:
	Write C++ program for storing appointment schedule for day. Appointments are booked
	randomly using linked list. Set start and end time and min and max duration for visit slot.
	Write functions for-
	A) Display free slots
	B) Book appointment
	C) Sort list based on time
	D) Cancel appointment ( check validity, time bounds, availability )
*/

#include <iostream>
using namespace std;

class Node
{
public:
	int start; // Start time
	int end;   // End time
	int min;   // Min duration
	int max;   // Max duration
	int flag;  // Booked OR Free
	Node *next;
} * head, *tmp, *last;

class AppointmentSchedule
{
public:
	int sz; // No of Appointments
	void create();

	void display();

	void bookAppointment();

	void cancel();

	void sortAppointments();

} obj;

void AppointmentSchedule ::create() // Create Appointment Schedule
{
	int i;
	// struct Node *tmp, *last;

	head = NULL;

	cout << "\n\n How many Appointment Slots: ";
	cin >> sz;

	for (i = 0; i < sz; i++)
	{
		tmp = new Node;

		cout << "\n\n Enter Start Time: ";
		cin >> tmp->start;
		cout << "\n Enter End Time: ";
		cin >> tmp->end;
		cout << "\n\n Enter Minimum Duration: ";
		cin >> tmp->min;
		cout << "\n Enter Maximum Duration: ";
		cin >> tmp->max;
		tmp->flag = 0;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			last = head;
		}
		else
		{
			last->next = tmp;
			last = last->next;
		}
	}
}

void AppointmentSchedule ::display() // Display Appointment Schedule
{
	int cnt = 1;

	cout << "\n\n ****Appointment Schdule****";
	cout << "\n\n Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";

	tmp = head;
	while (tmp != NULL)
	{
		cout << "\n\n " << cnt;
		cout << "\t " << tmp->start;
		cout << "\t " << tmp->end;
		cout << "\t  " << tmp->min;
		cout << "\t  " << tmp->max;

		if (tmp->flag)
			cout << "\t-Booked-";
		else
			cout << "\t--Free--";

		tmp = tmp->next;
		cnt++;
	}
}

void AppointmentSchedule ::bookAppointment() // Book Appointment
{
	int start;

	cout << "\n\n Please enter Appointment time: ";
	cin >> start;

	tmp = head;

	while (tmp != NULL)
	{
		if (start == tmp->start)
		{
			if (tmp->flag == 0)
			{
				cout << "\n\n Appointment Slot is Booked!!!";
				tmp->flag = 1;
			}
			else
				cout << "\n\n Appointment Slot is not Available!!!";
		}

		tmp = tmp->next;
	}
}

void AppointmentSchedule ::cancel() // Cancel Appointment
{
	int start;

	cout << "\n\n Please enter Appointment time to Cancel: ";
	cin >> start;

	tmp = head;
 
	while (tmp != NULL)
	{
		if (start == tmp->start)
		{
			if (tmp->flag == 1)
			{
				cout << "\n\n Your Appointment Slot is Canceled!!!";
				tmp->flag = 0;
			}
			else
				cout << "\n\n Your Appointment was not Booked!!!";
		}

		tmp = tmp->next;
	}
}

void AppointmentSchedule ::sortAppointments() // Sort Appointments
{
	int i, j, val;
	for (i = 0; i < sz - 1; i++)
	{
		tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->start > tmp->next->start)
			{
				val = tmp->start;
				tmp->start = tmp->next->start;
				tmp->next->start = val;

				val = tmp->end;
				tmp->end = tmp->next->end;
				tmp->next->end = val;

				val = tmp->min;
				tmp->min = tmp->next->min;
				tmp->next->min = val;

				val = tmp->max;
				tmp->max = tmp->next->max;
				tmp->next->max = val;
			}
			tmp = tmp->next;
		}
	}

	cout << "\n\n The Appointments got Sorted!!!";
}

int main()
{
	int ch;
	char ans;
	bool menu = 1;
	while (ans != 'n')
	{
		cout << "\n\n MENU";
		cout << "\n 1. Create Appointment Schedule";
		cout << "\n 2. Display Free Slots";
		cout << "\n 3. Book an Appointment";
		cout << "\n 4. Cancel an Appointment";
		cout << "\n 5. Sort slots based on Time";

		cout << "\n\n Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			obj.create();
			break;

		case 2:
			obj.display();
			break;

		case 3:
			obj.bookAppointment();
			break;

		case 4:
			obj.cancel();
			break;

		case 5:
			obj.sortAppointments();
			break;

		default:
			cout << "\n Wrong choice!!!";
		}

		cout << "\n\n Do you want to continue? (y/n) : ";
		cin >> ans;
	}
	cout << "\n\nTHANK YOU!!!";
}
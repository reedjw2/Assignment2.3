// Assignment2While.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Ticket
{
private:
	string issueStatus;
	char issueType;
	char issuePriority[25];
	char callerName[100];
	char description[1000];
	int numberUsers;
	unsigned int id;
	static unsigned int id_counter;
public:
	Ticket()
	{
		id = id_counter;
		id_counter++;
		issueStatus = "Open";
	};
	void ShowTicket();
	void CaptureTicket();
	void CloseTicket();
};
unsigned int Ticket::id_counter = 1; //must be initialized outside class

/*Ticket::Ticket()
{
	issueStatus = true;
}*/

void Ticket::CloseTicket()
{
	issueStatus = "Closed";
	cout << "Ticket number" << " " <<  id << " " << "is" << " " << issueStatus << endl;
}
void Ticket::ShowTicket()
{
	cout << "Issue id: " << id << "   ";
	switch (issueType)
	{
	case 'S':
	case 's':
		cout << "Type: Server \n";
		break;
	case 'A':
	case 'a':
		cout << "Type: Application \n";
		break;
	case 'C':
	case 'c':
		cout << "Type: Access \n";
		break;
	default:
		cout << "Not Valid Input. Try Again.";
		break;
	}
	cout << "Status:" << issueStatus << endl;
	cout << "Description: " << description << endl;
	cout << "User: " << callerName << endl;
	cout << "Users Impacted:" << numberUsers << endl;
	if (numberUsers < 10)
		cout << "Priority: LOW \n";
	if (numberUsers >= 10 && numberUsers < 50)
	{
		cout << "Priority: MEDIUM \n";
	}
	if (numberUsers > 50)
	{
		cout << "Priority: HIGH \n";
	}
	cout << "---------------------------------------" << endl;
}

void Ticket::CaptureTicket()
{
	std :: cin.clear();
	cin.ignore();
	cout << "What is the name of the caller?" << endl;
	gets_s(callerName);
	cout << "Issue Type? S=Server, A=Application, C=aCcess" << endl;
	cin >> issueType;
		switch (issueType)
	{
	default: cout << "Not Valid Input. Try Again." << endl;
		cout << "Issue Type? S=Server, A=Application, C=aCcess" << endl;
		cin >> issueType;
	case 's':
	case 'S':
	case 'a':
	case 'A':
	case 'c':
	case 'C': break;
	}
	cin.ignore();
	cout << "Description of issue?" << endl;
	gets_s(description);
	cout << "How many users impacted?" << endl;
	cin >> numberUsers;
	cin.clear();
	cin.ignore();
	cout << "Your issue id  is " << id << endl;
	
}

int main()
{
	const int maxTickets = 100;
	bool newticket = true;
	char choice;
	Ticket myTicket[maxTickets];
	int numTickets = 0;
	bool notDone = true;
	while (notDone)
	{
		cout << "Enter in new ticket? Press Y to continue." << endl;
		cin >> choice;
		switch (choice)
		{
		case 'Y':
		case 'y':
			myTicket[numTickets].CaptureTicket();
			++numTickets;
			break;
		case 'N':
		case 'n':
			notDone = false;
			break;
		default:
			cout << "I'm sorry try again" << endl
				;
			break;
		}
	}
	cout << "---------------------------------------" << endl;
	cout << "Ticket Listing" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < numTickets; ++i)
	{
		myTicket[i].ShowTicket();
	}
	myTicket[0].CloseTicket();
	return 0;
}
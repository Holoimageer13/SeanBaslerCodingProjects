#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer
{
	public:
		int timeArrive;//time of arrival;
		string name;//name of customer
		int numTickets;//number of tickets to pay
		int timeLeft;
		
		int theWait;
		
		void Create(int timeA, string Name, int Tickets);
		void Wait(int cWait);
};

void Customer::Create(int timeA, string Name, int Tickets)
{
	timeArrive = timeA;
	name = Name;
	numTickets = Tickets;
	timeLeft = numTickets * 4;
	theWait = 0;
}

void Customer::Wait(int cWait)
{
	theWait = cWait;
}


/*
//only tells who is leaving
std::ostream& operator<< (std::ostream& out, const Customer& Going)
{
   out<<"At time "<<Going.timeLeave<<" "<<Going.name<<" is done."<<endl;
  return out;
}
*/
#endif

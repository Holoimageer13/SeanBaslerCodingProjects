//Name: Sean Basler  Section: B
#include <iostream>
#include <string>
#include "linkedqueue.h"
#include "Customer.h"

using namespace std;

int main()
{
	
	int numCustomers;
	int globalTime = 0;
	int Arrive;//time customer arrives
	int Tickets;//tickets to process
	string Name;//name of customers
	int timeDoneA = 0;//when they are done
	int timeDoneB = 0;
	int lastDoneA = 0;//person in line before them and when they finished
	int lastDoneB = 0;
	int timeInLine = 0;//time in each line
	int maxWait = 0;
	int minWait;
	bool itemDequed = false;
	bool firstA = true, firstB = true;//tells if the person is at the front of the line
	Customer LongestWait;
	Customer ShortestWait;
	
	LinkedQueue<Customer> A;
	LinkedQueue<Customer> B;

	cin>>numCustomers;//number of Customers to process
	Customer* person = new Customer[numCustomers];
	
	
	for(int i = 0; i < numCustomers; i++)	
	{
		cin>>Arrive>>Name>>Tickets;	
		person[i].Create(Arrive, Name, Tickets);	
	}
	
	do
	{
		try
		{
			globalTime++;
			for(int k = 0; k < numCustomers; k++)
			{
				if(person[k].timeArrive == globalTime)
				{
					if(A.QueueLength() <= B.QueueLength())
					{
						A.enqueue(person[k]);
						cout<<"At time "<<globalTime;
						cout<<" "<<person[k].name;
						cout<<" joins line A."<<endl;
					}
					else
					{
						B.enqueue(person[k]);
						cout<<"At time "<<globalTime;
						cout<<" "<<person[k].name;
						cout<<" joins line B."<<endl;
					}
				}
			}
				
			if(!A.isEmpty())
			{
				if(firstA)
					timeDoneA = (A.front().timeLeft) + lastDoneA + A.front().timeArrive;
				else
					timeDoneA = (A.front().timeLeft) + lastDoneA;
				
				if(timeDoneA == globalTime)
				{
					cout<<"At time "<<globalTime<<" ";
					cout<<(A.front()).name<<" is done!";
					cout<<endl;//output message
					
					firstA = false;
					
					timeInLine = timeDoneA - (A.front().timeArrive);
					lastDoneA = timeDoneA;
					
					if(timeInLine > maxWait)
					{
						maxWait = timeInLine;
						LongestWait.Create((A.front()).timeArrive, 
							(A.front()).name, (A.front()).numTickets);
						LongestWait.Wait(timeInLine);
					}
					
					if(timeInLine < minWait)
					{
						minWait = timeInLine;
						ShortestWait.Create((A.front()).timeArrive, 
							(A.front()).name, (A.front()).numTickets);
						ShortestWait.Wait(timeInLine);
					}
					
					if(!itemDequed)
						minWait = timeInLine;
					
					A.dequeue();
					itemDequed = true;
					
					if(A.isEmpty())
					{
						firstA = true;
						lastDoneA = 0;
					}
				}
			}
			
			if(!B.isEmpty())
			{
				if(firstB)
					timeDoneB = B.front().timeArrive+(B.front().timeLeft) + lastDoneB;
				else
					timeDoneB = (B.front().timeLeft) + lastDoneB;
				
				if(timeDoneB == globalTime)
				{
					cout<<"At time "<<globalTime<<" ";
					cout<<(B.front()).name<<" is done!";
					cout<<endl;//output message
					
					firstB = false;
					
					timeInLine = timeDoneB - (B.front().timeArrive);
					lastDoneB = timeDoneB; 
					
					if(timeInLine > maxWait)
					{
						maxWait = timeInLine;
						LongestWait.Create((B.front()).timeArrive, 
							(B.front()).name, (B.front()).numTickets);
						LongestWait.Wait(timeInLine);
					}
					
					if(timeInLine < minWait)
					{
						minWait = timeInLine;
						ShortestWait.Create((B.front()).timeArrive, 
							(B.front()).name, (B.front()).numTickets);
						ShortestWait.Wait(timeInLine);
					}
					
					if(!itemDequed)
						minWait = timeInLine;
					
					B.dequeue();
					itemDequed = true;
					
					if(B.isEmpty())
					{
						firstB = true;
						lastDoneB = 0;
					}
				}
			}
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	} while(!A.isEmpty() || !B.isEmpty());
	
	cout<<"Longest wait: "<<LongestWait.name<<", ";
	cout<<LongestWait.theWait<<" mins."<<endl;
	cout<<"Shortest wait: "<<ShortestWait.name<<", ";
	cout<<ShortestWait.theWait<<" mins."<<endl;
	
	delete [] person;

	return 0;
}

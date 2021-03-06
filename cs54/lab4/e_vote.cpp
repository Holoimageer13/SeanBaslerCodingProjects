//File: e_vote
//Programmer: Sean Basler   Class Section: c
//Purpose: To caste an individuals vote for an election

#include <iostream>
 using namespace std;
 
int main()
{
  //Declarations
  bool more_votes;//checks if the loop needs to be repeated
  char vote;//Casts persons vote
  float perIron, perSilver, perIam;//used for percent calc.
  int numIron = 0, numSilver = 0, numIam = 0, totVote = 1;//counters and total
  
  //Greeting and Selection
  cout<<"Welcome to E-Voting system."<<endl<<endl;
  cout<<"Here are the canidates: "<<endl;
  cout<<"A: Iron Man"<<endl;
  cout<<"B: Silver Man"<<endl;
  cout<<"C: I am the Man"<<endl<<endl;
  
  //Voting and Counting
  do
  {
    cout<<"Who do you vote for? ";//prompt
    cin>>vote;
    cout<<endl;
    cout<<"You voted for ";
    //adds to votes for person selected with the counters
    if (vote == 'A')
    {
      cout<<"Iron Man."<<endl<<endl;
      numIron++;  
    }
    else if (vote == 'B')
    {
      cout<<"Silver Man."<<endl<<endl;
      numSilver++;
    }
    else if (vote == 'C')
    {
      cout<<"I am the Man."<<endl<<endl;
      numIam++; 
    }
    else
    {
      cout<<"You did not enter a valid vote."<<endl<<endl;
    }
    cout<<"Do you have more votes? (0 - No, 1 - Yes) : ";
    cin>>more_votes;
    cout<<endl;
  } while(more_votes == 1);//checks to see if it is repeated
  
  //Calculation for percents
  totVote = numIron+numSilver+numIam;
  perIron = static_cast <float>(numIron)/totVote;
  perSilver = static_cast <float>(numSilver)/totVote;
  perIam = static_cast <float>(numIam)/totVote;
  
  //Summary
  cout<<"Here is the voting summary:"<<endl;
  cout<<"Canidates        Votes      Percentage"<<endl;
  cout<<"Iron Man         "<<numIron<<"            "<<perIron<<endl;
  cout<<"Silver Man       "<<numSilver<<"            "<<perSilver<<endl;
  cout<<"I am the Man     "<<numIam<<"            "<<perIam<<endl;
  cout<<"Thanks for using the E-Voting system."<<endl;
  cout<<"Have a Nice Day!"<<endl;
  return 0;  
}  

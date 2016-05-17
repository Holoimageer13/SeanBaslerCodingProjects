//File: sci_proj.cpp
//Programmer: Sean Basler   Class: cs53   Section: b
//Description: This program will predict Ralph's science project grades
#include <iostream>
using namespace std;

int main()
{
  //Declares Constants
  const int RALPH_EATS = 4;//fraction of garbage Ralph eats
  const float GLUE_WEIGHT = 0.5, PUKE_WEIGHT = 1.0;//constant weights
  const float BE_QUIET = 3.0;//pity incrementor
  const float GET_A = 5.0, GET_B = 4.0;//grade comparison
  const float GET_C = 3.0, GET_D = 2.0, BART_PRICE = 2.00;//grade comparison
  
  //Declares Variables
  float trash_weight, money_amt, final_weight;//input weights
  char hunger, glowing_item, has_glue, cry = 'n', repeat;//choices  
  //Greeting
  cout<<"Hello Ralph, time to predict your science project's grade."<<endl;  
  //Loop that runs program
  do
  {
    //Checks for amount of trash
    cout<<"First of all, how many pounds of trash do you have?: ";
    cin>>trash_weight;
    cout<<endl;
    //Makes sure it is a valid answer
    while (trash_weight < 0)
    {
      cout<<"Invalid input, enter how many pounds of trash you have: ";
      cin>>trash_weight;
      cout<<endl;
    }
    //Checks for amount of money
    cout<<"Good, now how much money do you have?: ";
    cin>>money_amt;
    cout<<endl;
    //Makes sure that it is a valid amount
    while (money_amt < 0)
    {
      cout<<"Invalid input, enter how much money you have: ";
      cin>>money_amt;
      cout<<endl;
    }
    //Checks if Ralph has anything
    if (trash_weight == 0 && money_amt == 0)
    {
      final_weight = 1.0;
      has_glue = 'n';
      glowing_item = 'n';
      cout<<"You have nothing for Miss Hoover, do you plan to cry?(y/n): ";
      cin>>cry;
      while (cry != 'y' && cry != 'n')
      {
        cout<<"That is an invalid answer.";
        cout<<" Please enter if you plan to cry?(y/n): ";
        cin>>cry;
      }
      if (cry == 'y')
      {
        final_weight = final_weight*BE_QUIET;
      }
      
    }
    else
    {                                                                                               
      //Checks for hunger 
      cout<<"That's great! Now be honest Ralph, are you hungry(y/n): ";
      cin>>hunger;
      cout<<endl;
      //Makes sure it is y or n response
      while(hunger != 'y' && hunger != 'n')
      {
        cout<<"Invalid input, enter if you are hungry?(y/n): ";
        cin>>hunger;
        cout<<endl;
      }
      //Checks glue possession
      cout<<"Okay, Now do you have some glue?(y/n): ";
      cin>>has_glue;
      cout<<endl;
      //Checks for good input
      while(has_glue != 'y' && has_glue != 'n')
      {
        cout<<"Invalid input, enter if you have glue?(y/n): ";
        cin>>has_glue;
        cout<<endl;
      }
      //Checks glowing item possession
      cout<<"Fantastic! Finally, did you collect a glowing item?(y/n): ";
      cin>>glowing_item;
      cout<<endl;
      //Checks for y or n
      while(glowing_item != 'y' && glowing_item != 'n')
      {
        cout<<"Invalid input, enter if you have a glowing item?(y/n): ";
        cin>>glowing_item;
        cout<<endl;
      }
    }
    
    //Calculates final_weight
    if (cry != 'y' && final_weight != 1.0)
    {
      final_weight = trash_weight+(static_cast<int>(money_amt/BART_PRICE));
    }
    if (hunger == 'y' && has_glue == 'y')
    {
      //Applys the correct calculation for if he has a glowing item or not
      if (glowing_item =='y')
      {
        final_weight = (final_weight-(2*(final_weight/(RALPH_EATS))))+PUKE_WEIGHT; 
      }
      else
      {
        final_weight = final_weight-(final_weight/RALPH_EATS);
      }
    }
    //Creates weight for if he's not hungry
    else if (hunger == 'n' && has_glue == 'y')
    {
      final_weight = final_weight + GLUE_WEIGHT; 
    }
    //Calculates grade based on final weight
    cout<<"Final Weight: "<<final_weight<<endl;
    cout<<"You will recieve ";
    if (final_weight >= GET_A)
    {
      cout<<"an A."<<endl;
    }
    else if (GET_B <= final_weight && final_weight < GET_A)
    {
      cout<<"a B."<<endl;
    }
    else if (GET_C <= final_weight && final_weight < GET_B)
    {
      cout<<"a C."<<endl;
    }
    else if (GET_D <= final_weight && final_weight < GET_C)
    {
      cout<<"a D."<<endl;
    }
    else if (final_weight < GET_D)
    {
      cout<<"a F."<<endl;
    }
    cout<<"For your science project."<<endl<<endl;
    //prompts to see if you would like to repeat the process
    cout<<"Would you like to repeat the grading process, Ralph?(y/n): ";
    cin>>repeat;
    cout<<endl;                                                                      
  } while (repeat != 'n');
  return 0;//ends program
}  

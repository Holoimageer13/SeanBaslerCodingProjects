//Programmer: Sean Basler   Section: b
//File: goBanana.cpp
//Purpose: to take the names and weights of two fruit and
//         see which is heavier.
#include <iostream>
using namespace std;

//Global Constant Declarations
const int MAX_WEIGHT = 2000;

//Description: Greets the user
//Pre        : None
//Post       : Outputs a greeting
void greet();

//Description: Bids farewell to the user
//Pre        : None
//Post       : Outputs a farewell message.
void bye();

//Description: Asks the user if he wants to repeat the entire process
//Pre        : None
//Post       : A character is returned
char repeat();

//Description: makes sure user input a positive number and under 2000 lbs
//Pre        : None 
//Post       : returns valid user input
float isFruit(float weightNum);

//Description: Prompts for the names and weight of both of the fruit
//Pre        : None
//Post       : returns the first fruit's name and weight
void usersFruits(string & fruit1, float & weight1, 
                 string & fruit2, float & weight2); 

//Description: Tells the user which fruit is larger
//Pre        : weight parameters must be positive
//Post       : Outputs which fruit to root for
void compareFruit(const string fruit1, const float weight1,
                  const string fruit2, const float weight2);

int main()
{
  //local variable declarations
  float theFirstWeight, theSecondWeight;
  string theFirstFruit, theSecondFruit;
  char redo = 'y';
  
  greet();
  
  //loop that repeats the program
  do
  {
    //function calls
    usersFruits(theFirstFruit, theFirstWeight,
                theSecondFruit, theSecondWeight);
    compareFruit(theFirstFruit, theFirstWeight,
                 theSecondFruit, theSecondWeight);
    redo = repeat();
  } while (redo == 'y');
  bye();
  return 0;
}

void greet()
{
  cout<<"Welcome to the Fruit Root System."<<endl;
  cout<<"Time to find out who you're rooting for."<<endl<<endl;
  return;
}

void bye()
{
  cout<<"Thank you for using the Fruit Rooting System."<<endl;
  cout<<"Have a nice day!"<<endl;
  return;
}

char repeat()
{
  char again;//local variable
  
  //prompt
  cout<<"Do you wish to compare more fruit?(y/n): ";
  cin>>again;
  cout<<endl;
  return again;
}

float isFruit( float weightNum)
{ 
  cout<<endl;
  while (weightNum <= 0 || weightNum > MAX_WEIGHT )
  {
    cout<<"Incorrect Input, the weight must be positive ";
    cout<<"and under 2000 lbs."<<endl;
    cout<<"Please input a positive weight (in lbs): ";
    cin>>weightNum;
    cout<<endl;
  }
  return weightNum;
}

void usersFruits(string & fruit1, float & weight1,
                 string & fruit2, float & weight2)
{
  //declare local variables
  string the1Fruit, the2Fruit;
  float the1Weight, the2Weight;
  
  //Prompt statements for first fruit
  cout<<"What is the name of your first fruit?: ";
  cin>>the1Fruit;
  cout<<"What is the weight of your first fruit?(in lbs): ";
  cin>>the1Weight;
  the1Weight = isFruit(the1Weight);//makes sure it's positive
  cout<<endl;
  
  //Prompt statements for second fruit
  cout<<"What is the name of your second fruit?: ";
  cin>>the2Fruit;
  cout<<"What is the weight of your second fruit?(in lbs): ";
  cin>>the2Weight;
  the2Weight = isFruit(the2Weight); 
  
  //sets variables to desired value
  fruit1 = the1Fruit;
  weight1 = the1Weight;   
  fruit2 = the2Fruit;
  weight2 = the2Weight;
  return;
}

void compareFruit(const string fruit1, const float weight1,
                  const string fruit2, const float weight2)
{
  if (weight1 < weight2)
  {  
    cout<<"The "<<fruit2<<" will win."<<endl;
    cout<<"GO "<<fruit2<<"!"<<endl;
  }
  else if (weight1 > weight2)
  {
    cout<<"The "<<fruit1<<" will win."<<endl;  
    cout<<"GO "<<fruit1<<"!"<<endl;
  }
  else
    cout<<"The fruit have equal chances of winning."<<endl;
  cout<<endl;
  return;
}                      

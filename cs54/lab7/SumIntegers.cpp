//Programmer: Sean Basler    Section: c
//File: SumIntegers.cpp
//Purpose: This Program finds the sum of all the integers between two
//         given values.

#include <iostream>
using namespace std;

//Description: Greets the user
//        Pre: None
//       Post: Outputs a greeting to the user
void hello();

//Description: Prompts user for two numbers and validates the inputs
//        Pre: None
//       Post: Returns two positive integers where the first is less than
//             the second
void numReader(int & lowLim, int & highLim);

//Description: Finds the the sum of the integers in between the limits
//        Pre: Must take in two positive integers
//       Post: Returns the sum of the integers in between the limits
int sumIntegers(int const lowerLim, int const higherLim);

//Description: Tells the user the results
//        Pre: Must take a positive integer
//       Post: Outputs the result of the sum
void result(int const smallLim, int const bigLim, int const theSum);

//Description: Says goodbye to the user
//        Pre: None
//       Post: Outputs farewell message
void bye();

int main()
{
  //Declares local variables
  int finalSum, firstLim, lastLim;

  //Function calls
  hello();
  numReader(firstLim, lastLim);
  finalSum = sumIntegers(firstLim, lastLim);
  result(firstLim, lastLim, finalSum);
  bye();
  
  //Ends program 
  return 0;
} 

void hello()
{
  cout<<"Welcome!"<<endl;
  cout<<"Today's program will find the sum of all integers within the ";
  cout<<"given range."<<endl<<endl;
  return;
}

void numReader(int & lowLim, int & highLim)
{
  //This loop makes sure lower limit is positive
  do
  { 
    cout<<"Enter the lower limit (>0): ";
    cin>>lowLim;
  } while(lowLim < 1 );
  cout<<endl;
  
  //This loop makes sure upper limit is greater than the lower limit
  do
  {
    cout<<"Enter the upper limit (>"<<lowLim<<"): ";
    cin>>highLim;
  } while(highLim <= lowLim); 
  cout<<endl<<endl; 

  //Returns to calling function
  return;
}

int sumIntegers(const int lowerLim, const int higherLim)
{
  //Declares local variables
  int ourSum = 0;
  
  //Computes the sum
  for (int i = lowerLim; i <= higherLim; i++)
  {
    ourSum = ourSum + i;  
  }
  
  //Returns the value to the calling function
  return ourSum;
}

void result(int const smallLim, int const bigLim, int const theSum)
{
  cout<<"The lower limit was: "<<smallLim<<endl;
  cout<<"The upper limit was: "<<bigLim<<endl;
  cout<<"The sum of integers between "<<smallLim<<" and "<<bigLim;
  cout<<" is: "<<theSum<<"."<<endl;
  return;
}

void bye()
{
  cout<<"Thanks for using the intger sum program."<<endl;
  cout<<"Have a great day!"<<endl;
  return;
}

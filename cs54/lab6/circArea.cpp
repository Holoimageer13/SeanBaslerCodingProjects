//File: circArea.cpp
//Programmer: Sean Basler   Section: c
//Purpose: this program gives the user the area of a circle given an input.
#include <iostream>
using namespace std;

//Description: Greeting message is output to the screen
//Pre        : None
//Post       : Greeting message is output to the screen
void greet();

//Description: Read a user input for radius and make sure it is
//             positive. If it is negative, it will keep asking until 
//             a positive number is entered 
//Pre        : None
//Post       : A non negative radius is returned
float readRadius();

//Description: Calculate and return the area of the circle 
//Pre        : the parameter radius must be positive
//Post       : Area of the circle is returned
float findArea(float radius);

//Description: The radius and area are output on the screen
//Pre        : None
//Post       : The radius and area are output on the screen
void printResult(float radius, float area);

//Description: The radius and area are output on the screen
//Pre        : None
//Post       : The radius and area are output on the screen
void signoff();

int main()
{
  float circRad, finalArea;//local variables for radius and area
  
  greet();
  circRad = readRadius();
  finalArea = findArea(circRad);
  printResult(circRad, finalArea);
  signoff();
  return 0;
}

void greet()
{
  cout<<"Welcome to the Area Calculator."<<endl;
  return;
}

float readRadius()
{
  float firstRad;//local variable for initial radius
  cout<<"Please enter the radius of the circle: ";
  cin>>firstRad;
  cout<<endl;
  
  //checks to make sure it is positive
  while (firstRad <= 0)
  {
    cout<<"That is an invalid radius, please enter a positive radius: ";
    cin>>firstRad;
  }
  cout<<endl;
  return firstRad;
}

float findArea(float radius)
{
  const float PI = 3.1415926;//delares math constant
  float theArea;//local variable for area
  
  theArea = PI*radius*radius;//calculates area
  
  return theArea; 
}

void printResult(float radius, float area)
{
  cout<<"You entered the radius: "<<radius<<endl;
  cout<<"The area of the circle: "<<area;
  cout<<endl;
  return;
}

void signoff()
{
  cout<<endl;
  cout<<"Have a Good Day!"<<endl;
  return;
}

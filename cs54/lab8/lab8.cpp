//Programmer: Sean Basler    Section: C
//File: lab8Main.cpp
//Description: This program prompts the user for a random shapes information
//             in order to determine the shape's perimeter
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lab8.h"
using namespace std;

int main()
{
  //Randomizes the number
  srand(time(NULL));
  
  //Declares local variables
  float perim;
  float radius;
  float length1, length2, length3;
  int shape;
  
  greeting();
  shape = generateRandomNum();
  switch (shape)
  {
    case CIRCLE:
    {
      cout<<"Input the circle"<<endl;
      radius = readInput();
      perim = findPerimeter(radius); 
      break;   
    }
    case RECTANGLE:
    {
      cout << "Input the rectangle " << endl;
      length1= readInput();
      length2 = readInput();
      perim = findPerimeter(length1, length2);
      break;
    }
    case TRIANGLE:
    {
      cout<<"Input the triangle"<<endl;
      length1 = readInput();
      length2 = readInput();
      length3 = readInput();
      perim = findPerimeter(length1, length2, length3);      
      break;
    }
    default:
      cout<<"Invalid option"<<endl;
  }
  printResult(shape, perim);
  signoff();
  
  return 0;
}

//-----------------------------------------------------------------------
// Programmer: Sean Basler           Student ID: 12366509 
// Lab: 13, "Overloading"            Filename: Lab13.cpp
// Due Date: 04/22/14                Class: CSc54, Section C
//------------------------------------------------------------------------
#include <iostream>
using namespace std;

//The class functions in the order they appear in the class
//Desc: Constructs a rectangle with default length and width of one
// Pre: none
//Post: Creates the rectangle object with default lengths
//Desc: Constructs a rectangle with a given length and width
// Pre: Must be passed positive non-zero  numbers
//Post: Creates a rectangle with the given lengths
//Desc: Sets the length of the rectangle
// Pre: Must be passed a positive non-zero number
//Post: Sets the length
//Desc: Sets the width of the rectangle
// Pre: Must be passed a positive non-zero number
//Post: Sets the width
//Desc: Tests to see if the given rectangle is a square
// Pre: none
//Post: Returns whether or not the rectangle is a square
//Desc: Redefines the addition operator to add rectangles
// Pre: none
//Post: Adds two rectangles
//Desc: converts rectangle to a square using the average of its sides 
// Pre: none
//Post: the not operator will now convert rectangles to squares
//Desc: defines what will happen when you output a rectangle
// Pre: none
//Post: outputs a rectangle
class Rectangle
{
  private:
    int length;
    int width;
  
  public:
    Rectangle(): length(1), width(1) { }
    Rectangle(int rect_length, int rect_width);
    void setLength(int rect_length);
    void setWidth(int rect_width);
    bool isSquare();
    
    Rectangle operator +(const Rectangle& other);
    void operator !();
    friend ostream & operator << (ostream & stream, const Rectangle & value);
};

int main()
{
  //Declares the rectangles
  Rectangle rect1, rect2, rect3(4, 2), rect4(4, 3);
  
  //greetings 
  cout<<"Welcom to Rectangle lesson"<<endl<<endl;
  
  //rectangle one
  cout<<"d1: "<<rect1<<endl;
  
  //rectangle two
  cout<<"d2: "<<rect2;
  rect2.setLength(8);
  rect2.setWidth(5);
  cout<<"d2: after setting width and length ";
  cout<<rect2<<endl;
  
  //rectangle three
  cout<<"d3: "<<rect3;
  if(rect3.isSquare())
    cout<<"d3 is a square"<<endl;
  else
    cout<<"d3 is not a square"<<endl;
  cout<<"!d3 is ";
  !rect3;
  cout<<rect3;
  if(rect3.isSquare())
    cout<<"d3 is a square"<<endl;
  else
    cout<<"d3 is not a square"<<endl;
  cout<<endl;
  
  //rectangle four
  cout<<"d4: "<<rect4;
  cout<<"d4 + d2 "<<rect4 + rect2;
  
  //end
  cout<<"Thanks for your participation"<<endl;
  return 0;
}

Rectangle::Rectangle(int rect_length, int rect_width)
{
  setLength(rect_length);
  setWidth(rect_width);
}

void Rectangle::setLength(int rect_length)
{
  if(rect_length > 0)
    length = rect_length;
  else 
    cout<<"Error, invalid entry.";
  return;
}

void Rectangle::setWidth(int rect_width)
{
  if(rect_width > 0)
    width = rect_width;
  else
    cout<<"Error, invalid entry.";
  return;
}

bool Rectangle::isSquare()
{
  return (length == width);
}

Rectangle Rectangle::operator +(const Rectangle& other)
{
  //Declares local variables
  int newLength, newWidth;
  
  //calculations
  newLength = length + other.length;
  newWidth = width + other.width;
  
  //Declares new rectangle
  Rectangle newRect(newLength, newWidth);
  
  return newRect; 
}

void Rectangle::operator !()
{
  //local constants
  const int NUMDIM = 2;//number of dimensions in a rectangle
  
  //Declares local variables
  int average;
  
  //calculations
  average = (length + width)/NUMDIM;
  
  //converts the rectangle into a square
  length = average;
  width = average;
  
  return;
}

ostream& operator <<(ostream & stream, const Rectangle & value)
{
  stream<<"( "<<value.width<<" "<<value.length<<" )"<<endl;
  return stream;
}

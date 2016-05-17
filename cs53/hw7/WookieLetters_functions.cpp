//Programmer: Sean Basler    Section: b
//File: WookieLetters_functions.cpp
//Description: This defines the functions used in the WookieLetters program
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "WookieLetters.h"
using namespace std;

void greeting()
{
  cout<<"Welcome to Ralph's Wookie and Letter Sorting System.";
  cout<<endl<<endl;
}

void signoff()
{
  cout<<"Thank you for using Ralph's Wookie and Letter Sorting System.";
  cout<<endl;
  cout<<"Have A Great Day!";
  cout<<endl;
}
ostream& operator <<(ostream & os, const Wookie & w)
{
  os<<w.m_name<<" weighs "<<w.m_weight<<" oz and is ";
  os<<w.m_height<<" inches tall (total ";
  os<<(w.m_height+w.m_weight)<<").";
  return os;
}
        
bool operator <(const Wookie & wook1, const Wookie &  wook2)
{
  float wookSum1, wookSum2;
  wookSum1 = wook1.m_weight + wook1.m_height;
  wookSum2 = wook2.m_weight + wook2.m_height;
  return (wookSum1 < wookSum2);
}
                 
void init_array(Wookie wookArr[])
{
  //Declares local variables
  float randNum;
  
  //Loop that counts the wookies
  for (int i = 0; i < WOOKIE_MAX; i++)
  {
    //Constant declaraitons
    const int UP_WT = 78 , LOW_WT = 12;//Wookie Weight restrictions
    const int UP_HT = 34 , LOW_HT = 10;//Wookie Hegiht restricitons
  
    //Prompts for wookie's name
    cout<<"Please enter a Wookie name: ";
    cin>>wookArr[i].m_name;
  
    //Creates a random weight in desired range
    randNum = LOW_WT + static_cast<float>(rand())
              /(static_cast<float>(RAND_MAX/(UP_WT-LOW_WT)));
    wookArr[i].m_weight = randNum;
  
    //Creates a random height in desired range
    randNum = LOW_HT + static_cast<float>(rand())
              /(static_cast<float>(RAND_MAX/(UP_HT-LOW_HT)));
    wookArr[i].m_height = randNum;
  }
  return;
}

void init_array(char letterArr[])
{
  //Constant declarations
  const int UP_LT = 90 , LOW_LT = 65;//Character restricitons
  
  //Declares local variables
  float randNum;
  
  //Loop that counts the letters
  for (int i = 0; i < LETTER_MAX; i++)
  {
    //Creates a random letter in the desired range
    randNum = LOW_LT + static_cast<float>(rand())
              /(static_cast<float>(RAND_MAX/(UP_LT-LOW_LT)));
    letterArr[i] = randNum;
  }
  return;
}

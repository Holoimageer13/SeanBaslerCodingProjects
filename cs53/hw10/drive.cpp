//Programmer: Adam Bowers and Sean Basler  Date: 04/16/2014
//File: drive.cpp		           Class: CS53 b
//Purpose: This is the driver for a program that has two classes a student and
//         a schoolmate class. Without any user input it generates and outputs
//         the values for an object of each class
#include "structs.h"
#include "classmate.h"
#include "schoolyard.h"
using namespace std;
int main()
{
  srand(time(NULL));
  cout<<"Hello welcome to the school yard\n";
  schoolyard school(YARMAX,YARMIN);
  classmate stu1("Ralph"), stu2("Possum");
  stu1.go_to_school(school);
  stu2.go_to_school(school);
  cout<<school<<endl;
  int num_mvs = 0;
  while(!stu1.isdone()||!stu2.isdone())
  {
    //move each unit till they get score
    if(!stu1.isdone())
      stu1.move(school);
    if(!stu2.isdone())
      stu2.move(school);
    cout<<school;
    num_mvs++;
    usleep(90000);//if you want it to go slower uncomment this
  }
  cout<<school<<endl;
  if(stu1.getscore()>=stu2.getscore())
  {
    cout<<stu1<<" and they have won!"<<endl;
    cout<<" His score is "<<stu1.getscore()<<endl;
    cout<<"It took "<<num_mvs<<" turns to finish"<<endl;
  }
  else
  {
    cout<<stu2<<" and they have won! "<<endl;
    cout<<" His score is "<<stu2.getscore()<<endl;
    cout<<"It took "<<num_mvs<<" turns to finish"<<endl;
  }
  cout<<"Thanks have a nice day"<<endl;
  return 0;
}

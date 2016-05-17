//Programmer: Adam Bowers		Date: 04/16/2014
//File: drive.cpp				Class: CS53 b
//Purpose: This is the driver for a program that has two classes a student and
//			a schoolmate class. Without any user input it generates and outputs
//			the values for an object of each class
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
  {//move each unit till they get score
	if(!stu1.isdone())
	  stu1.move(school);
	  cout<<school;
	if(!stu2.isdone())
	  stu2.move(school);
	if(!stu1.isdone())
	cout<<"moved"<<endl;
	if(num_mvs<10)
	  cout<<school;
	num_mvs++;
  }
  cout<<school<<endl;
  if(stu1.getscore()>=stu2.getscore())
  {
	cout<<"The student "<<stu1<<" has won!"<<endl;
	cout<<"It took "<<num_mvs<<" turns to finish"<<endl;
  }
  else
  {
	cout<<"The student "<<stu2<<" has won!"<<endl;
	cout<<"It took "<<num_mvs<<"to finish"<<endl;
  }
  cout<<"Thanks have a nice day"<<endl;
  return 0;
}

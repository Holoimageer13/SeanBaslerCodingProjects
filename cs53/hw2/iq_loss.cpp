// Programmer: Sean Basler   Student ID: 12366509   date: 02/03/14
// Homework 2: "IQ Loss"     Filename: iq_loss.cpp
// Due Date: 02/07/14        Class: CSc53, Section B
// Purpose: To find iq loss from paste and crayons

# include <iostream>
  using namespace std;
  
  int main()
  {
    /*Declaration Section*/
    short age, iq, crayon_amount, loss;//declares short integer variables
    float paste_amount;
    const int GLUE_POTENCY = 20, SMART = 150;//declares glue gonstant
    const float SWGF = 1.6;//declares genetic constant
    bool wig_father, genius;//declares bool that checks relation to chief Wiggum
    
    /*Prompt section*/
    cout<<"Welcome to the IQ loss program."<<endl;//intro statement
    cout<<"This will tell you the amount ";//intro statement
    cout<<"of IQ you will lose."<<endl;//intro statement
    cout<<"Please enter the following information:"<<endl<<endl;//intro prompt
    cout<<"Your age:           ";//age prompt
    cin>>age;
    cout<<endl;
    cout<<"Your current IQ:    ";//IQ prompt
    cin>>iq;
    cout<<endl;
    cout<<"Amount of paste:    ";//Paste prompt
    cin>>paste_amount;
    cout<<endl;
    cout<<"Number of crayons:  ";//Crayon prompt
    cin>>crayon_amount;
    cout<<endl;
    cout<<"Is your father the chief of police (enter 1 for yes, ";
    cout<<"0 for no):    ";// Police prompt
    cin>>wig_father;
    cout<<endl<<endl;//puts space in between sections
    
    /*Calculation Section */
    genius = (iq < SMART);//determines if the person's iq is 150 or above 
    loss = (static_cast<float>(age)/iq)*(GLUE_POTENCY*paste_amount)*genius
           +(SWGF*crayon_amount*wig_father)*genius;//calculates IQ loss
           
    /*Results Section*/
    cout<<"You will lose "<<loss<<" IQ points."<<endl<<endl;// gives results
    cout<<"Have a wonderful day!"<<endl;// goodbye
    return 0;//ends program
  }

//File: bmi_calc
//Programmer: Sean Basler    Class Section: d
//Purpose to calculate the body mass index of an individual.

#include <iostream>
 using namespace std;
 
 int main() 
 {
   /*Declarations*/
   int height, mass, req_mass;
   float bmi, des_bmi;
   const int CONVERSION = 703;
   
   /*Introduction and Initial Prompts*/
   cout<<"Welcome to BMI calculator."<<endl<<endl;//intro 
   cout<<"Enter the height and mass."<<endl<<endl;//intro
   cout<<"Height (inches) :  ";//height prompt
   cin>>height;
   cout<<endl;
   cout<<"Mass (pounds)   :  ";//mass prompt
   cin>>mass;
   cout<<endl;
   
   /*BMI Calculations*/
   bmi = (static_cast<float>(mass)*CONVERSION)/(height*height);//bmi calculation
   
   /*Return Calculated Values*/
   cout<<"The BMI value for "<<height<<" inches and "<<mass<<" pounds is ";
   cout<<bmi<<"."<<endl<<endl;//output
   
   /*Secondary Prompts*/
   cout<<"Enter the BMI value you would like to obtain:  ";//desired BMI prompt
   cin>>des_bmi;
   cout<<endl;
   
   /*Desired BMI Calculations*/
   req_mass = (height*height*des_bmi)/CONVERSION;//mass calc.
   
   /*Final Output*/
   cout<<"Required mass to obtain "<<des_bmi<<" BMI value is "<<req_mass;
   cout<<" pounds."<<endl;//conclusion statement
 }

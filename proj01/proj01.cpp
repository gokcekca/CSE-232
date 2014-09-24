#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    cout << setprecision(10);
    double debt;
    double denom;
    double population;
    double miles;
    double moon;
    double each;
    double bills;
    cout << "Input the US national debt:" << endl;
    cin >> debt;
    cout << "Input the denomination of US currency:"<< endl;
    cin >> denom;
    cout << "Input the population of the United States:"<< endl;
    cin >> population;
    
    bills = debt / denom;
    miles = (bills*0.0043)/63360;
    moon = miles/238857;
    each = debt/population;
    cout << "Miles high of indicated currency: " << miles <<endl;
    cout << "Multiples of distance to the moon: "<<moon<<endl;
    cout<<"What each person owes: $"<<round(each)<<endl;
}
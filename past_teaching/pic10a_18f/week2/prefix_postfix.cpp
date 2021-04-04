/*
Practice PreFix and PostFix

Prefix operators increment the value of the variable, then return the reference to the variable. 

Postfix operators create a copy of the variable and increments the value of the variable. Then it returns a copy from BEFORE the increment.
*/

#include<iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int post = 0;
    int pre = 0;
    cout<<"Inital values: \t\t\tpost = "<<post<<" pre= "<<pre<<"\n";
    post = a++;
    pre = ++b;
    cout<<"After one postfix and prefix: \tpost = "<<post<<" pre= "<<pre<<"\n";
    post = a++;
    pre = ++b;
    cout<<"After two postfix and prefix: \tpost = "<<post<<" pre= "<<pre<<"\n";  

    cout<<"\nUsing postfix\n";
    for(int i=0; i<5; i++)
    {
        cout << i << endl;
    }

    cout<<"\nUsing prefix\n";
    for(int i=0; i<5; ++i)
    {
        cout << i << endl;
    }
    return 0;
}
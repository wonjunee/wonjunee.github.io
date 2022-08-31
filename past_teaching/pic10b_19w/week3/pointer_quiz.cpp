/*Goal: Examine pointers!*/

#include <iostream>

using namespace std;

int main()
{


    // int a,b;

    // a = 54;
    // b = a;
    // cout << "BEFORE\n";
    // cout<<"address of a is at &a = "<< &a<<" a is " << a <<"\n";
    // cout<<"address of b is at &b = "<< &b<<" b is " << b <<"\n";
    // b = 12;
    // cout << "AFTER\n";
    // cout<<"address of a is at &a = "<< &a<<" a is " << a <<"\n";
    // cout<<"address of b is at &b = "<< &b<<" b is " << b <<"\n";
    

    int a = 54;
    int * b = &a;
    a = 32;

    cout<<"a  = "<<a<<"\n";
    cout<<"*b = "<<*b<<"\n";
    cout<<"address of a is at &a = "<< &a<<"\n";
    cout<<"address of a is at b  = "<< b<<"\n";

    *b = 40;

    cout<<"a  = "<<a<<"\n";
    cout<<"*b = "<<*b<<"\n";
    cout<<"address of a is at &a = "<< &a<<"\n";
    cout<<"address of a is at b  = "<< b<<"\n";



    return 0;
}
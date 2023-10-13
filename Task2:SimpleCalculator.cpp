/*Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, anddivision. 
Allow the user to input two numbers and choose anoperation to perform.*/
#include<iostream>
using namespace std;
int main()
{
    float a,b,d;
    char c;
    cout<<"Enter first number :";
    cin>>a;
    cout<<"Enter second number:";
    cin>>b;
    cout<<"Enter your choice of operations:(+,-,*,/)";
    cin>>c;
    switch(c)
    {
        case '+':d=a+b;cout<<"The addition of two given numbers are:"<<d;
        break;
        case '-':d=a-b;cout<<"The difference of two given numbers are:"<<d;
        break;
        case '*':d=a*b;cout<<"The multiplication of two given numbers are:"<<d;
        break;
        case '/':if(b==0) cout<<"Division by zero is not defined";
                else d=a/b;cout<<"result of division of two given numbers is:"<<d;break;
        default:cout<<"Invalid choice";
    }
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    cout << "Hello, World! nikitha" << endl;
    int a,b;
    int sum=0;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    sum = a + b;
    cout << "Sum: " << sum << endl;
    if(sum%2 == 0)
        cout << "Sum is even." << endl;
    else
        cout << "Sum is odd." << endl;
    cout << "This is a simple C++ program." << endl;    
    return 0;
}
#include <iostream>
using namespace std;
class B;
class A
{
    int a;

public:
    A(int x)
    {
        a = x;
    }
    friend void largest(A a1, B b1);
    friend void smallest(A a1, B b1);
};
class B
{
    int b;

public:
    B(int y)
    {
        b = y;
    }
    friend void largest(A a1, B b1);
    friend void smallest(A a1, B b1);
};
void largest(A a1, B b1)
{
    if (a1.a > b1.b)
        cout << "The largest number is a = " << a1.a << endl;
    else
        cout << "The largest number is b = " << b1.b << endl;
}
void smallest(A a1, B b1)
{
    if (a1.a < b1.b)
        cout << "The smallest number is a = " << a1.a << endl;
    else
        cout << "The smallest number is b = " << b1.b << endl;
}
int main()
{
    int val1, val2;
    cout << "Enter the value for a: ";
    cin >> val1;
    A ax(val1);
    cout << "Enter the value for b: ";
    cin >> val2;
    B by(val2);
    cout << "\nFinding the largest and smallest between two numbers of two different classes:" << endl;
    largest(ax, by);
    smallest(ax, by);
    return 0;
}

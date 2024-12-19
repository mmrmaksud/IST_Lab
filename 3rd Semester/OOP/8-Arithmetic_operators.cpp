#include <iostream>
#include <iomanip>
using namespace std;
class Float
{
    float a;

public:
    Float()
    {
        a = 0.0;
    }
    Float(float num1);
    Float operator+(Float o);
    Float operator-(Float o);
    Float operator*(Float o);
    Float operator/(Float o);
    void display();
};
Float ::Float(float num1)
{
    a = num1;
}
Float Float ::operator+(Float o)
{
    Float c;
    c.a = a + o.a;
    return c;
}
Float Float ::operator-(Float o)
{
    Float c;
    c.a = a - o.a;
    return c;
}
Float Float ::operator*(Float o)
{
    Float c;
    c.a = a * o.a;
    return c;
}
Float Float ::operator/(Float o)
{
    Float c;
    c.a = a / o.a;
    return c;
}
void Float ::display()
{
    cout << "Result = " << a << endl;
}
int main()
{
    float f1, f2;
    cout << "Enter two floating point number: ";
    cin >> f1 >> f2;
    Float o1(f1), o2(f2), o3;
    cout << "\nAddition:" << endl;
    o3 = o1 + o2;
    o3.display();
    cout << "Subtraction:" << endl;
    o3 = o1 - o2;
    o3.display();
    cout << "Multiplication:" << endl;
    o3 = o1 * o2;
    o3.display();
    cout << "Division:" << endl;
    o3 = o1 / o2;
    o3.display();

    return 0;
}

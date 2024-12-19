#include <iostream>
using namespace std;
class Time
{
    int h, m;
    char ch;
public:
    Time()
    {
        h = m = 0;
    }
    void getData()
    {
        cout << "Enter h : m" << endl;
        cin >> h >> ch >> m;
    }
    void add(Time &t1, Time &t2);
    void display();
};
void Time::add(Time &t1, Time &t2)
{
    m = t1.m + t2.m;
    h = m / 60;
    h = h + t1.h + t2.h;
    m = m % 60;
}
void Time ::display()
{
    cout << "Hours : Minutes" << endl;
    cout << h << " : " << m << endl;
}
int main()
{
    Time a, b, c;
    a.getData();
    b.getData();
    c.add(a, b);
    c.display();

    return 0;
}

#include <iostream>
using namespace std;
class area_cl
{
public:
    double height;
    double width;
    double area();
};
class rectangle : public area_cl
{
public:
    rectangle(double h, double w)
    {
        height = h;
        width = w;
    }
    double area()
    {
        return (height * width);
    }
};
class isosceles : public area_cl
{
public:
    isosceles(double h, double w)
    {
        height = h;
        width = w;
    }
    double area()
    {
        return (0.5 * height * width);
    }
};
int main()
{
    double result;
    rectangle r1(5, 3);
    result = r1.area();
    cout << "The area of a rectangle is: " << result << endl;
    isosceles i1(5, 3);
    result = i1.area();
    cout << "The area of a isosceles triangle is: " << result << endl;
    return 0;
}

#include <iostream>
using namespace std;
void volume(int l, int w, int h)
{
    cout << "Volume of a rectangle: " << l * w * h << endl;
}
void volume(double r, int h)
{
    cout << "Volume of a cylinder: " << 3.1416 * r * r * h << endl;
}
void volume(int sl)
{
    cout << "Volume of a cube: " << sl * sl * sl << endl;
}
int main()
{
    int l, w, h, a;
    double r;
    cout << "Enter l, h & w to calculate the volume of a rectangle: ";
    cin >> l >> w >> h;
    volume(l, w, h);
    cout << "\nEnter r & h to calculate the volume of a cylinder: ";
    cin >> r >> h;
    volume(r, h);
    cout << "\nEnter a to calculate the volume of a cube: ";
    cin >> a;
    volume(a);

    return 0;
}

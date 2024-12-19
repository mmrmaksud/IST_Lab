#include <iostream>
using namespace std;
class COMPLEX
{
    int real, imaginary;

public:
    COMPLEX()
    {
        real = imaginary = 0;
    }
    COMPLEX(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    void add(COMPLEX &c1, COMPLEX &c2)
    {
        real = c1.real + c2.real;
        imaginary = c1.imaginary + c2.imaginary;
    }
    void show()
    {
        cout << "\nComplex number: ";
        cout << real << "+" << imaginary << "i";
    }
};
int main()
{
    int r, i;
    char ch;
    cout << "Enter a complex number: ";
    cin >> r >> ch >> i >> ch;
    COMPLEX ob1(r, i);
    cout << "Enter a complex number: ";
    cin >> r >> ch >> i >> ch;
    COMPLEX ob2(r, i);
    COMPLEX ob3;
    ob3.add(ob1, ob2);
    ob3.show();

    return 0;
}

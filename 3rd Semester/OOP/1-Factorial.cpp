#include <iostream>
using namespace std;
class factorial
{
private:
    int n, fact;

public:
    factorial(int number)
    {
        fact = 1;
        n = number;
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }
    }
    void display();
};
void factorial::display()
{
    cout << fact << endl;
}
int main()
{
    int number;
    cout << "Enter an integer number: ";
    cin >> number;
    factorial f1(number);
    f1.display();
    return 0;
}

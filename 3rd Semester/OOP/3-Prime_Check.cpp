#include <iostream>
using namespace std;
class prime
{
private:
    int number;

public:
    void primeCheck(int n)
    {
        number = n;
        int i, flag = 0;
        for (i = 2; i <= number / 2; i++)
        {
            if (number % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not Prime" << endl;
        }
    }
};
int main()
{
    int value;
    cout << "Enter a positive value to check prime or not: ";
    cin >> value;
    prime p;
    p.primeCheck(value);
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string ch;
    fstream fpI, fpO;
    fpI.open("read.txt", ios::in);
    fpO.open("write.txt", ios::out | ios::app);
    if (!fpO)
    {
        cout << "Error" << endl;
    }
    else
    {
        while (getline(fpI, ch))
        {
            fpO << ch;
            fpO << endl;
        }
    }
    fpI.close();
    fpO.close();

    return 0;
}

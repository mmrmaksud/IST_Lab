//3. Write a program to measure the performance using time function between bubble sort and quick sort.

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int n = 10000;
void BubbleSort(int *a, int num)
{
    int temp;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (a[j] > a[j + 1])
                int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}
int Partition(int *a, int p, int q)
{
    int pov = a[q];
    int i = p, j = q, temp;
    do
    {
        while (a[j] >= pov && i < j)
            j--;
        while (a[i] <= pov && i < j)
            i++;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j], a[j] = temp;
        }
    } while (i < j);
    temp = a[i];
    a[i] = pov;
    a[p] = temp;

    return i;
}
void QuickSort(int *a, int i, int j)
{
    if (i < j)
    {
        int m = Partition(a, i, j);
        QuickSort(a, i, m - 1);
        QuickSort(a, m + 1, j);
    }
}
int main()
{
    clock_t start, stop;
    int *array_1 = new int[n];
    for (int i = 0; i < n; array_1[i] = rand(), i++);
    start = clock();
    BubbleSort(array_1, n - 1);
    stop = clock();
    cout << "For " << n << " elements" << endl << "Bubble Sort: " << ((double)(stop - start)) / CLOCKS_PER_SEC << " seconds" << endl;
    start = clock();
    QuickSort(array_1, 0, n - 1);
    stop = clock();
    cout << "Quick Sort: " << ((double)(stop - start)) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}

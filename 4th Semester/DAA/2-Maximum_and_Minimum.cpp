//2. Implement divide and conquer method for finding the maximum and minimum number.

#include <iostream>
#include <climits>
using namespace std;
struct Pair
{
    int min;
    int max;
};
Pair findMinMax(int arr[], int low, int high)
{
    Pair minmax, left_minmax, right_minmax;
    int mid;
    if (low == high)
    {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
    mid = (low + high) / 2;
    left_minmax = findMinMax(arr, low, mid);
    right_minmax = findMinMax(arr, mid + 1, high);
    if (left_minmax.min < right_minmax.min)
        minmax.min = left_minmax.min;
    else
        minmax.min = right_minmax.min;
    if (left_minmax.max > right_minmax.max)
        minmax.max = left_minmax.max;
    else
        minmax.max = right_minmax.max;
    return minmax;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Pair minmax = findMinMax(arr, 0, n - 1);
    cout << "Minimum element: " << minmax.min << endl;
    cout << "Maximum element: " << minmax.max << endl;

    return 0;
}

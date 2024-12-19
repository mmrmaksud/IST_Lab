//5. Implement the 0/1 knapsack problem that will generate an optimal solutions for the given set of instance such as no of elements n, cost pi and weight wi

#include <iostream>
using namespace std;
int knapsack(int values[], int weights[], int n, int capacity)
{
   int dp[n + 1][capacity + 1];
   for (int i = 0; i <= n; ++i)
      for (int w = 0; w <= capacity; ++w)
         dp[i][w] = 0;
   for (int i = 1; i <= n; ++i)
   {
      for (int w = 1; w <= capacity; ++w)
      {
         if (weights[i - 1] <= w)
         {
            dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
         }
         else
         {
            dp[i][w] = dp[i - 1][w];
         }
      }
   }
   return dp[n][capacity];
}
int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int values[n], weights[n];
   cout << "Enter the values and weights of each element:" << endl;
   for (int i = 0; i < n; ++i)
   {
      cout << "Element " << i + 1 << ": ";
      cin >> values[i] >> weights[i];
   }
   int capacity;
   cout << "Enter the capacity of the knapsack: ";
   cin >> capacity;
   int max_value = knapsack(values, weights, n, capacity);
   cout << "Maximum value possible: " << max_value << endl;

   return 0;
}

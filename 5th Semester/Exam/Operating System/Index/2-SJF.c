#include <stdio.h>
void sortProcesses(int n, int burstTime[], int process[])
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (burstTime[j] > burstTime[j + 1])
            {
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}
void calculateWaitingTime(int n, int burstTime[], int waitingTime[])
{
    int i;
    waitingTime[0] = 0;
    for (i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
}
void calculateTurnAroundTime(int n, int burstTime[], int waitingTime[], int turnAroundTime[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }
}
void displayResults(int n, int process[], int burstTime[], int waitingTime[], int turnAroundTime[])
{
    int i;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", process[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
}
int main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n], burstTime[n], waitingTime[n], turnAroundTime[n];
    for (i = 0; i < n; i++)
    {
        process[i] = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    sortProcesses(n, burstTime, process);
    calculateWaitingTime(n, burstTime, waitingTime);
    calculateTurnAroundTime(n, burstTime, waitingTime, turnAroundTime);
    displayResults(n, process, burstTime, waitingTime, turnAroundTime);
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnAroundTime / n);

    return 0;
}
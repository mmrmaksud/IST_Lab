#include <stdio.h>
void calculateTimes(int pid[], int arrival[], int burst[], int waiting[], int turnaround[], int n)
{
    int currentTime = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (currentTime < arrival[i])
        {
            currentTime = arrival[i];
        }
        waiting[i] = currentTime - arrival[i];
        turnaround[i] = waiting[i] + burst[i];
        currentTime += burst[i];
    }
}
void printProcesses(int pid[], int arrival[], int burst[], int waiting[], int turnaround[], int n)
{
    int i;
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-----------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival[i], burst[i], waiting[i], turnaround[i]);
    }
}
int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], arrival[n], burst[n], waiting[n], turnaround[n];
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("\nEnter arrival time and burst time for Process %d: ", pid[i]);
        scanf("%d%d", &arrival[i], &burst[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arrival[j] > arrival[j + 1])
            {
                int temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;
                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }
    calculateTimes(pid, arrival, burst, waiting, turnaround, n);
    printProcesses(pid, arrival, burst, waiting, turnaround, n);
    float totalWaiting = 0, totalTurnaround = 0;
    for (i = 0; i < n; i++)
    {
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }
    printf("\nAverage Waiting Time: %.2f\n", totalWaiting / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / n);

    return 0;
}

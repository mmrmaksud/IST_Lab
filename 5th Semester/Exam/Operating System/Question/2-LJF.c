//Write a C program to implement Longest Job First (LJF) algorithm.

#include <stdio.h>
struct Process
{
    int id, burst_time, waiting_time, turnaround_time;
};

void sortByBurstTime(struct Process proc[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (proc[j].burst_time < proc[j + 1].burst_time)
            {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(struct Process proc[], int n)
{
    proc[0].waiting_time = 0;
    for (int i = 1; i < n; i++)
    {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
    for (int i = 0; i < n; i++)
    {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void display(struct Process proc[], int n)
{
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++)
    {
        proc[i].id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].burst_time);
    }

    sortByBurstTime(proc, n);
    calculateTimes(proc, n);
    display(proc, n);

    return 0;
}

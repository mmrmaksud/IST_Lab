//Write a C program to implement Highest Response Ratio Next (HRRN) algorithm.

#include <stdio.h>

struct Process
{
    int id, arrival, burst, waiting, turnaround;
    float response_ratio;
};

void calculateHRRN(struct Process proc[], int n)
{
    int time = 0, completed = 0, max_index;
    while (completed < n)
    {
        max_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrival <= time && proc[i].waiting == -1)
            {
                proc[i].response_ratio = (float)(time - proc[i].arrival + proc[i].burst) / proc[i].burst;
                if (max_index == -1 || proc[i].response_ratio > proc[max_index].response_ratio)
                {
                    max_index = i;
                }
            }
        }

        if (max_index == -1)
        {
            time++;
            continue;
        }

        time += proc[max_index].burst;
        proc[max_index].waiting = time - proc[max_index].arrival - proc[max_index].burst;
        proc[max_index].turnaround = proc[max_index].waiting + proc[max_index].burst;
        completed++;
    }
}

void display(struct Process proc[], int n)
{
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].arrival, proc[i].burst, proc[i].waiting, proc[i].turnaround);
    }
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++)
    {
        proc[i].id = i + 1;
        printf("Enter arrival and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].arrival, &proc[i].burst);
        proc[i].waiting = -1;
    }

    calculateHRRN(proc, n);
    display(proc, n);

    return 0;
}

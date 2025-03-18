//Write a C program to implement Longest Remaining Time First (LRTF) algorithm.

#include <stdio.h>
struct Process
{
    int id, arrival, burst, remaining, completion, turnaround, waiting;
};

void calculateLRTF(struct Process proc[], int n)
{
    int time = 0, completed = 0, max_index;
    while (completed < n)
    {
        max_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrival <= time && proc[i].remaining > 0)
            {
                if (max_index == -1 || proc[i].remaining > proc[max_index].remaining)
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

        proc[max_index].remaining--;
        time++;

        if (proc[max_index].remaining == 0)
        {
            proc[max_index].completion = time;
            proc[max_index].turnaround = proc[max_index].completion - proc[max_index].arrival;
            proc[max_index].waiting = proc[max_index].turnaround - proc[max_index].burst;
            completed++;
        }
    }
}

void display(struct Process proc[], int n)
{
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].arrival, proc[i].burst, proc[i].completion, proc[i].turnaround, proc[i].waiting);
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
        proc[i].remaining = proc[i].burst;
    }

    calculateLRTF(proc, n);
    display(proc, n);

    return 0;
}

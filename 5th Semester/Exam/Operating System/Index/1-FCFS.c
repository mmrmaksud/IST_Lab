#include <stdio.h>
void fwt(int process[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    int i;
    for (i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}
void ftat(int process[], int n, int bt[], int wt[], int tat[])
{
    int i;
    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void fat(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    fwt(processes, n, bt, wt);
    ftat(processes, n, bt, wt, tat);
    printf("Process\t Burst Time\tWaiting Time\tTurnaround Time\n");
    int i;
    for (i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time (W.T): %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time (T.A.T): %.2f\n", (float)total_tat / n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n];
    printf("Enter burst time for each process:\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    fat(NULL, n, bt);
    return 0;
}

/*Correction: 1-FCFS.c

#include <stdio.h>

void fwt(int process[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void ftat(int process[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void fat(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    fwt(processes, n, bt, wt);
    ftat(processes, n, bt, wt, tat);

    printf("Process\t Burst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" P%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time (W.T): %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time (T.A.T): %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], processes[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;  // Assign process ID
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    fat(processes, n, bt);
    return 0;
}
*/
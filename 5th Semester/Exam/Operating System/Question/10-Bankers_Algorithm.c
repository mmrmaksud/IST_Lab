//Write a C program for Banker's algorithm for deadlock avoidance.

#include <stdio.h>

#define max_proc 5
#define max_res 3

int processes, resources;
int allocation[max_proc][max_res], max[max_proc][max_res], need[max_proc][max_res], available[max_res];
int safeSequence[max_proc];

void calculateNeedMatrix()
{
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void printMatrix(int matrix[max_proc][max_res], char *title)
{
    printf("\n%s:\n", title);
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int isSafeSequence()
{
    int work[max_res], finish[max_proc] = {0}, count = 0;

    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    while (count < processes)
    {
        int found = 0;
        for (int i = 0; i < processes; i++)
        {
            if (!finish[i])
            {
                int canAllocate = 1;
                for (int j = 0; j < resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < resources; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
        {
            return 0; // System is in an unsafe state
        }
    }
    return 1;
}

int main()
{
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources: ");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    // Calculate Need Matrix
    calculateNeedMatrix();
    printMatrix(need, "Need Matrix");

    // Check for Safe Sequence
    if (isSafeSequence())
    {
        printf("\nSafe Sequence: ");
        for (int i = 0; i < processes; i++)
        {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nNo Safe Sequence Found! The system is in an unsafe state.\n");
    }

    return 0;
}
#include <stdio.h>
void first_fit(int blocks[], int block_count, int processes[], int process_count)
{
    printf("\nFirst Fit Allocation:\n");
    int allocated[50];
    int i, j;
    for (i = 0; i < block_count; i++)
    {
        allocated[i] = 0;
    }
    for (i = 0; i < process_count; i++)
    {
        int found = 0;
        for (j = 0; j < block_count; j++)
        {
            if (allocated[j] == 0 && blocks[j] >= processes[i])
            {
                blocks[j] -= processes[i];
                allocated[j] = 1;
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}
void best_fit(int blocks[], int block_count, int processes[], int process_count)
{
    printf("\nBest Fit Allocation:\n");
    int allocated[50];
    int i, j;
    for (i = 0; i < block_count; i++)
    {
        allocated[i] = 0;
    }
    for (i = 0; i < process_count; i++)
    {
        int best_idx = -1;
        for (j = 0; j < block_count; j++)
        {
            if (allocated[j] == 0 && blocks[j] >= processes[i])
            {
                if (best_idx == -1 || blocks[j] < blocks[best_idx])
                {
                    best_idx = j;
                }
            }
        }
        if (best_idx != -1)
        {
            blocks[best_idx] -= processes[i];
            allocated[best_idx] = 1;
            printf("Process %d allocated to Block %d\n", i + 1, best_idx + 1);
        }
        else
        {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}
void worst_fit(int blocks[], int block_count, int processes[], int process_count)
{
    printf("\nWorst Fit Allocation:\n");
    int allocated[50];
    int i, j;
    for (i = 0; i < block_count; i++)
    {
        allocated[i] = 0;
    }
    for (i = 0; i < process_count; i++)
    {
        int worst_idx = -1;

        for (j = 0; j < block_count; j++)
        {
            if (allocated[j] == 0 && blocks[j] >= processes[i])
            {
                if (worst_idx == -1 || blocks[j] > blocks[worst_idx])
                {
                    worst_idx = j;
                }
            }
        }
        if (worst_idx != -1)
        {
            blocks[worst_idx] -= processes[i];
            allocated[worst_idx] = 1;
            printf("Process %d allocated to Block %d\n", i + 1, worst_idx + 1);
        }
        else
        {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}
int main()
{
    int block_count, process_count;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &block_count);
    printf("Enter the number of processes: ");
    scanf("%d", &process_count);
    int blocks[50];
    int original_blocks[50];
    int processes[50];
    int i;
    printf("Enter the sizes of each block:\n");
    for (i = 0; i < block_count; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
        original_blocks[i] = blocks[i];
    }
    printf("Enter the sizes of each process:\n");
    for (i = 0; i < process_count; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }
    first_fit(blocks, block_count, processes, process_count);
    for (i = 0; i < block_count; i++)
    {
        blocks[i] = original_blocks[i];
    }
    best_fit(blocks, block_count, processes, process_count);
    for (i = 0; i < block_count; i++)
    {
        blocks[i] = original_blocks[i];
    }
    worst_fit(blocks, block_count, processes, process_count);

    return 0;
}

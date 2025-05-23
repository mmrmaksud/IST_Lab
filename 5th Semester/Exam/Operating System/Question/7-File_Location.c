/*Write a C program to simulate all file location strategies:
a) Sequential
b) Indexed
c) Linked*/

// Combined

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100

// Disk block structure for Linked Allocation
struct Block
{
    int isAllocated;
    int next;
} disk[MAX_BLOCKS];

// ✅ Initialize Disk Blocks
void initializeDisk()
{
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        disk[i].isAllocated = 0;
        disk[i].next = -1;
    }
}

// ✅ Sequential Allocation
void sequentialAllocation(int startBlock, int fileSize)
{
    if (startBlock + fileSize > MAX_BLOCKS)
    {
        printf("Not enough contiguous space available!\n");
        return;
    }
    for (int i = startBlock; i < startBlock + fileSize; i++)
    {
        if (disk[i].isAllocated)
        {
            printf("Block %d already allocated! Allocation failed.\n", i);
            return;
        }
    }
    for (int i = startBlock; i < startBlock + fileSize; i++)
    {
        disk[i].isAllocated = 1;
    }
    printf("Sequential Allocation successful from block %d to %d\n", startBlock, startBlock + fileSize - 1);
}

// ✅ Indexed Allocation
void indexedAllocation(int indexBlock, int fileSize)
{
    if (disk[indexBlock].isAllocated)
    {
        printf("Index block %d is already allocated!\n", indexBlock);
        return;
    }

    int *blocks = (int *)malloc(fileSize * sizeof(int));
    if (blocks == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    int allocated = 0;
    for (int i = 0; i < MAX_BLOCKS && allocated < fileSize; i++)
    {
        if (!disk[i].isAllocated)
        {
            blocks[allocated++] = i;
            disk[i].isAllocated = 1;
        }
    }

    if (allocated < fileSize)
    {
        printf("Not enough free blocks available!\n");
        free(blocks);
        return;
    }

    disk[indexBlock].isAllocated = 1;
    printf("Indexed Allocation successful at index block %d with blocks: ", indexBlock);
    for (int i = 0; i < fileSize; i++)
    {
        printf("%d ", blocks[i]);
    }
    printf("\n");
    free(blocks);
}

// ✅ Linked Allocation
void linkedAllocation(int startBlock, int fileSize)
{
    if (disk[startBlock].isAllocated)
    {
        printf("Starting block %d already allocated!\n", startBlock);
        return;
    }

    int *blocks = (int *)malloc(fileSize * sizeof(int));
    if (blocks == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    int allocated = 0, prev = -1;
    for (int i = 0; i < MAX_BLOCKS && allocated < fileSize; i++)
    {
        if (!disk[i].isAllocated)
        {
            blocks[allocated++] = i;
            disk[i].isAllocated = 1;
            if (prev != -1)
            {
                disk[prev].next = i;
            }
            prev = i;
        }
    }

    if (allocated < fileSize)
    {
        printf("Not enough free blocks available!\n");
        free(blocks);
        return;
    }

    disk[startBlock].isAllocated = 1;
    printf("Linked Allocation successful at block %d with chain: ", startBlock);
    for (int i = 0; i < fileSize; i++)
    {
        printf("%d -> ", blocks[i]);
    }
    printf("NULL\n");
    free(blocks);
}

// ✅ Display Disk Status
void displayDisk()
{
    printf("Disk Blocks:\n");
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%d ", disk[i].isAllocated);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

// ✅ Main Function
int main()
{
    initializeDisk();
    int choice, startBlock, fileSize, indexBlock;

    while (1)
    {
        printf("\nFile Allocation Strategies:\n");
        printf("1. Sequential Allocation\n");
        printf("2. Indexed Allocation\n");
        printf("3. Linked Allocation\n");
        printf("4. Display Disk\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter start block and file size: ");
            scanf("%d %d", &startBlock, &fileSize);
            sequentialAllocation(startBlock, fileSize);
            break;
        case 2:
            printf("Enter index block and file size: ");
            scanf("%d %d", &indexBlock, &fileSize);
            indexedAllocation(indexBlock, fileSize);
            break;
        case 3:
            printf("Enter start block and file size: ");
            scanf("%d %d", &startBlock, &fileSize);
            linkedAllocation(startBlock, fileSize);
            break;
        case 4:
            displayDisk();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

//------------------------------------------------

/*
// Separate 3 Files

// 1. Sequential Allocation

#include <stdio.h>

#define MAX_BLOCKS 100

int disk[MAX_BLOCKS] = {0}; // 0 = Free, 1 = Allocated

void allocateSequential(int start, int length)
{
    int i;
    for (i = start; i < start + length; i++)
    {
        if (disk[i] == 1)
        {
            printf("Block %d is already allocated! Sequential allocation failed.\n", i);
            return;
        }
    }
    for (i = start; i < start + length; i++)
    {
        disk[i] = 1;
    }
    printf("File allocated sequentially from block %d to %d\n", start, start + length - 1);
}

void displayDisk()
{
    printf("Disk Blocks:\n");
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%d ", disk[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

int main()
{
    int start, length;
    printf("Enter start block and length for sequential allocation: ");
    scanf("%d %d", &start, &length);

    allocateSequential(start, length);
    displayDisk();

    return 0;
}

-------------------------------------

// 2. Indexed Allocation

#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int disk[MAX_BLOCKS] = {0}; // 0 = Free, 1 = Allocated

void allocateIndexed(int indexBlock, int numBlocks, int blocks[])
{
    if (disk[indexBlock] == 1)
    {
        printf("Index block %d is already allocated!\n", indexBlock);
        return;
    }

    disk[indexBlock] = 1; // Allocate index block
    printf("Index block %d allocated.\n", indexBlock);

    for (int i = 0; i < numBlocks; i++)
    {
        if (disk[blocks[i]] == 1)
        {
            printf("Block %d is already allocated! Indexed allocation failed.\n", blocks[i]);
            return;
        }
    }

    for (int i = 0; i < numBlocks; i++)
    {
        disk[blocks[i]] = 1;
    }

    printf("File allocated using Indexed Allocation with index block %d\n", indexBlock);
}

void displayDisk()
{
    printf("Disk Blocks:\n");
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%d ", disk[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

int main()
{
    int indexBlock, numBlocks;
    printf("Enter index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks to allocate: ");
    scanf("%d", &numBlocks);

    int blocks[numBlocks];
    printf("Enter the block numbers: ");
    for (int i = 0; i < numBlocks; i++)
    {
        scanf("%d", &blocks[i]);
    }

    allocateIndexed(indexBlock, numBlocks, blocks);
    displayDisk();

    return 0;
}

-------------------------------------

// 3. Linked Allocation

#include <stdio.h>

#define MAX_BLOCKS 100

struct Block
{
    int isAllocated;
    int next;
} disk[MAX_BLOCKS];

void allocateLinked(int start, int numBlocks, int blocks[])
{
    int prev = start;
    disk[start].isAllocated = 1;

    for (int i = 0; i < numBlocks; i++)
    {
        if (disk[blocks[i]].isAllocated == 1)
        {
            printf("Block %d is already allocated! Linked allocation failed.\n", blocks[i]);
            return;
        }
        disk[blocks[i]].isAllocated = 1;
        disk[prev].next = blocks[i];
        prev = blocks[i];
    }
    disk[prev].next = -1;
    printf("File allocated using Linked Allocation starting at block %d\n", start);
}

void displayLinkedList(int start)
{
    int current = start;
    printf("File Blocks (Linked List): ");
    while (current != -1)
    {
        printf("%d -> ", current);
        current = disk[current].next;
    }
    printf("NULL\n");
}

void displayDisk()
{
    printf("Disk Blocks:\n");
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%d ", disk[i].isAllocated);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

int main()
{
    int start, numBlocks;
    printf("Enter start block: ");
    scanf("%d", &start);

    printf("Enter number of blocks to allocate: ");
    scanf("%d", &numBlocks);

    int blocks[numBlocks];
    printf("Enter the block numbers: ");
    for (int i = 0; i < numBlocks; i++)
    {
        scanf("%d", &blocks[i]);
    }

    allocateLinked(start, numBlocks, blocks);
    displayLinkedList(start);
    displayDisk();

    return 0;
}

----------------------------------------------------

// Real File Operations, Actual File System

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_BLOCKS 100

struct Block
{
    int isAllocated;
    int next;
} disk[MAX_BLOCKS];

void initializeDisk()
{
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        disk[i].isAllocated = 0;
        disk[i].next = -1;
    }
}

// ✅ Sequential Allocation (File Writing)
void writeSequentialFile(const char *filename, const char *content)
{
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0)
    {
        perror("File creation failed");
        return;
    }
    write(fd, content, strlen(content));
    close(fd);
    printf("File '%s' written sequentially.\n", filename);
}

// ✅ Indexed Allocation (File Reading)
void readIndexedFile(const char *filename)
{
    char buffer[1024];
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("File read failed");
        return;
    }
    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    close(fd);
    printf("File '%s' contains: %s\n", filename, buffer);
}

// ✅ Linked Allocation (File Deletion)
void deleteFile(const char *filename)
{
    if (unlink(filename) == 0)
        printf("File '%s' deleted successfully.\n", filename);
    else
        perror("File deletion failed");
}

// ✅ Display Disk Status
void displayDisk()
{
    printf("Disk Blocks:\n");
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        printf("%d ", disk[i].isAllocated);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

// ✅ Main Function
int main()
{
    initializeDisk();
    int choice;
    char filename[50], content[1024];

    while (1)
    {
        printf("\nFile Allocation & Operations:\n");
        printf("1. Sequential Allocation (Write File)\n");
        printf("2. Indexed Allocation (Read File)\n");
        printf("3. Linked Allocation (Delete File)\n");
        printf("4. Display Disk\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Buffer clear

        switch (choice)
        {
        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);
            getchar();
            printf("Enter content: ");
            fgets(content, sizeof(content), stdin);
            writeSequentialFile(filename, content);
            break;
        case 2:
            printf("Enter filename to read: ");
            scanf("%s", filename);
            readIndexedFile(filename);
            break;
        case 3:
            printf("Enter filename to delete: ");
            scanf("%s", filename);
            deleteFile(filename);
            break;
        case 4:
            displayDisk();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
*/
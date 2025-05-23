//Write a C program to simulate the concept of the Dining Philosophers problem.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 4 // Number of philosophers
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define MAX_EAT_TIMES 3 // Each philosopher eats this many times

int state[N];               // Track philosopher state
int phil[N] = {0, 1, 2, 3}; // Philosopher identifiers

sem_t mutex; // Semaphore for critical section
sem_t S[N];  // Semaphore for each philosopher

void test(int philosopher)
{
    if (state[philosopher] == HUNGRY &&
        state[(philosopher + 3) % N] != EATING &&
        state[(philosopher + 1) % N] != EATING)
    {

        state[philosopher] = EATING;
        printf("Philosopher %d takes forks %d and %d and starts EATING\n",
               philosopher, (philosopher + 3) % N, philosopher);
        sleep(2);
        printf("Philosopher %d finishes eating\n", philosopher);
        sem_post(&S[philosopher]); // Allow philosopher to eat
    }
}

void take_fork(int philosopher)
{
    sem_wait(&mutex);
    state[philosopher] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", philosopher);
    test(philosopher);
    sem_post(&mutex);
    sem_wait(&S[philosopher]);
    sleep(1);
}

void put_fork(int philosopher)
{
    sem_wait(&mutex);
    state[philosopher] = THINKING;
    printf("Philosopher %d puts forks %d and %d down and starts THINKING\n",
           philosopher, (philosopher + 3) % N, philosopher);
    test((philosopher + 3) % N);
    test((philosopher + 1) % N);
    sem_post(&mutex);
}

void *philosopher(void *num)
{
    int *i = num;
    for (int eat_count = 0; eat_count < MAX_EAT_TIMES; eat_count++)
    {
        printf("Philosopher %d is THINKING\n", *i);
        sleep(1);
        take_fork(*i);
        sleep(1);
        put_fork(*i);
    }
    printf("Philosopher %d has finished eating and is leaving.\n", *i);
    return NULL;
}

int main()
{
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    for (int i = 0; i < N; i++)
    {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is created\n", i);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);

    printf("All philosophers have finished eating. Simulation ends.\n");
    return 0;
}
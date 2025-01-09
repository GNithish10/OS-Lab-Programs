#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
void create_binary_semaphore(sem_t *sem)
{
    if (sem_init(sem, 0, 1) != 0)
    {
        perror("Failed to initialize binary semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Binary semaphore initialized with value 1 (locked/unlocked state).\n");
}
void create_counting_semaphore(sem_t *sem, unsigned int value)
{
    if (sem_init(sem, 0, value) != 0)
    {
        perror("Failed to initialize counting semaphore");
        exit(EXIT_FAILURE);
    }
    printf("Counting semaphore initialized with value %u.\n", value);
}

int main()
{
    sem_t binary_semaphore;
    sem_t counting_semaphore;

    // Create and initialize a binary semaphore
    create_binary_semaphore(&binary_semaphore);

    // Create and initialize a counting semaphore with an initial value of 3
    create_counting_semaphore(&counting_semaphore, 3);
    return 0;
}

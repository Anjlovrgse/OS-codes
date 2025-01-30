#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)1122, 1024, 0666 | IPC_CREAT); // Create or get shared memory
    segment
        printf("Key of Shared memory is %d\n", shmid); // Print shared memory key
    shared_memory = shmat(shmid, NULL, 0);             // Attach shared memory segment to process
    printf("Process attached at %p\n", shared_memory); // Print memory address where the
    segment is attached
        printf("Enter some data to write to shared memory:\n"); // Prompt user for input
    read(0, buff, 100);                                         // Read user input into buff
    strcpy(shared_memory, buff);                                // Copy user input to shared memory
    printf("You Wrote: %s\n", (char *)shared_memory);           // Print the written data
}
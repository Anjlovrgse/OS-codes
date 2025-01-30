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
    shmid = shmget((key_t)1122, 1024, 0666);           // Access the shared memory segment
    printf("Key of Shared memory is %d\n", shmid);     // Print shared memory key
    shared_memory = shmat(shmid, NULL, 0);             // Attach shared memory segment to process
    printf("Process attached at %p\n", shared_memory); // Print memory address where the
    segment is attached
        printf("Data read from shared memory is: %s\n", (char *)shared_memory); // Read and
    display data from shared memory
}
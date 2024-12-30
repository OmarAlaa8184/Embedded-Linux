#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 12345  // Shared memory key
#define SHM_SIZE 4096  // Shared memory size

int main() {
    // Create shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory
    char *shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write a message to the shared memory
    const char *message = "Hello from the writer using shmget!";
    strncpy(shared_memory, message, SHM_SIZE);
    printf("Writer: Wrote message: \"%s\" to shared memory.\n", message);

    // Wait for user input before exiting
    printf("Writer: Press Enter to exit...\n");
    getchar();

    // Detach from shared memory
    shmdt(shared_memory);

    return 0;
}


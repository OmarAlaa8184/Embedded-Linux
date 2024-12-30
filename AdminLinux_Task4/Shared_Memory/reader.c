#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 12345  // Shared memory key
#define SHM_SIZE 4096  // Shared memory size

int main() {
    // Get the shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
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

    // Read the message from the shared memory
    printf("Reader: Read message: \"%s\" from shared memory.\n", shared_memory);

    // Wait for user input before cleaning up
    printf("Reader: Press Enter to clean up and exit...\n");
    getchar();

    // Detach from shared memory
    shmdt(shared_memory);

    // Remove the shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}


#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void Printf(int fd, const char *format, ...);
// Custom Printf function

int main() {
    // Example usage
    Printf(STDOUT_FILENO, "Hello, stdout: %d\n",10);
    Printf(STDERR_FILENO, "Hello, stderr:");

    // Optionally, write to a file
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd != -1) {
        Printf(file_fd, "Writing to a file:");
        close(file_fd);
    } else {
        Printf(STDERR_FILENO, "Failed to open file\n");
    }

    return 0;
}

void Printf(int fd, const char *format, ...) {
    char buffer[1024]; // Temporary buffer for formatted output
    va_list args;

    // Initialize the variable argument list
    va_start(args, format);

    // Format the string
    vsnprintf(buffer, sizeof(buffer), format, args);

    // End variable argument processing
    va_end(args);

    // Write the formatted string to the specified file descriptor
    write(fd, buffer, strlen(buffer));
}




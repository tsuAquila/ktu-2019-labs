#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd;
    char buffer[BUFFER_SIZE];

    // Create file
    fd = open("file.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        printf("Error creating file.\n");
        return 1;
    }

    // Write to file
    char *text = "Hello, world!";
    int len = strlen(text);
    if (write(fd, text, len) != len)
    {
        printf("Error writing to file.\n");
        return 1;
    }

    // Close file
    if (close(fd) == -1)
    {
        printf("Error closing file.\n");
        return 1;
    }

    // Open file for reading
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read from file
    int n = read(fd, buffer, BUFFER_SIZE);
    if (n == -1)
    {
        printf("Error reading from file.\n");
        return 1;
    }

    // Close file
    if (close(fd) == -1)
    {
        printf("Error closing file.\n");
        return 1;
    }

    // Display file content
    printf("%.*s\n", n, buffer);

    return 0;
}

#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat file_stat;

    // Get file status
    if (stat("file.txt", &file_stat) == -1)
    {
        printf("Error getting file status.\n");
        return 1;
    }

    // Display file status
    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("File type: ");
    if (S_ISREG(file_stat.st_mode))
    {
        printf("Regular file\n");
    }
    else if (S_ISDIR(file_stat.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISLNK(file_stat.st_mode))
    {
        printf("Symbolic link\n");
    }
    else
    {
        printf("Unknown\n");
    }
    printf("Number of hard links: %ld\n", file_stat.st_nlink);

    return 0;
}

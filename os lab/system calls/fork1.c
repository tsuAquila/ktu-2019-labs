#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("A\tPID: %d\tParentID: %d\n", getpid(), getppid());
    pid_t b = fork();
    if (b == 0)
    {
        printf("B\tPID: %d\tParentID: %d\n", getpid(), getppid());
        pid_t c = fork();
        if (c == 0)
        {
            printf("C\tPID: %d\tParentID: %d\n", getpid(), getppid());
        }
    }
    wait();
    return 0;
}
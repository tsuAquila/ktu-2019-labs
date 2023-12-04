#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            printf("%d ", i);
            fflush(stdout);
            sleep(1);
        }
    }
    else if (pid > 0)
    {
        for (int i = 11; i <= 20; i++)
        {
            printf("%d ", i);
            fflush(stdout);
            sleep(1);
        }
    }
    else
    {
        printf("Fork failed.\n");
        return 1;
    }

    return 0;
}

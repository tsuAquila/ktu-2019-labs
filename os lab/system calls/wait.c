#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    // Child process
    for (int i = 1; i <= 10; i++) {
      printf("%d ", i);
      fflush(stdout);
    }
  } else if (pid > 0) {
    // Parent process
    wait(NULL); // Wait for child process to finish
    for (int i = 11; i <= 20; i++) {
      printf("%d ", i);
      fflush(stdout);
    }
  } else {
    // Fork failed
    printf("Fork failed.\n");
    return 1;
  }

  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> /* Deklaracje standardowych funkcji uniksowych fork(), write() itd. */

int main()
{
    pid_t pid = getpid();
    printf("Moj PID = %d\n", pid);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define CHAINED_PROCESSES 5
#define SLEEP_TIME 5

int main()
{
    pid_t pid;
    int i;

    printf("getpid(); //=> %d\n", getpid());

    for (i = 0; i < CHAINED_PROCESSES; i++) {
        if ((pid = fork()) == 0) {
            printf("getpid(); //=> %d\n", getpid());
            if (i == CHAINED_PROCESSES-1) {
                printf("Ostatni potomek stworzny\nMasz %d sekund na wywolanie `pstree`\n", SLEEP_TIME);
                sleep(SLEEP_TIME);
                return EXIT_SUCCESS;
            }
        }
        else {
            break;
        }
    }

    if (wait(0) == -1) {
        fprintf(stderr, "Blad w wait(0)\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

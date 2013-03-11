#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> /* Deklaracje standardowych funkcji uniksowych fork(), write() itd. */

int main()
{
    pid_t pid;
    printf("Moj PID = %d\n", getpid());

    switch(pid = fork()) {
        case -1:
            fprintf(stderr, "Blad w fork()\n");
            return EXIT_FAILURE;
        case 0: /* Proces potomny */
            printf("Jestem procesem potomnym. Wartosc przekazana przez getpid() %d\n", getpid());
            printf("Jestem procesem potomnym. Wartosc przekazana przez fork() %d\n", pid);
            return EXIT_SUCCESS;
        default: /* Proces macierzysty */
            printf("Jestem procesem macierzystym. Wartosc przekazana przez getpid() %d\n", getpid());
            printf("Jestem procesem macierzystym. Wartosc przekazana przez fork() %d\n", pid);
            if(wait(0) == -1) { /* Oczekiwanie na zakończenie procesu potomnego */
                fprintf(stderr, "Blad w wait\n");
                return EXIT_FAILURE;
            }
            return EXIT_SUCCESS;
    }
}

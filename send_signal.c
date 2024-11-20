/**
 * File: send_signal.c
 * Modified by: Andrew Keenan
 * 
 * Brief summary of program: sends a signal to a process
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

int main (int argc, char *argv[]) {
    int pid;
    if (argc == 2) {
        pid = atoi(argv[1]);
    } else {
        printf("Error with command line\n");
        exit(1);
    }

    // setup random number
    srand(time(NULL));
    int random = rand() % 100;

    union sigval signal;
    signal.sival_int = random;

    sigqueue(pid, SIGUSR1, signal);
    return 0;
}
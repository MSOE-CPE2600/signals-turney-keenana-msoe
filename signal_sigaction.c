/**
 * File: signal_sigaction.c
 * Modified by: Andrew Keenan
 * 
 * Brief summary of program: Uses sigaction to handle SIGUSR1
 */

 #include <signal.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>

 void handler(int sig, siginfo_t *info, void *context) {
    int pid;
    if (info != NULL) {
        pid = info->si_pid;
    } else {
        printf("error getting info\n");
        exit(1);
    }
    printf("pid of user that sent SIGUSR1: %d\n", pid);
    exit(1);
 }

 int main() {
    // print pid for later
    int pid = getpid();
    printf("%d\n", pid);

    // initialize struct
    struct sigaction sa;

    // setup flags and handlers
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;

    // pass through struct using sigaction
    sigaction(SIGUSR1, &sa, NULL);
    
    while (1) {
        sleep(1);
        // send the SIGUSR1 signal using kill in console
    }
    return 0;
 }

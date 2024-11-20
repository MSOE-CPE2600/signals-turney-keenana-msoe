/**
 * File: recv_signal.c
 * Modified by: Andrew Keenan
 * 
 * Brief summary of program: recieves a signal and prints out the int
 */

#include <signal.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>

 void handler(int sig, siginfo_t *info, void *context) {
    if (info != NULL) {
        printf("Received integer: %d\n", info->si_value.sival_int);
    }
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
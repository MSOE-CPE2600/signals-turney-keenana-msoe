/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Andrew Keenan
 * 
 * Brief summary of modifications: i removed exit(1) from signal handler.
 * I also added a new sigkill on the 3rd second
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // get pid
    int pid = getpid();

    // set a counter
    int count = 0;
    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
        // use kill to send signal
        if (kill(pid, SIGINT) == -1) {
            printf("failed to send signal\n");
        } else {
            printf("signal sent through kill\n");
        }
        if (count == 3) {
            kill(pid, SIGKILL);
        }
        count += 1;
    }
    return 0;
}
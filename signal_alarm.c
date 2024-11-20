/**
 * File: signal_alarm.c
 * Modified by: Andrew Keenan
 * 
 * Brief summary of program: Sets off an alarm after 5 seconds
 */

 #include <signal.h>
 #include <unistd.h>
 #include <stdio.h>

 void signal_handler() {
    printf("ALARM EXPIRED\n");
 }

 int main() {
    // register signal handler
    signal(SIGALRM, signal_handler);

    // set the alarm
    alarm(5);

    // sleep for 8
    sleep(8);

    return 0;
 }

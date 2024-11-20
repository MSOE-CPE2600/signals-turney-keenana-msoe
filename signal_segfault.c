/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Andrew Keenan
 * 
 * Brief summary of modifications: added a handler method to handle the SIGSEGV
 * also registered that signal to call the handler
 */

#include <signal.h>
#include <stdio.h>

void handler() {
    printf("Segmentation fault recieved\n");
}

int main (int argc, char* argv[]) {
    // register the handler
    signal(SIGSEGV, handler);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
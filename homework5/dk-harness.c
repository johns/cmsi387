/**
 * A test harness for running solutions to the pining ktahsophers problem.
 */
#include <pthread.h>
#include <stdio.h>

#include "dk-sync.h"

// The test harness defines the expected interfaces.
void *ktahsopher(int id, int pineBound, int eatBound);

typedef struct {
    int id, pineBound, eatBound;
} zom_def;

/**
 * Thread runner for the ktahsopher.
 */
void *zomRunner(void *arg) {
    zom_def *z = (zom_def *)arg;
    printf("Starting ktahsopher %d\n", z->id);
    ktahsopher(z->id, z->pineBound, z->eatBound);
    printf("Ending ktahsopher %d\n", z->id);
    pthread_exit(NULL);
}

/**
 * Overall driver program.
 */
int main(int argc, char** argv) {
    printf("Starting Ktahsopher test harness...\n");

    // Initialize the synchronization primitives.
    initSync();

    // Start the threads.
    pthread_t zomThread[NUM_KTAHSOPHERS];
    zom_def zomDef[NUM_KTAHSOPHERS];
    int i;
    for (i = 0; i < NUM_KTAHSOPHERS; i++) {
        zomDef[i].id = i;
        zomDef[i].pineBound = 3;
        zomDef[i].eatBound = 2;
        pthread_create(&zomThread[i], NULL, zomRunner, &zomDef[i]);
    }

    // Not really needed, since we'll pretty much run forever...
    for (i = 0; i < NUM_KTAHSOPHERS; i++) {
        pthread_join(zomThread[i], NULL);
    }
}

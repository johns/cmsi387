/**
 * Ktahsopher implementation.
 */
#include "dk-cs.h"
#include "dk-sync.h"
#include "table.h"
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

// [!] TODO: Fix the implementation of a ktahsopher's eating habits below!
// Very little of what is given is done correctly, and it is up to you to
// ensure proper synchronization and avoidance of deadlock; you may modify
// anything inside of the while-loop below to attain the proper behavior
void ktahsopher(int id, int pineBound, int eatBound) {
    while (1) {
        // Simulate a non-trivial pinin'
        printf("Ktahsopher %d is pining...\n", id);
        randomwait(pineBound);

        // Ktahsopher got hungry after pinin'
        if(setKtahsopherState(id, hungry)) { return; }
        printf("Ktahsopher %d is hungry.\n", id);

        // [!] Major TODO: determine policy for chopstick holding here

        // Simulate a non-trivial eat.
        if(setKtahsopherState(id, eating)) { return; }
        printf("Ktahsopher %d is eating...\n", id);
        randomwait(eatBound);
        printf("Ktahsopher %d is done eating.\n", id);
        if(setKtahsopherState(id, pining)) { return; }
        // [!] TODO: What to do after eating?!
    }
}

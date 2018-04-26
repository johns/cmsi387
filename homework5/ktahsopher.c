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

void ktahsopher(int id, int pineBound, int eatBound) {
    while (1) {
        // Simulate a non-trivial pinin'
        printf("Ktahsopher %d is pining...\n", id);
        randomwait(pineBound);

        // Ktahsopher got hungry after pinin'
        if(setKtahsopherState(id, hungry)) { return; }
        printf("Ktahsopher %d is hungry.\n", id);

        pthread_mutex_lock(&mutex);

        sem_wait(chopSem[leftChop(id)]);
        sem_wait(chopSem[rightChop(id)]);

        pickup(id, leftChop(id));
        pickup(id, rightChop(id));

        pthread_mutex_unlock(&mutex);


        if(setKtahsopherState(id, eating)) { return; }
        printf("Ktahsopher %d is eating...\n", id);
        randomwait(eatBound);
        printf("Ktahsopher %d is done eating.\n", id);
        if(setKtahsopherState(id, pining)) { return; }

        putdown(id, leftChop(id));
        putdown(id, rightChop(id));

        sem_post(chopSem[leftChop(id)]);
        sem_post(chopSem[rightChop(id)]);

    }
}

/**
 * Synchronization primitive implementation.
 */
#include "dk-sync.h"

#include "table.h"
#ifdef __APPLE_CC__
#include <fcntl.h>
#endif
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void initSync(void) {
    pthread_mutex_init(&mutex, NULL);
    int i;
    for (i = 0; i < NUM_KTAHSOPHERS; i++) {
#ifndef __APPLE_CC__
        chopSem[i] = &chopSemHolder[i];
        sem_init(chopSem[i], 0, 1);
#else
        char semname[8];
        sprintf(semname, "fork%d", i);
        sem_unlink(semname);
        chopSem[i] = sem_open(semname, O_CREAT, S_IRWXU, 1);
#endif
    }
}

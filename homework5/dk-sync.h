/**
 * Synchronization elements for a pining ktahsopher solution.
 */
#ifndef __DK_SYNC__
#define __DK_SYNC__

#include "table.h"

#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex;
sem_t *chopSem[NUM_KTAHSOPHERS];
#ifndef __APPLE_CC__
sem_t chopSemHolder[NUM_KTAHSOPHERS];
#endif

/**
 * Initializes synchronization primitives.
 */
void initSync(void);

#endif

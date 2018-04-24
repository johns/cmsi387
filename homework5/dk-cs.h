/**
 * Definitions for critical-section functions and shared resources.
 */
#ifndef __DK_CS__
#define __DK_CS__

#include "table.h"

typedef enum {
    pining, hungry, eating, out
} zom_state;

/**
 * Sets the state of ktahsopher i.
 */
int setKtahsopherState(int i, zom_state s);

/**
 * Ktahsopher by id picks up chopstick i.
 */
int pickup(int id, int i);

/**
 * Ktahsopher by id puts down chopstick i.
 */
int putdown(int id, int i);

#endif

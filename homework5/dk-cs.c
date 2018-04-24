/**
 * Implementation (and privates) for critical-section functions.
 */
#include "dk-cs.h"
#include "table.h"

#include <stdio.h>
#include <string.h>

static zom_state ktahsophers[NUM_KTAHSOPHERS];
static int chopsticks[NUM_KTAHSOPHERS];

void displayStatus() {
    char display[(NUM_KTAHSOPHERS * 4) + 8];
    sprintf(display, "[ ");
    int i;
    for (i = 0; i < NUM_KTAHSOPHERS; i++) {
        // Chopstick first.
        if (chopsticks[i]) {
            strcat(display, "| ");
        } else {
            strcat(display, "_ ");
        }

        // Ktahsopher status next.
        switch (ktahsophers[i]) {
            case pining:
                strcat(display, "P ");
                break;
            case hungry:
                strcat(display, "H ");
                break;
            case eating:
                strcat(display, "E ");
                break;
            case out:
                strcat(display, "X ");
                break;
        }
    }
    strcat(display, "]\n");
    printf("%s", display);
}

int isNeighborEating(int id) {
    int left  = (id - 1 < 0) ? NUM_KTAHSOPHERS - 1 : (id - 1),
        right = (id + 1) % NUM_KTAHSOPHERS;
    return ktahsophers[left] == eating || ktahsophers[right] == eating;
}

int setKtahsopherState(int id, zom_state s) {
    // Setting a state of out overrides all checks.
    if (s != out) {
        int error = (s == eating) ? isNeighborEating(id) : 0;
        switch (ktahsophers[id]) {
            case pining:
                if (s != hungry) { error = 1; }
                break;
            case hungry:
                if (s != eating) { error = 1; }
                break;
            case eating:
                if (s != pining) { error = 1; }
                break;

            // Once a ktahsopher is out, they stay out.
            case out:
                return -1;
        }
        if (error) {
            fprintf(stderr, "***** State transition problem!\n");
            ktahsophers[id] = out; // Transition problem? Youuu're outta there
            return -1;
        }
    }
    ktahsophers[id] = s;
    displayStatus();
    return 0;
}

int pickup(int id, int i) {
    if (chopsticks[i]) {
        fprintf(stderr, "***** Chopstick pickup failure!\n");
        setKtahsopherState(id, out);
        return -1;
    }

    chopsticks[i] = 1;
    displayStatus();
    return 0;
}

int putdown(int id, int i) {
    if (!chopsticks[i]) {
        fprintf(stderr, "***** Chopstick putdown failure!\n");
        setKtahsopherState(id, out);
        return -1;
    }

    chopsticks[i] = 0;
    displayStatus();
    return 0;
}

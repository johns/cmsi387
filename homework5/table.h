/**
 * Public definitions for a dining philosophers table.
 */
#ifndef __TABLE__
#define __TABLE__

#define NUM_KTAHSOPHERS 5

/**
 * Returns the index of the fork to the left of philosopher i.
 */
int leftChop(int i);

/**
 * Returns the index of the fork to the right of philosopher i.
 */
int rightChop(int i);

#endif

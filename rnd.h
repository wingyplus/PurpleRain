#ifndef RND_H
#define RND_H

// Random number from 0 - high number
#define RAND(high) rand() % high

// Random number from low - high number
#define RAND_LH(low, high) rand() % low + high


#endif // RND_H

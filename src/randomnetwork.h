/*
 * randomnetwork.h
 *
 *  Created on: April 27, 2014
 *      Author: Marcin Dzieżyc
 */

#ifndef RANDOMNETWORK
#define RANDOMNETWORK

#include "network.h"

class RandomNetwork : public Network {
public:
    RandomNetwork(int v, int e, float p);

    float p;
};

#endif /* RANDOMNETWORK */

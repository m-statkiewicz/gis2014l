/*
 * randomnetwork.cpp
 *
 *  Created on: April 27, 2014
 *      Author: Marcin Dzieżyc
 */

#include <cstdlib>
#include "randomnetwork.h"

RandomNetwork::RandomNetwork(int v, int e, float p) {
    float fRand;
    scale = 7;

    srand(time(NULL));

    if (p < 0)
        p = 2*float(e)/float(v*(v-1));

    this->v = v;
    this->p = p;

    for (int i = 0; i < v; ++i) {
        for (int j = i + 1; j < v; ++j) {

            fRand = ((double) rand() / (RAND_MAX));

            if (fRand < p) {
                fRand = ((double) rand() / (RAND_MAX));
                this->e.insert(Edge(i, j, fRand));
            }
        }
    }
}

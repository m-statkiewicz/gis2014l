/*
 * scalefreenetwork.cpp
 *
 *  Created on: April 27, 2014
 *      Author: Marcin Dzieżyc
 */

#include <cstdlib>
#include <vector>
#include "scalefreenetwork.h"

ScaleFreeNetwork::ScaleFreeNetwork(int v, int m0, int m) {
    unsigned int m0index, noEdges, degreeSum;
    std::vector<unsigned int> degrees, addInds;
    int rind;

    this->v = v;
    degrees.resize(v, 0);
    degreeSum = 0;
    
    srand(time(NULL));
    for (int i = 1; i < m0; ++i) {
        m0index = rand() % i;
        this->e.insert(Edge(m0index, i, 1));
        degrees[m0index]++, degrees[i]++;
        degreeSum += 2;
    }

    noEdges = this->e.size();

    for (int i = m0; i < v; ++i) {
        addInds.clear();
        for (int k = 0; k < m; ++k) {
            rind = rand() % degreeSum;
            for (int j = 0; j < i; ++j) {
                rind -= degrees[j];
                if (rind < 0) {
                    if (e.find(Edge(j, i, 1)) != e.end()) {
                        --k;
                        break;
                    }
                    this->e.insert(Edge(j, i, 1));
                    addInds.push_back(j);
                    break;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            degrees[addInds[j]]++;
        }
        degreeSum += 2*m;
        degrees[i] += m;
    }

}

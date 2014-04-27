/*
 * euclideannetwork.h
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#ifndef EUCLIDEANNETWORK
#define EUCLIDEANNETWORK

#include"network.h"

class EuclideanNetwork : public Network {
public:
	std::vector<float> x;
	std::vector<float> y;
	EuclideanNetwork(int v, float radius);
};
#endif /* EUCLIDEANNETWORK */

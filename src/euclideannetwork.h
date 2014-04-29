/*
 * euclideannetwork.h
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#ifndef EUCLIDEANNETWORK
#define EUCLIDEANNETWORK

#include"network.h"

#include<vector>

class EuclideanNetwork : public Network {
public:
	std::vector<float> x;
	std::vector<float> y;
	EuclideanNetwork(int v, float radius);
    virtual void show(std::string filename, const char *filetype);
};
#endif /* EUCLIDEANNETWORK */

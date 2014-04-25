/*
 * smallworldnetwork.h
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#ifndef SMALLWORLDNETWORK
#define SMALLWORLDNETWORK

#include"network.h"

class SmallWorldNetwork : public Network {
public:
	SmallWorldNetwork(int v, int neighbours, float p);
};
#endif /* SMALLWORLDNETWORK */

/*
 * network.h
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#ifndef NETWORK
#define NETWORK

#include <set>

#include"edge.h"

abstract class Network {
private:
	int v;
	std::set<Edge> e;

public:
	void save(std::string filename);
	void show(std::string filename, char format_flag);
	bool isCompact();
};
#endif /* NETWORK */

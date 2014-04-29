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
#include<string>

class Network {
protected:
	int v;
	std::set<Edge> e;
    unsigned int scale;
	
	void DFS(int act_v, std::set<int>* visited);
public:
	void save(std::string filename);
	virtual void show(std::string filename, const char* filetype);
	bool isCompact();
};
#endif /* NETWORK */

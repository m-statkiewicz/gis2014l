/*
 * edge.h
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#ifndef EDGE
#define EDGE

#include<exception>

class Edge {
private:
	int v1;
	int v2;
	float wage;
public:
	Edge(int v1, int v2);
	Edge(int v1, int v2, float w);
	bool operator<(Edge const &e);
};
#endif /* EDGE */

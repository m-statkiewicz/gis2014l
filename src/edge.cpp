/*
 * edge.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */
#include<cstdlib>

#include"edge.h"

Edge::Edge(int v1, int v2){
	if (v1<v2) {
		this->v1 = v1;
		this->v2 = v2;
	} else {
		this->v1 = v2;
		this->v2 = v1;
	}
	this->wage = (float)rand()/RAND_MAX;
};

Edge::Edge(int v1, int v2, float w){
	if (v1<v2) {
		this->v1 = v1;
		this->v2 = v2;
	} else {
		this->v1 = v2;
		this->v2 = v1;
	}
	this->wage = w;
};

bool Edge::operator<(Edge const &e) const{
	if (this->v1<e.v1)
		return true;
	if (this->v1>e.v1)
		return false;
	if (this->v2<e.v2)
		return true;
	return false; 
};

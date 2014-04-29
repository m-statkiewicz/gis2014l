/*
 * euclideannetwork.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */
#include<cstdlib>
#include<vector>
#include<math.h>
//#include<iostream>

#include"euclideannetwork.h"


EuclideanNetwork::EuclideanNetwork(int v, float radius){
	this->v = v;
	//this->e = new std::set<Edge>();
	float r=radius*radius;
	std::vector<float> x;
	std::vector<float> y;

	for (int i=0; i<v; ++i)	{
		x.push_back((float)(rand()%1000)/1000);
		y.push_back((float)(rand()%1000)/1000);
//		std::cout<<"v[i] = ("<<x[i]<<","<<y[i]<<")\n";
		for (int j=0; j<i; ++j){
			float d = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			if (d<=r)
				e.insert(*(new Edge(i,j,sqrt(d))));
		}
	}
};

void EuclideanNetwork::show(std:;string filename, const char* filetype) {
    GVC_t *gvc;
    Agraph_t *g;
    std::stringstream sStream;
    std::vector<Agnode_t *> vNodes;
    std::vector<Agedge_t *> vEdges;
    int i = 0;

    if (v < 1) return;
    
    gvc = gvContext();
    g = agopen("g", Agundirected, 0);

    while (i < v) {
        sStream.str("");
        sStream << i++;
        vNodes.push_back(agnode(g, sStream.str().c_str(), 1));
        sStream.str("");
        sStream << 
    }

    for (std::set<Edge>::iterator x = e.begin(); x != e.end(); ++x) {
        sStream.str("");
        sStream << ((*x).wage * 2);
        vEdges.push_back(agedge(g, vNodes[(*x).v1], vNodes[(*x).v2], sStream.str().c_str(), 1));
    }

    gvLayout(gvc, g, "neato");
    gvRenderFilename(gvc, g, filetype, filename.c_str());

    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);

    return;

}

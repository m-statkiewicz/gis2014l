/*
 * network.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#include"network.h"
#include<iostream>
#include<fstream>
#include <graphviz/gvc.h>
#include <set>
#include <sstream>
#include <vector>

void Network::save(std::string filename){

std::fstream file;
file.open(filename.c_str(), std::ios::out);
file<<"Network (v="<<v<<", e="<<e.size()<<"):\n";
int oldv1=-1; 
for (std::set<Edge>::iterator it = e.begin(); it != e.end(); ++it)
{
	if (it->v1!=oldv1)
		file<<"\n"<<it->v1<<" :\t";
	file<<it->v2<<"("<<it->wage<< ")\t";
	oldv1=it->v1;
}
file<<"\n";
file.close();
};
void Network::show(std::string filename, const char* filetype) {
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
        agsafeset(vNodes[vNodes.size()-1], "height", "0.4", "");
        agsafeset(vNodes[vNodes.size()-1], "width", "0.4", "");
        agsafeset(vNodes[vNodes.size()-1], "fixedsize", "true", "");
    }

    for (std::set<Edge>::iterator x = e.begin(); x != e.end(); ++x) {
        sStream.str("");
        sStream << ((*x).wage * scale);
        vEdges.push_back(agedge(g, vNodes[(*x).v1], vNodes[(*x).v2], sStream.str().c_str(), 1));
        agsafeset(vEdges[vEdges.size()-1], "len", sStream.str().c_str(), "");
    }

    gvLayout(gvc, g, "fdp");
    gvRenderFilename(gvc, g, filetype, filename.c_str());

    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);

    return;

};

bool Network::isCompact(){
	std::set<int> visited;
	DFS(1, &visited);
	if (visited.size() == this->v) 
		return true;
	return false;
};

void Network::DFS(int act_v, std::set<int>* visited){
	if (visited->count(act_v)==0)
	{
		visited->insert(act_v);
		for (std::set<Edge>::iterator it = e.begin(); it != e.end(); ++it)
		{
			if (it->v1 == act_v)
				DFS(it->v2, visited);
			if (it->v2 == act_v)
				DFS(it->v1, visited);
		}
	}
	return;
};

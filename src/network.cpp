/*
 * network.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#include"network.h"
#include<iostream>

void Network::save(std::string filename){
std::cout<<"Edges - "<<e.size()<<"\n";
	for (std::set<Edge>::iterator it = e.begin(); it != e.end(); ++it)
		std::cout<< it->v1<<" - "<<it->v2<<" ("<<it->wage<< ")\n";
};
void Network::show(std::string filename, char format_flag){};

bool Network::isCompact(){
	std::set<int> visited;
	DFS(1, &visited);
	std::cout<< visited.size()<<"=="<<this->v<<"\n";

	if (visited.size() == this->v) 
		return true;
	return false;
};

void Network::DFS(int act_v, std::set<int>* visited){
	//for (int i=0;i<v;++i) visited->insert(i);
	std::cout<<"DFS in "<<act_v<<"\n Visited:";
	for (std::set<int>::iterator it = visited->begin(); it != visited->end(); ++it)
		std::cout<< *it<<"\t";
		std::cout<<"#"<<visited->size()<<"\n";
		
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

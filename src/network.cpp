#include"network.h"
#include<iostream>

void Network::save(std::string filename){
std::cout<<"Edges - "<<e.size()<<"\n";
//for (std::set<int>::iterator it = e.begin(); it != e.end(); ++it)
//		std::cout<< *it->v1 <<" - "<< *it->v2 <<" ("<< *it->wage<<")\n";
};
void Network::show(std::string filename, char format_flag){};

bool Network::isCompact(){
	std::set<int> visited;
	DFS(1, &visited);
	if (visited.size() == this->v) 
		return true;
	return false;
};

void Network::DFS(int act_v, std::set<int>* visited){
	for (int i=0;i<v;++i) visited->insert(i);/*
	if (visited->count(act_v)==0)
	{
		visited->insert(act_v);
		for (std::set<int>::iterator it = e.begin(); it != e.end(); ++it)
		{
			if (it->v1 == act_v)
				DFS(it->v2, visited);
			if (it->v2 == act_v)
				DFS(it->v1, visited);
		}
	}*/
	return;
};

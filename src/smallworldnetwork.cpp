#include"smallworldnetwork.h"
#include<cstdlib>
#include<iostream>

SmallWorldNetwork::SmallWorldNetwork(int v, int neighbours, float p){
	this->v=v;
	for (int i=0; i<v; ++i){
		for (int n=1; n<=neighbours/2; ++n){
			if (i!=i+n)
				e.insert(*(new Edge(i,(i+n)%v)));
		}
	}
	std::set<Edge> ecpy(e);

	for (std::set<Edge>::iterator it = ecpy.begin(); it != ecpy.end(); ++it){
		if ((float)rand()/RAND_MAX < p) {
			e.erase(*it);
				int i=1;			
			while (i==1){
				int v1=0,v2=0;
				while (v1==v2){
					v1 = rand()%v;
					v2 = rand()%v;
				}
				Edge edge(v1,v2);			
				i=e.count(edge);i<<"\n";
				e.insert(*(new Edge(v1,v2)));
			}
		}		 
	}
};

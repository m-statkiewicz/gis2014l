#include"euclideannetwork.h"

#include<cstdlib>
#include<vector>
#include<math.h>
#include<iostream>

EuclideanNetwork::EuclideanNetwork(int v, float radius){
	this->v = v;
	//this->e = new std::set<Edge>();
	float r=radius*radius;
	std::vector<float> x;
	std::vector<float> y;

	for (int i=0; i<v; ++i)	{
		x.push_back((float)(rand()%1000)/1000);
		y.push_back((float)(rand()%1000)/1000);
		for (int j=0; j<i; ++j){
		float d = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		if (d<=r)
			e.insert(*(new Edge(i,j,sqrt(d))));
		}
	}
};

EuclideanNetwork::~EuclideanNetwork(){
	delete &e;
};

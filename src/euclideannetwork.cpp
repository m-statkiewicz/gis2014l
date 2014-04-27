/*
 * euclideannetwork.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */
#include<cstdlib>
#include<vector>
#include<math.h>

#include"euclideannetwork.h"


EuclideanNetwork::EuclideanNetwork(int v, float radius){
	this->v = v;
	float r=radius*radius;

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

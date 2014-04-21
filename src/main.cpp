/*
 * main.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <cstdlib>


#include "euclideannetwork.h"
#include "randomnetwork.h"
#include "scalefreenetwork.h"
#include "smallworldnetwork.h"
#include "network.h"

void usage();

int main(int argc, char **argv)
{
int t = 0;
int e = 0;
   int n = 0;
   int v = 0;
	float p = -1;
	float r = -1;
	float s = 1;
	std::string d;
	int f = 0;
	
	for (int i=1; i<argc; ++i)
	{
		int j=i;
		if (std::string(argv[i])=="-t"){
				++i;
				std::stringstream str(argv[i]);
				str>>t;
				if (t<0 || t>4){
					std::cout<<"Wrong value (network type not specified).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-v"){
				++i;
				std::stringstream str(argv[i]);
				str>>v;
				if (v<0){
					std::cout<<"Wrong value (vertices number below 0).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-e"){
				++i;
				std::stringstream str(argv[i]);
				str>>e;
				if (e<0){
					std::cout<<"Wrong value (edges number below 0).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-n"){
				++i;
				std::stringstream str(argv[i]);
				str>>n;
				if (n<0){
					std::cout<<"Wrong value (neighbours number below 0).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-p"){
				++i;
				std::stringstream str(argv[i]);
				str>>p;
				if (p>1){	
					std::cout<<"Wrong value (probability > 1).\n";
					--i;
				}
				if (p<0){	
					std::cout<<"Wrong value (probability < 0).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-f"){
				++i;
				std::stringstream str(argv[i]);
				str>>f;
				if (f<0 || f>2){
					std::cout<<"Wrong value (format type not specified).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-d"){
				++i;
				std::stringstream str(argv[i]);
				str>>d;
		}
		if (std::string(argv[i])=="-r"){
				++i;
				std::stringstream str(argv[i]);
				str>>r;
				if (r<0){
					std::cout<<"Wrong value (radius length below 0).\n";
					--i;
				}
		}
		if (std::string(argv[i])=="-s"){
				++i;
				std::stringstream str(argv[i]);
				str>>s;
				if (s<0){
					std::cout<<"Wrong value (side lenght below 0).\n";
					--i;
				}
		}
		if (j==i){
				usage();
				return 0;			
		}
	}
		std::cout<<"t="<<t<<" v="<<v<<" e="<<e<<" p="<<p<<" r="<<r<<" s="<<s<<" n="<<n<<std::endl;
	srand(time(0));
	Network* network;
	switch (t) {
	case 1:
		std::cout<<"Generating euclidean network...\n";
		if (r<=0){	
			std::cout<<"Value not specified (r).\n";
			usage();
			return 0;
		}
		network = new EuclideanNetwork(v,r/s);
		break;
	case 2:
//		network = new RandomNetwork(v);
		break;
	case 3:
//		network = new ScaleFreeNetwork(v,p);
		break;
	case 4:
		if (v<=0){	
			std::cout<<"Value not specified (v).\n";
			usage();
			return 0;
		}if (n<=0){	
			std::cout<<"Value not specified (n).\n";
			usage();
			return 0;
		}
		if (p<0){	
			std::cout<<"Value not specified (p).\n";
			usage();
			return 0;
		}		
		std::cout<<"Generating small world network...\n";
		network = new SmallWorldNetwork(v,n,p);
		break;
	}
	switch (f) {
	case 1:
		network->save(d);
		break;
	case 2:
		network->show(d,'a');
		break;
	}
	std::cout<<"Network created, saved in file "<<d<<". Network is"<< (network->isCompact() ? "" : " not") <<" compact.\n";
	return 1;
}

void usage()
{
std::cout<<"Usage:\nnetworkGenerator [OPTION] \nGenerate network corresponding to parameters:\n\nOptions:\n-d\tdestation file name\n-f\tdestation format:\n\t 1 - Flat file\n\t 2 - jpg\n-t\ttype of network: \n\t 1 - Euclidean Network \n\t 2 - Random Network\n\t 3 - Scale Free Network\n\t 4 - Small World Network\n\n";
std::cout<<"Euclidean Network parameters:\n\t-v\tcount of verticles\n\t-s\tsize side squere in which network will be generate (default 1)\n\t-r\tradius, which edges will be generate\n";
std::cout<<"Random Network parameters:\n\t-v\tcount of verticles\n\t-e\tcount of edges\n\t-p\tedge existing probability\n";
std::cout<<"Scale Free Network parameters:\n\t-v\tcount of verticles\n";
std::cout<<"Small World Network parameters:\n\t-v\tcount of verticles\n\t-n\tcount of neighbours at start\n\t-p\tedge change probability\n";
};

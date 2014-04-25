/*
 * main.cpp
 *
 *  Created on: April 18, 2014
 *      Author: Mateusz Statkiewicz
 */

#define VERSION "0.0.1beta"

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
void help();
void about();

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
int c=0;
if (argc==0){
	help();
}
for (int i=1; i<argc; ++i){
	try{
		int j=i;
		if (std::string(argv[i])=="-a"){
			about();
			return 0;
		}
		if (std::string(argv[i])=="-h"){
			usage();
			return 0;
		}
		if (std::string(argv[i])=="-t"){
			std::stringstream str(argv[++i]);
			str>>t;
			if (t<0 || t>4)
				throw std::string("network type");
		}
		if (std::string(argv[i])=="-v"){
			std::stringstream str(argv[++i]);
			str>>v;
			if (v<0)
				throw std::string("vertices number below 0");
		}
		if (std::string(argv[i])=="-e"){
			std::stringstream str(argv[++i]);
			str>>e;
			if (e<0)
				throw std::string("edges number below 0");
		}
		if (std::string(argv[i])=="-n"){
			std::stringstream str(argv[++i]);
			str>>n;
			if (n<0)
				throw std::string("neighbours number below 0");
		}
		if (std::string(argv[i])=="-p"){
			std::stringstream str(argv[++i]);
			str>>p;
			if (p>1)
				throw std::string("probability > 1");
			if (p<0)	
				throw std::string("probability < 0");
		}
		if (std::string(argv[i])=="-f"){
			std::stringstream str(argv[++i]);
			str>>f;
			if (f<0 || f>2)
				throw std::string("format type not specified");
		}
		if (std::string(argv[i])=="-d"){
			std::stringstream str(argv[++i]);
			str>>d;
		}
		if (std::string(argv[i])=="-r"){
			std::stringstream str(argv[++i]);
			str>>r;
			if (r<0)
				throw std::string("radius length below 0");
		}
		if (std::string(argv[i])=="-s"){
			std::stringstream str(argv[++i]);
			str>>s;
			if (s<0)
				throw std::string("side length below 0");
		}
		if (i==j){
			std::cout<<"Invalid option "<<argv[i]<<".\n";
			help();
			return 0;		
		}
	}catch(std::string e){
		std::cout<<"!!! Wrong value ("<<e<<"). !!!\n";
		c=1;
	}
}
if (c==1){
	help();
	return 0;
}

srand(time(0));
Network* network;
std::string wrongValues;
try{
	if (d.empty())
		wrongValues+="d";
	if (f==0)
		wrongValues+="f";	
	switch (t) {
	case 1:		
		if (v<=0)
			wrongValues+="v";	
		if (r<=0)
			wrongValues+="r";
		if (wrongValues.length() != 0)
			throw wrongValues;	
		std::cout<<"Generating euclidean network...\n";
		network = new EuclideanNetwork(v,r/s);
		break;
	case 2:
		if (v<=0)
			wrongValues+="v";
		if (e<=0 && p<0)
			wrongValues+="ep";
		if (wrongValues.length() != 0)
			throw wrongValues;	
		std::cout<<"Generating random network...\n";
	//		network = new RandomNetwork(v);
		break;
	case 3:
		if (v<=0)
			wrongValues+="v";
		if (wrongValues.length() != 0)
			throw wrongValues;	
		std::cout<<"Generating scale free network...\n";
	//		network = new ScaleFreeNetwork(v,p);
		break;
	case 4:
		if (v<=0)
			wrongValues+="v";	
		if (n<=0)
			wrongValues+="n";
		if (p<=0)
			wrongValues+="p";
		if (wrongValues.length() != 0)
			throw wrongValues;	
		std::cout<<"Generating small world network...\n";
		network = new SmallWorldNetwork(v,n,p);
		break;
	default:
		throw wrongValues+="t";		
	}
	switch (f) {
	case 1:
		network->save(d);
		break;
	case 2:
		network->show(d,'a');
		break;
	}
}catch (std::string e){
	std::cout<<"!!! Required value(s) not specified ("<<e[0];
	for (int i=1;e[i]!=0;++i)
		std::cout<<","<<e[i];	
	std::cout<<"). !!!\n";
	help();
	return 0;
}
std::cout<<"Network created, saved in file "<<d<<". Network is"<< (network->isCompact() ? "" : " not") <<" coherent.\n";
return 1;
}

void usage()
{
std::cout<<"Usage:\n./networkGenerator [OPTION] \nGenerate network corresponding to parameters:\n\nOptions:\n-a\tabout program\n-h\tdisplay help\n-d\tdestination file name\n-f\tdestination format:\n\t 1 - Flat file\n\t 2 - jpg\n-t\ttype of network: \n\t 1 - Euclidean Network \n\t 2 - Random Network\n\t 3 - Scale Free Network\n\t 4 - Small World Network\n\n";
std::cout<<"Mandatory Euclidean Network parameters:\n\t-v\tcount of verticles\n\t-s\tsize side squere in which network will be generate (default 1)\n\t-r\tradius, which edges will be generate\n";
std::cout<<"Mandatory Random Network parameters:\n\t-v\tcount of verticles\n\t-e\tcount of edges\n\t-p\tedge existing probability\n";
std::cout<<"Mandatory Scale Free Network parameters:\n\t-v\tcount of verticles\n";
std::cout<<"Mandatory Small World Network parameters:\n\t-v\tcount of verticles\n\t-n\tcount of neighbours at start\n\t-p\tedge change probability\n";
};

void about()
{
std::cout<<"Network generator (v."<<VERSION<<").\nProgram writted for GIS project, on summer semester 2014.\nProgrammers:\n\tMarcin Dzieżyc\n\tMateusz Statkiewicz\n\n";
}

void help()
{
std::cout<<"Try -h option for help.\n";
}

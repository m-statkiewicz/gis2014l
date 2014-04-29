all: clean networkGenerator

install:
	mkdir ../target
	mv *.o ../target
	mv networkGenerator ../target

clean:
	rm -Rf ../target
	rm -rf *.o networkGenerator

networkGenerator: main.o smallworldnetwork.o scalefreenetwork.o randomnetwork.o euclideannetwork.o network.o edge.o
	g++ main.o smallworldnetwork.o scalefreenetwork.o randomnetwork.o euclideannetwork.o network.o edge.o timer.o -o networkGenerator -lgvc -lcgraph

main.o: network.h smallworldnetwork.h scalefreenetwork.h randomnetwork.h euclideannetwork.h timer.h
	g++ -c main.cpp

smallworldnetwork.o: smallworldnetwork.cpp network.h 
	g++ -c smallworldnetwork.cpp 

scalefreenetwork.o: scalefreenetwork.cpp network.h
	g++ -c scalefreenetwork.cpp

euclideannetwork.o: euclideannetwork.cpp network.o
	g++ -c euclideannetwork.cpp -lm

randomnetwork.o: randomnetwork.cpp network.h
	g++ -c randomnetwork.cpp

network.o: network.cpp edge.h
	g++ -c network.cpp -fpermissive

edge.o: edge.cpp
	g++ -c edge.cpp

timer.o: timer.cpp
	g++ -c timer.cpp

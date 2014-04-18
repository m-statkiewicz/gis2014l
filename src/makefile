all: clean networkGenerator

clean:
	touch o.o
	rm *.o

networkGenerator: main.o smallworldnetwork.o scalefreenetwork.o randomnetwork.o euclideannetwork.o
	g++ main.o smallworldnetwork.o scalefreenetwork.o randomnetwork.o euclideannetwork.o -o networkGenerator
main.o: smallworldnetwork.h scalefreenetwork.h randomnetwork.h euclideannetwork.h
	g++ -c main.cpp
smallworldnetwork.o: smallworldnetwork.cpp network.h 
	g++ -c smallworldnetwork.cpp 
scalefreenetwork.o: scalefreenetwork.cpp network.h
	g++ -c scalefreenetwork.cpp
euclideannetwork.o: euclideannetwork.cpp network.h
	g++ -c euclideannetwork.cpp
randomnetwork.o: randomnetwork.cpp network.h
	g++ -c randomnetwork.cpp
network.o: network.cpp edge.h
	g++ -c network.cpp
edge.o: edge.cpp
	g++ -c edge.cpp

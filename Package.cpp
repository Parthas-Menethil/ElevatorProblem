#include "Package.h"
#include <cstdlib>

Package::Package(){
	weight = 0;
	destFloor = 0;
	loaded = false;
}
Package::Package(int maxFloor){
	this->weight = rand() % 10 + 1;
	this->destFloor = rand() % maxFloor + 1;
	this->loaded = false;
}

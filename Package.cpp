#include "Package.h"
#include <cstdlib>

Package::Package(int maxFloor){
	this->weight = rand() % 10 + 1;
	this->destFloor = rand() % maxFloor + 1;
}

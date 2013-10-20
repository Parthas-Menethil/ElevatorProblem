#include <vector>
#include "Package.h"
using namespace std;
class Elevator{
private:
	static float _totalTime;
	int floors;
	int curFloor;
	float capacity;  // Constat 10
	vector<Package> pkgs;
	int packages;
public:
	Elevator(int floors);
	static void resetTotalTime();
};

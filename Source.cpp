#include <iostream>
#include "Package.h"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void TopDownMergeSort(Package A[], Package B[], int n);
void TopDownSplitMerge(Package A[], int iBegin, int iEnd, Package B[]);
void TopDownMerge(Package A[], int iBegin, int iMiddle, int iEnd, Package B[]);
void TopDownMergeSort(Package A[], Package B[], int n){
	TopDownSplitMerge(A, 0, n, B);
}
void TopDownSplitMerge(Package A[], int iBegin, int iEnd, Package B[]){
	
}
void TopDownMerge(Package A[], int iBegin, int iMiddle, int iEnd, Package B[]){

}

int main(){
	srand(time(NULL));
	int maxFloor = 0, packNumber = 0;
	vector<Package> pkgs;
	cout << "Please enter the max floor: ";
	cin >> maxFloor;
	cout << "Please enter the package number: ";
	cin >> packNumber;
	for(int i = 0; i < packNumber; i++){
		pkgs.push_back(Package(maxFloor));
		cout << "Weight:" << pkgs[i].weight << "kg To:" << pkgs[i].destFloor << endl;
	}
	return 0;
}

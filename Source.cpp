#include <iostream>
#include "Package.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
void TopDownMergeSort(Package A[], Package B[], int n);
void TopDownSplitMerge(Package A[], int iBegin, int iEnd, Package B[]);
void TopDownMerge(Package A[], int iBegin, int iMiddle, int iEnd, Package B[]);
void TopDownMergeSort(Package A[], Package B[], int n){
	TopDownSplitMerge(A, 0, n, B);
}
void TopDownSplitMerge(Package A[], int iBegin, int iEnd, Package B[]){
	if (iEnd - iBegin < 2)
		return;
	int iMiddle = 0;
	iMiddle = (iBegin + iEnd) / 2;
	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iBegin, iEnd, B);
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
	copy(B, B + (iEnd - iBegin), A);
}
void TopDownMerge(Package A[], int iBegin, int iMiddle, int iEnd, Package B[]){
	int i0 = iBegin, i1 = iMiddle;
	
	for (int j = iBegin; j < iEnd; j++){
		if (i0 < iMiddle && (i1 >= iEnd || A[i0].weight <= A[i1].weight)){
			B[j] = A[i0++];
		}
		else{
			B[j] = A[i1++];
		}
	}
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
	Package p[10];
	TopDownMergeSort(pkgs.data(), p, 9);
	for (int i = 0; i < 10; i++)
		cout << "Weight: " << p[i].weight << "kg To:" << p[i].destFloor << endl;
	return 0;
}
